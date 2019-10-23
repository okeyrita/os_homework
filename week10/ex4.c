#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct NamesWithInode{
    ino_t number; 
    char *names;
    struct NamesWithInode *next;
}NamesWithInode;

int main(void)
{
    char *directory = "/home/margo/Рабочий стол/os week 10/tmp";
    size_t directory_length = strlen(directory);
    char *path = malloc(directory_length + 1 + NAME_MAX);
    strcpy(path, directory);
    path[directory_length] = '/';

    DIR *pDir = opendir(directory);
    struct dirent *pDirent;
    struct stat vStat; 

    if (pDir == NULL)
    {
        printf("Can't open the directory");
        return 1;
    }
    
    NamesWithInode *names = NULL;
    while ((pDirent = readdir(pDir)) != NULL)
    {
        strcpy(path + directory_length + 1, pDirent->d_name);
        if (stat(path, &vStat) == -1) {
            printf("Can't use stat.");
            return 1;
        }
        if (vStat.st_nlink >= 2) {
            if (names == NULL){
                names = malloc(sizeof(NamesWithInode));
                names->next = NULL;
                names->number = vStat.st_ino;
                names->names = malloc(strlen(pDirent->d_name));
                strcpy(names->names,pDirent->d_name);
                continue; 
            }
            NamesWithInode *current = names;
            do{
                if(current->number == vStat.st_ino){
                    char* last_names = malloc(strlen(current->names));
                    strcpy(last_names,current->names);
                    current->names = malloc(strlen(last_names)+strlen(pDirent->d_name)+1);
                    strcpy(current->names,last_names);
                    current->names[strlen(current->names)] = ' ';
                    strcat(current -> names , pDirent->d_name);
                    break;
                }
                if (current->next == NULL){
                    current->next = malloc(sizeof(NamesWithInode));
                    current->next->next = NULL;
                    current->next->number = vStat.st_ino;
                    current->next->names = malloc(strlen(pDirent->d_name));
                    strcpy(current->next->names,pDirent->d_name);
                    break;
                }
                current = current->next; 
            }while(1);
            
        }
    }

    NamesWithInode *current = names;
    while(current != NULL){
        printf("%ld %s\n",current->number, current->names);
        current = current->next;
    }
    closedir(pDir);
    return 0;
}

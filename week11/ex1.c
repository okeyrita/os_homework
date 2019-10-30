#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>


int main(){

    int fileOpen;
    struct stat fileStat;
    

    if (stat("ex1.txt", &fileStat) < 0){
        perror("File cannot get stat ");
        return ENOENT;
    }
    if ((fileOpen = open("ex1.txt", O_RDWR)) < 0){
        perror("File cannot be opened");
        return ENOENT;
    } 

    size_t fileSize = (size_t)fileStat.st_size;
    char* text = "This is a nice day";
    if (fileSize < strlen(text)){
        fileSize = strlen(text);
    }

    char* map;
    map = (char*)(long)(mmap(0, fileSize, PROT_READ| PROT_WRITE, MAP_SHARED, fileOpen, 0));
    if(map == MAP_FAILED){
        perror("The file cannot be mapped");
        return EBADF;
    }

    memset(map, ' ', fileSize);
    strcpy(map, text);
    map[strlen(text)] = ' ';

    munmap(map, fileSize);

    return 0;
}

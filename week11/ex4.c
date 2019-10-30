#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include <errno.h>
#include<sys/mman.h>
#include<string.h>

int main(int argc, char **argv){
    int sfd, dfd;
    char *src, *dest;
    size_t filesize;

    sfd = open("ex1.txt", O_RDONLY);
    filesize = lseek(sfd, 0, SEEK_END);
    src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, sfd, 0);

    dfd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(dfd, filesize);
    dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);

    memcpy(dest, src, filesize);

    munmap(src, filesize);
    munmap(dest, filesize);

    close(sfd);
    close(dfd);

    return 0;
}

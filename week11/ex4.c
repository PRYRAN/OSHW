#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("ex1.txt", O_RDWR, 0);
    int fd2 = open("ex1.memcpy.txt", O_RDWR, 0);
    struct stat st;
    fstat(fd1, &st);
    size_t fsize = (size_t)st.st_size;
    ftruncate(fd2, fsize);
    char* dataPtr1 = mmap(0, fsize, PROT_WRITE, MAP_SHARED, fd1, 0);
    char* dataPtr2 = mmap(0, fsize, PROT_WRITE, MAP_SHARED, fd2, 0);
    memcpy(dataPtr2 ,dataPtr1, fsize);
    close(fd1);
    close(fd2);

    return 0;
}
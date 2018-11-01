#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd = open("ex1.txt", O_RDWR, 0);
    const char *text = "This is a nice day";
    struct stat st;
    fstat(fd, &st);
    size_t fsize = (size_t)st.st_size;
    lseek(fd, fsize-1, SEEK_SET);
    char* dataPtr = mmap(0, fsize, PROT_WRITE, MAP_SHARED, fd, 0);
    ftruncate(fd, fsize);
    memcpy(dataPtr, text, strlen(text));
    msync(dataPtr, fsize, MS_SYNC);
    munmap(dataPtr, fsize);
    close(fd);

    return 0;
}

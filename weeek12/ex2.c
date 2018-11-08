#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define N 500

int main(int argc, char *argv[]){
    char *buff = (char *)malloc(sizeof(char) * N);

    int count;
    int *files;
    if (argc > 1 && strcmp("-a", argv[1]))
    {
        count = argc - 2;
        files = (int *)malloc(sizeof(int) * count);
        for (int i = 0; i < count; i++){
                files[i] = open(argv[i + 2], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);

        }

    }
    else
    {
        count = argc - 1;
        files = (int *)malloc(sizeof(int) * count);
        for (int i = 0; i < count; i++){
                files[i] = open(argv[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        }
    }
    read(0, buff, N);
    printf("%s", buff);

    for (int i = 0; i < count; i++){
        for (int j = 0; j < N; j++){
            if (buff[j] == '\0')
                break;
            write(files[i], (buff + j), 1);
        }
        close(files[i]);
    }





    return 0;
}
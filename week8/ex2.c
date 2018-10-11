#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int *arr;
    for (int i=0; i<10; i++){
        arr = malloc(1024 * 1024);
        memset(arr, 0, 1024 * 256);
        sleep(1);
    }
    return 0;
}
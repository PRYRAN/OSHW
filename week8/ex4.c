#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    struct rusage us;
    int *arr;
    for (int i=0; i<10; i++){
        arr = malloc(1024 * 1024);
        memset(arr, 0, 1024 * 256);
        getrusage(RUSAGE_SELF, &us);
        printf("%ld ", us.ru_maxrss);
        sleep(1);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main() {
    char* temp = (char*)malloc(sizeof(char) * 20);
    FILE *fp = fopen("/dev/random", "r");
    FILE *output = fopen("ex1.txt", "w+");
    fread(temp, 1, 20, fp);
    fprintf(output,"%s",temp);
}

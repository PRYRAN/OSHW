#include <stdio.h>
#include <stdlib.h>
 
 
int main(){
	char temp = malloc(sizeof(char));
    char *p = &temp;
    char **s = &p;
    char foo[] = "Hello World";
 
    *s = foo;
    printf("s is %p\n", s);
    s[0] = foo;
    printf("s[0] is %p\n", s[0]);
 
    return 0;
}

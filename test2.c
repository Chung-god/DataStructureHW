#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(void) {
    char *a = (char *)malloc(100);
    memset(a, 0, 100);
    
    strcpy(a, "Hello World!");
    printf("%s\n", a);
    free(a);
    
    char *b = (char *)malloc(100); 
    strcpy(b, "Hello Pwnable!");
    printf("%s\n", b);
    
    strcpy(a, "Hello World!");
    printf("%s\n", b);
    
}
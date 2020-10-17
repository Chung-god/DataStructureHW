#include <stdio.h>

int main(){
    int a,b,c,d = 0;
    char str[] = "string";
    char str2[] = "st\x00ring";
    printf("1.");
    printf("hello keeper!!%n\n",&a);
    printf("2.");
    printf("str:%s%n\n",str, &b);
    printf("3.");
    printf("%100c%n\n", 'x', &c);
    printf("4.");
    printf("str: %s\n", str2);

    printf("\na: %d b: %d c: %d str : %s",a,b,c,str2);
}
#include <stdio.h>

int main(){
    int a,b,c = 0;
    char str[] = "string";
    char str2[] = "st\x00ring";
   
    //a,b,c�� str2 ��� ���� �����غ���!
    printf("hello Keeper!%n\n",&a);
    printf("str:%s%n\n",str, &b);
    printf("%100c%n\n", 'x', &c);
    printf("str: %s\n", str2);

}
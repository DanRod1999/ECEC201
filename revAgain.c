#include<stdio.h>
#include<string.h>

int main(){

    char input[20];

    printf("enter string: ");
    // scanf("%c",input);
    fgets(input,20,stdin);
    printf("%s\n",input);

}

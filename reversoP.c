#include<stdio.h>
#include<string.h>

int main(){

    char input[20],letter=NULL;

    printf("type here: ");
    // letter = getchar();
    
    int i = 0;
    while(letter != '\n' && letter != EOF){
        letter = getchar();
        // scanf(" %1c",input);
        input[i] = letter;
        i++;
    }

    printf("%s\n",input);
    int len = strlen(input);
    for(int i = 0; i <= len; i++){
        printf("%c",*(input + len - i));
    }
    printf("\n");
}
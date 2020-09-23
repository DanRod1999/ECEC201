#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 20
#define MAX_WORD 80

int read_line(char str[], int n){

    int ch, i = 0;

    while (ch = getchar() != '\n'){
        if(i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;   
}

int main(void){

    int i = 0;
    char word[MAX_LEN+1];
    char *words[MAX_WORD];
    int num_word = 0;

    for(;;){
        if(num_word == MAX_WORD){
            printf("To many word");
            break;
        }

        printf("enter word: ");
        read_line(word,MAX_LEN);
        
        if(word[0] == '\0'){
            printf("No space\n");
            break;
        }
        
        words[i] = malloc(strlen(word));
        strcpy(words[i],word);



        num_word++;
        i++;   
    }

    for(int i = 0; i < num_word; i++){
        printf("%s\n", words[i]);
    }

    return 0;

}
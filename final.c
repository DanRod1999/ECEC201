#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STR 20

typedef struct _LLNODE {
   char first_name[MAX_STR],last_name[MAX_STR],party[MAX_STR],state[MAX_STR];
   struct _LLNODE * pNext;
} LLNODE, *PLLNODE;

void write_list(){
    char first_name[MAX_STR],last_name[MAX_STR],party[1],state[2];
    
    FILE *fp;
    fp = fopen("senate_116_trim.json", "r");

    if (fopen("senate_116_trim.json", "r") == NULL){
        printf("File does not exist\n");
        exit(EXIT_FAILURE);
    }

    int i=0;
    while(i<64){
        if (i%4 == 0){
            fgets(first_name,MAX_STR,fp);
            fgets(last_name,MAX_STR,fp);
            fgets(party,MAX_STR,fp);
            fgets(state,MAX_STR,fp);
        }
        // else if(i%4 == 1){
        //     fgets(last_name,MAX_STR,fp);
        // }
        // else if(i%4 == 2){
        //     fgets(party,MAX_STR,fp);
        // }
        // else if(i%4 == 3){
        //     fgets(state,MAX_STR,fp);
        // }
        i = i +4;;
        printf("%s, %s, %s(%s)\n", last_name,first_name,state,party);
    }
    // printf("%s\n",first_name);
}

PLLNODE addNodeToList(PLLNODE head,PLLNODE pNode){
   PLLNODE pInsertBefore=head, pInsertAfter=NULL;
   if (NULL == head){
       return pNode;
   }
   while(NULL != pInsertBefore && strcmp(pInsertBefore->last_name, pNode->last_name) < 0){
       pInsertAfter=pInsertBefore;
       pInsertBefore=pInsertBefore->pNext;
   //insert pNode before head
   }
   pNode->pNext=pInsertBefore;
   if (NULL==pInsertAfter){
       head=pNode;
   }
   else{
       pInsertAfter->pNext=pNode;
   }
   //head=pNode;
   return head;
}

void printList(PLLNODE head){
   PLLNODE pNode=head;
   while(NULL != pNode){
       printf("%s, %s, %s(%s)", pNode->last_name, pNode->first_name, pNode->state, pNode->party);
       if (NULL != pNode->pNext){
           printf("\n");
       }
       pNode = pNode->pNext;
   }
   printf("\n");
}

void printPA(PLLNODE head){
   PLLNODE pNode=head;
   while(NULL != pNode){
        if(strcmp(pNode -> state,"pa")==0)
            printf("%s, %s, %s(%s)", pNode->last_name, pNode->first_name, pNode->state, pNode->party);
        if (NULL != pNode->pNext){
           printf("\n");
       }
       pNode = pNode->pNext;
   }
   printf("\n");
}

int main(){
    write_list();

    
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _LLNODE {
    double dRandom01;
    struct _LLNODE * pNext;
    struct _LLNODE * pPrevious;
} LLNODE, *PLLNODE;

#define NUMBER_OF_NODES 5

PLLNODE generateRandomNode(){
    PLLNODE pNode;
    pNode = malloc(sizeof(LLNODE));
   
    if (NULL == pNode){
        printf("ERROR ! OUT OF MEMORY! OH NO!");
        return NULL;
    }

    pNode -> dRandom01=(double)random()/RAND_MAX;
    pNode -> pNext = NULL;
    pNode -> pPrevious = NULL;
    return pNode;
} //generateRandomNode

void addNodeToList(PLLNODE *head,PLLNODE pNode, PLLNODE *tail){
//Make head a Pointer to pointer in order to change head without returning it
    PLLNODE pInsertBefore=*head, pInsertAfter=NULL;
    if (NULL == *head){
        *head = pNode; //style??
    }

    while(NULL != pInsertBefore && (pInsertBefore)->dRandom01 < pNode->dRandom01){
        pInsertAfter=pInsertBefore;
        pInsertBefore=(pInsertBefore)->pNext;
    //insert pNode before head
    }

    pNode->pNext=pInsertBefore; //assign pNode's pNext value
    pNode->pPrevious=pInsertAfter; //assign pNode's pPrevious value
    if (NULL==pInsertAfter){
        *head=pNode;
    }
    else{
        pInsertAfter->pNext=pNode;
    }

    if (NULL==pInsertBefore){
        *tail=pNode;
    }
    else{
        pInsertBefore->pPrevious=pNode;
    }//if pNode is last element set it to tail else set pNode to pInsertBefore's pPrevious
}

void printList(PLLNODE head){

    FILE *fp;
    fp = fopen("llForward.txt", "wb");

    if (fopen("llForward.txt", "r") == NULL){
        printf("File does not exist\n");
        exit(EXIT_FAILURE);
    }

    PLLNODE pNode=head;
    while(NULL != pNode){
        fprintf(fp,"%0.2f", pNode->dRandom01);
        if (NULL != pNode->pNext){
            fprintf(fp,",");
        }
        pNode = pNode->pNext;
    }
    printf("\n");
    fclose(fp);
}

void printListRev(PLLNODE tail){

    FILE *fp;
    fp = fopen("llReverse.txt", "wb");

    if (fopen("llReverse.txt", "r") == NULL){
        printf("File does not exist\n");
        exit(EXIT_FAILURE);
    }

    PLLNODE pNode=tail;
    while(NULL != pNode){
        fprintf(fp,"%0.2f", pNode->dRandom01);
        if (NULL != pNode->pPrevious){
            fprintf(fp,",");
        }
        pNode = pNode->pPrevious;
    }
    printf("\n");
}

void freeNodes(PLLNODE head){
    PLLNODE pNode=head;
    while(NULL != pNode){
        free(pNode);
        pNode = pNode->pNext;
    }
}

int main(int argc, char * argv[]){
    PLLNODE head, pNode, tail;
    head = NULL;
    pNode = NULL;
    tail = NULL;

    for (int i = 0; i < NUMBER_OF_NODES; i++){
        // add a random node
        pNode=generateRandomNode();
        addNodeToList(&head, pNode,&tail);
    }
    printList(head);
    printListRev(tail);
    freeNodes(head);
}
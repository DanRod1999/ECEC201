#include <stdio.h>
#include <stdlib.h>
typedef struct _LLNODE {
   double dRandom01;
   struct _LLNODE * pNext;
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
   return pNode;
} //generateRandomNode
PLLNODE addNodeToList(PLLNODE head,PLLNODE pNode){
   PLLNODE pInsertBefore=head, pInsertAfter=NULL;
   if (NULL == head){
       //tree
       //head=pNode;
       return pNode; //style??
   }
   while(NULL != pInsertBefore && pInsertBefore->dRandom01 < pNode->dRandom01){
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
       printf("%0.2f", pNode->dRandom01);
       if (NULL != pNode->pNext){
           printf(",");
       }
       pNode = pNode->pNext;
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
   PLLNODE head=NULL, pNode=NULL;//set head and pNode to null
   for (int i = 0; i < NUMBER_OF_NODES; i++){
       // add a random node
       pNode=generateRandomNode() ;
       head = addNodeToList(head, pNode);
   }
   printList(head);
   freeNodes(head);
   printList(head);
}
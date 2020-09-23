#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_NODES 9
#define FILE_NAME "binaryTree.txt"

typedef struct _BTN {
    int nodeID,leftChildID,rightChildID;

    struct _BTN *btParent,*btLeftChild,*btRightChild;
} BinaryTreeNode;

void readTree(char input[15], int bt_vals[]){
    char ch = "";
    FILE *fp;
    fp = fopen(FILE_NAME, "r");

    for (int i = 0; i<NUM_NODES*3; i++){
        ch = fgetc(fp); //grabs char then moves pointer one
        if(!isdigit(ch)){
            bt_vals[i] = -1; //if ch is not a digit set bt_vals to -1 then move pointer
            fgetc(fp);
        }else{
            bt_vals[i] = ch - '0'; //else set bt_vals to int version of ch
        }
        fgetc(fp); //move pointer one in order to avoid comma
    }
    fclose(fp);
}

void InitNode(int bt_vals[], BinaryTreeNode bt[]){

    int array_count = 0;
    for(int i = 0; i < NUM_NODES; i++){

        bt[i].nodeID = bt_vals[array_count];
        bt[i].leftChildID = bt_vals[array_count + 1];
        bt[i].rightChildID = bt_vals[array_count + 2];
        array_count = array_count + 3;
        // printf("%d -> %d, %d\n",bt[i].nodeID, bt[i].leftChildID, bt[i].rightChildID);
    }
}

int setPointer(BinaryTreeNode bt[]){
    for(int i = 0; i < NUM_NODES; i++){
        for(int j = 0; j < NUM_NODES; j++){
            if(bt[i].nodeID == bt[j].leftChildID){
                bt[i].btParent = &bt[j];//if node id matches left ID set pointer of parent to address 
                                        //of that element
                // bt[j].btRightChild = &bt[i].rightChildID;
                //thought this was how pointers worked but was wrong
            }
            else if(bt[i].nodeID == bt[j].rightChildID){
                bt[i].btParent = &bt[j];//if node id matches rightchild ID set pointer of parent to address
                                        //of that element
                // bt[j].btLeftChild = &bt[i].leftChildID;
            }
        }
    }
    return bt[0].nodeID;//return root node
}

void printTreeArray(BinaryTreeNode bt[]){
    for(int i = 0; i < NUM_NODES; i++){
        if(bt[i].btParent == NULL){
            //if there is no parent pointer print *
            printf("(*) -> %d: %d, %d\n",bt[i].nodeID,bt[i].leftChildID,bt[i].rightChildID);
        }else{
            //else print previous node id for parent then current Id's for the rest
            printf("(+%d) -> %d: %d, %d\n",bt[i-1].nodeID,bt[i].nodeID,bt[i].leftChildID,bt[i].rightChildID);
        }
    }
}

void printTreeDFS(BinaryTreeNode *bt_pointer){
    if(bt_pointer == NULL){
        return;
    }else{
        printf("(%p)-> %d: %d, %d",bt_pointer->btParent,bt_pointer->nodeID,bt_pointer->leftChildID,bt_pointer->rightChildID);
        printTreeDFS(bt_pointer->btLeftChild); //these are pointers pointing 
        printTreeDFS(bt_pointer->btRightChild);//to pointers -segmentation fault
    }
}


int main(int argc, char ** argv){

    int bt_vals[(NUM_NODES*3)];

    BinaryTreeNode bt[NUM_NODES];

    readTree(FILE_NAME,bt_vals);

    InitNode(bt_vals, bt);

    printf("Print root node: %d\n",setPointer(bt));

    printTreeArray(bt);
    printf("%p\n", bt[0].btParent);

    printTreeDFS(bt[0].btParent);

    return 0;
}
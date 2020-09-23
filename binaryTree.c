#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_NODES 9

typedef struct {
    int nodeID,leftChildID,rightChildID;

    int idxParent,idxLeftChild,idxRightChild;
} BinaryTreeNode;
BinaryTreeNode bt[NUM_NODES];

int main(int argc, char ** argv){

    FILE *fp;
    char ch = "";
    int bt_vals[(NUM_NODES*3)];
    
    fp = fopen(argv[1], "r");
    if(fp == NULL){                                 //if file does not exist quit
        printf("file %s cannot be open\n",argv[1]);
        exit(EXIT_FAILURE);
    }


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

    for(int i = 0; i < NUM_NODES; i++){
        bt[i].nodeID = -1;
        bt[i].idxLeftChild = -1;
        bt[i].idxRightChild = -1;
        // printf("node %d: %d\n",i+1,bt[i].nodeID);
    }

    int array_count = 0;
    for(int i = 0; i < NUM_NODES; i++){

        bt[i].nodeID = bt_vals[array_count];
        bt[i].leftChildID = bt_vals[array_count + 1];
        bt[i].rightChildID = bt_vals[array_count + 2];
        array_count = array_count + 3;
        // printf("%d -> %d, %d\n",bt[i].nodeID, bt[i].leftChildID, bt[i].rightChildID);
    }

    int count = 0;
    for(int i = 0; i<NUM_NODES; i++){
        if(bt[i].leftChildID != -1){
            bt[i].idxLeftChild = (2*count) + 1;
            bt[i].idxRightChild = (2*count) + 2;
            count++;
        }else{
            bt[i].idxLeftChild = -1;
            bt[i].idxRightChild = -1;
        }
        printf("%d(%d) -> %d(%d), %d(%d)\n",bt[i].nodeID,i, bt[i].leftChildID, bt[i].idxLeftChild, bt[i].rightChildID,bt[i].idxRightChild);
    }

}
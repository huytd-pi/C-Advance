#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* nextNode;
} *Vector;

Vector createNode(int value){
    Vector newNode = (Vector) malloc(sizeof(Vector));
    newNode->data = value;
    newNode->nextNode = NULL;
    return newNode;
}

void freeNode(Vector node){
    Vector tempNode;
    while (node != NULL){
        tempNode = node;
        node = node->nextNode;
        free(tempNode);
    }
}

Vector push_back(Vector newNode,int value){
    Vector tempNode = createNode(value);
    if(newNode == NULL) newNode = tempNode;
    else{
        Vector curentNode = newNode;
        if (curentNode->nextNode != NULL) curentNode = push_back(curentNode->nextNode,value);
        else curentNode->nextNode = tempNode;
    }
    return newNode;
}

Vector push_top(Vector newNode,int value){
    Vector tempNode = createNode(value);
    tempNode->data = value;
    tempNode->nextNode = newNode;
    newNode = tempNode;
    return newNode;
}

Vector pop_back(Vector newNode){
    Vector tempNode = newNode;
    while (tempNode->nextNode->nextNode != NULL)
    {
        tempNode = tempNode->nextNode;
    }
    tempNode->nextNode = NULL;
    return tempNode;
}

int lenghtNode(Vector node){
    int count = 0;
    Vector tempNode = node;
    while (tempNode != NULL){
        count++;
        tempNode = tempNode->nextNode;
    }
    return count;
}

Vector assign(Vector newNode,int value){
    Vector tempNode = newNode;
    while (tempNode != NULL)
    {
        tempNode->data = value;
        tempNode = tempNode->nextNode;
    }
    return tempNode;
    
}

Vector insert(Vector newNode,int index, int value){
    Vector tempNode = newNode;
    Vector tempNode1 = createNode(value);
    if(index == 0){
        newNode = push_top(newNode,value);
    } else if(index == lenghtNode(newNode)){
        newNode = push_back(newNode,value);
    } else{
        int count = 0;
        while (count != index-2){
            tempNode = tempNode->nextNode;
            count++;
        }
        tempNode1->nextNode = tempNode->nextNode;
        tempNode->nextNode = tempNode1;
    }
    return newNode;
}

void printVector(Vector node){
    while (node)
    {
        printf("%d\t",node->data);
        node = node->nextNode;
    }
    printf("\n");
}


int main(int argc, char* argv[]){
    Vector vector = NULL;
    vector = push_back(vector,1);
    vector = push_back(vector,0);
    vector = push_back(vector,6);
    vector = push_back(vector,8);
    printVector(vector);

    // insert in any position
    vector = insert(vector,3,88);
    vector = insert(vector,lenghtNode(vector),10);
    vector = insert(vector,0,11);
    vector = insert(vector,3,99);
    printVector(vector);


    assign(vector,10);
    printVector(vector);


    pop_back(vector);
    pop_back(vector);

    printVector(vector);

    return 0;
}
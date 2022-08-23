#include<stdio.h>
#include<stdlib.h>

typedef struct Vector{
    int data;
    struct Vector* nextNode;
} Node;

Node* createNode(int value){
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->nextNode = NULL;
    return newNode;
}

void freeNode(Node* node){
    Node *tempNode;
    while (node != NULL){
        tempNode = node;
        node = node->nextNode;
        free(tempNode);
    }
}

Node* push_back(Node *newNode,int value){
    Node* tempNode = createNode(value);
    if(newNode == NULL) newNode = tempNode;
    else{
        Node *curentNode = newNode;
        if (curentNode->nextNode != NULL) curentNode = push_back(curentNode->nextNode,value);
        else curentNode->nextNode = tempNode;
    }
    return newNode;
}

Node* push_top(Node* newNode,int value){
    Node* tempNode = createNode(value);
    tempNode->data = value;
    tempNode->nextNode = newNode;
    newNode = tempNode;
    return newNode;
}

Node* pop_back(Node* newNode){
    Node* tempNode = newNode;
    while (tempNode->nextNode->nextNode != NULL)
    {
        tempNode = tempNode->nextNode;
    }
    tempNode->nextNode = NULL;
    return tempNode;
}

int lenghtNode(Node* node){
    int count = 0;
    Node* tempNode = node;
    while (tempNode != NULL){
        count++;
        tempNode = tempNode->nextNode;
    }
    return count;
}

Node* assign(Node* newNode,int value){
    Node* tempNode = newNode;
    while (tempNode != NULL)
    {
        tempNode->data = value;
        tempNode = tempNode->nextNode;
    }
    return tempNode;
    
}

Node* insert(Node* newNode,int index, int value){
    Node* tempNode = newNode;
    Node* tempNode1 = createNode(value);
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

void printListNode(Node* node){
    while (node)
    {
        printf("%d\t",node->data);
        node = node->nextNode;
    }
    printf("\n");
}


int main(int argc, char* argv[]){
    Node* newNode = NULL;
    newNode = push_back(newNode,1);
    newNode = push_back(newNode,0);
    newNode = push_back(newNode,6);
    newNode = push_back(newNode,8);
    printListNode(newNode);

    // insert in any position
    newNode = insert(newNode,3,88);
    newNode = insert(newNode,lenghtNode(newNode),10);
    newNode = insert(newNode,0,11);
    newNode = insert(newNode,3,99);
    printListNode(newNode);


    assign(newNode,10);
    printListNode(newNode);


    pop_back(newNode);
    pop_back(newNode);

    printListNode(newNode);

    return 0;
}
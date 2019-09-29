/*This program demonstrate level traverse of binary tree
Written by : seongjin.kim
Date : 2019.09.10
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX 100

using namespace std;

typedef struct _NODE{
    char data;
    struct _NODE* left;
    struct _NODE* right;
}NODE;

NODE* head;
NODE* leaf;
NODE* QUEUE[MAX];
int front, rear;


//Function Declarations
void initQueue(void);
void enqueue(NODE* node);
NODE* dequeue();
bool isQueueEmpty();

void makeChild(NODE* parent, char left, char right);
void makeTree(void);
void initTree(void);


void visit(NODE* node);
void levelTraverse(NODE* visitor);

int main(void){
    initQueue();
    initTree();
    makeTree();
    levelTraverse(head->left);
    cout << " end " <<endl;
}



void initQueue(void){
    front = rear = 0;
}

void enqueue(NODE* node){
    QUEUE[rear] = node;
    rear = (rear+1) % MAX;
}

NODE* dequeue(){
    NODE* first = NULL;
    if(!isQueueEmpty()){
        first = QUEUE[front];
        front = (front+1) % MAX;
    }else{
        printf("Queue is empty");
    }
    return first;
}

bool isQueueEmpty(){
    if (front ==  rear){
        return true;
    }else{
        return false;
    }
}

void initTree(void){
    head = (NODE*)malloc(sizeof(NODE));
    leaf = (NODE*)malloc(sizeof(NODE));
    head->left = leaf;
    head->right = leaf;
    leaf->left = leaf;
    leaf->right = leaf;
}

void makeTree(void){
    NODE* parent = (NODE*)malloc(sizeof(NODE));
    parent->data = 'A';
    
    head->left = parent;
    head->right = parent;
    
    makeChild(parent, 'B', 'C');
    parent = parent->left;
    makeChild(parent, 'D', 'E');
    parent = head->right->right;
    makeChild(parent, 'F', 'G');
}


void makeChild(NODE* parent, char left, char right){
    NODE* leftChild = (NODE*)malloc(sizeof(NODE));
    leftChild->data = left;
    leftChild->left = leaf;
    leftChild->right = leaf;
    
    NODE* rightChild = (NODE*)malloc(sizeof(NODE));
    rightChild->data = right;
    rightChild->left = leaf;
    rightChild->right = leaf;
    
    parent->left = leftChild;
    parent->right = rightChild;
    
}


void levelTraverse(NODE* visitor){
    enqueue(visitor);
    while(!isQueueEmpty()){
        visitor = dequeue();
        visit(visitor);
        
        if(visitor->left != leaf){
            enqueue(visitor->left);
        }
        
        if(visitor->right != leaf){
            enqueue(visitor->right);
        }
        
    }
}

void visit(NODE* node){
    printf("%2c -> ", node->data);
}

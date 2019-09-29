//
//  main.cpp
//  binaryTree
//
//  Created by Kim Seong Jin on 2019. 9. 9..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define MAX 100

using namespace std;

typedef struct _NODE{
    char data;
    struct _NODE* left;
    struct _NODE* right;
}NODE;


//function declarations
void initStack(void);
bool isStackEmpty(void);
void push(NODE* ptrNode);
NODE* pop(void);
void printStack();

void makeChild(NODE* parent, char left, char right);
void makeTree(void);
void initTree(void);
void visit(NODE* node);
void preOrderTraverse(NODE* node);
void midOrderTraverseStack(NODE* node);
void midOrderTraverseRecursive(NODE* visitor);
void postOrderTraverseStack(NODE* visitor);

//Global Variables
NODE* stack[MAX];
int top;
NODE* head;
NODE* leaf;

int main(void) {
    initStack();
    initTree();
    makeTree();
    
    /*
    printf("preOrder\n");
    preOrderTraverse(head->left);
    printf(" end \n");
    
    printf("midOrder(Stack)\n");
    initStack();
    midOrderTraverseStack(head->left);
    printf(" end \n");
    
    printf("midOrder(Recursion)\n");
    initStack();
    midOrderTraverseRecursive(head -> left);
    printf(" end \n");
    */
    
    printf("postOrder(Recursion)\n");
    initStack();
    postOrderTraverseStack(head->left);
    printStack();
    //printf(" end \n");

    
    
    
    
    return 0;
}

void initStack(void){
    top = 0 ;
}

void push(NODE* ptrNode){
    stack[top] = ptrNode;
    top = (top+1) % MAX;
    
}

NODE* pop(void){
    NODE* ptrNode;
    if(!isStackEmpty()){
        ptrNode = stack[--top];
        return ptrNode;
    }
    return NULL;
}

bool isStackEmpty(void){
    if (top==0){
        return true;
    }else{
        return false;
    }
}

void printStack(){
    for(int idx = 0 ; idx < 7 ; idx++){
        printf("%2c ", stack[idx]->data);
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

void visit(NODE* node){
    printf("%2c ->", node->data);
}

void preOrderTraverse(NODE* node){
    push(node);
    while(!isStackEmpty()){
        node = pop();
        visit(node);
        
        if(node->right != leaf){
            push(node->right);
        }
        if(node->left != leaf){
            push(node->left);
        }
    }
}

void midOrderTraverseStack(NODE* visitor){
    bool finish = false;
    
    do{
        while(visitor!= leaf){
            push(visitor);
            visitor = visitor->left;
        }
        if(!isStackEmpty()){
            visitor = pop();
            visit(visitor);
            visitor = visitor->right;
        }else{
            finish = true;
        }
    }while(!finish);
}

void midOrderTraverseRecursive(NODE* visitor){
    if(visitor == leaf){
        return;
    }
    midOrderTraverseStack(visitor->left);
    printf("%2c ->", visitor->data);
    midOrderTraverseStack(visitor->right);
    
}

void postOrderTraverseStack(NODE* visitor){
    bool finished = false;
    NODE* visited = leaf;
    NODE* pushed = leaf;
    while(visitor != leaf && visitor != visited ){
        if(visitor != pushed)
            push(visitor);
        
        if(visitor->right != leaf)
            push(visitor->right);
        
        if(visitor->left != leaf)
            push(visitor->left);
        
        pushed = visitor;
        visitor = visitor->left;
    }
}




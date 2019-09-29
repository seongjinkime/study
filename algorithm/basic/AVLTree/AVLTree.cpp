//
//This Program implements AVL tree
//  main.cpp
//  AVLTree
//
//  Created by Kim Seong Jin on 2019. 9. 11..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct _NODE{
    int data;
    int height;
    struct _NODE* left;
    struct _NODE* right;
}NODE;


int height(NODE* node);
NODE* singleRotateLeft(NODE* parent);
NODE* singleRotateRight(NODE* parent);
NODE* doubleRotateLeftRight(NODE* parent);
NODE* doubleRotateRightLeft(NODE* parent);
NODE* insert(NODE* node, NODE* parent, int dataIn);
void midOrderTraverse(NODE* node);

int main(int argc, const char * argv[]) {
    NODE* AVL = NULL;
    AVL = insert(AVL, AVL, 4);
    AVL = insert(AVL, AVL, 2);
    AVL = insert(AVL, AVL, 7);
    AVL = insert(AVL, AVL, 6);
    AVL = insert(AVL, AVL, 8);
    AVL = insert(AVL, AVL, 5);
    midOrderTraverse(AVL);
    return 0;
}

int height(NODE* node){
    if(!node){
        return -1;
    }else{
        return node->height;
    }
}


NODE* singleRotateLeft(NODE* parent){ //왼쪽이 무거움
    NODE* child = parent->left;
    parent->left = child->right; //자식보다 크고 부모보다 작은 수룰 부모의 왼쪽에 놓는다
    child->right = parent; //자식의 자식으로 부모들 하강 시킨다
    
    parent->height = max(height(parent->left), height(parent->right)) + 1;
    child->height = max(height(child->right), parent->height) + 1;
    
    return child;
}

NODE* singleRotateRight(NODE* parent){ //오른쪽이 무거움
    NODE* child = parent->right;
    parent->right = child->left; //부모보다 크고 자식보다 작은 수를 부모의 오른쪽에 놓는다
    child->left = parent; //자식의 왼쪽으로 부모를 하강 시킨다
    
    parent->height = max(height(parent->left), height(parent->right)) + 1;
    child->height = max(height(child->right), parent->height) + 1;
    
    return child;
}

NODE* doubleRotateLeftRight(NODE* parent){ //상위엔 레프트, 하위엔 라이트 => 라이트 먼저 -> 레프트 왼쪽이 무거움
    parent->left = singleRotateRight(parent->left); //왼쪽의 균형 맞춤
    return singleRotateLeft(parent);
}


NODE* doubleRotateRightLeft(NODE* parent){ //상위엔 라이트, 하위엔 레프트 => 레프트 먼저 -> 라이트 오른쪽이 무거움
    parent->right = singleRotateLeft(parent->right);
    return singleRotateRight(parent);
}

NODE* insert(NODE* node, NODE* parent, int dataIn){
    int nodeData;
    int childData;
    if(!node){
        node = (NODE*)malloc(sizeof(NODE));
        if(!node){
            printf("Memory error!");
            exit(101);
        }else{
            node->data = dataIn;
            node->height = 0;
            node->left = node -> right = NULL;
        }
    }//if node is null
    
    nodeData = node->data;
    
    if(dataIn < nodeData){
        node->left = insert(node->left, node, dataIn); //이진 트리 생성
        if(height(node->left) - height(node->right) >= 2){ //왼쪽이 무거울 경우
            childData = node->left->data;
            if(dataIn < childData)
                node = singleRotateLeft(node); //왼쪽으로 치우쳐져 있을 경우
            else
                node = doubleRotateLeftRight(node);
        }
        
    }else if(dataIn > nodeData){
        node->right = insert(node->right, node, dataIn); //이진 트리 생성
        if(height(node->right) - height(node->left) == 2){ //오른쪽이 무거울 경우
            childData = node->right->data;
            if(dataIn > childData) //오른쪽으로 치우쳐져 있을 경우
                node = singleRotateRight(node);
            else
                node = doubleRotateRightLeft(node);
        }
        
        
    }
    
    node->height = max(height(node->left), height(node -> right)) + 1;
    
    return node;
}

void midOrderTraverse(NODE* node){
    if(!node)
        return;
    
    midOrderTraverse(node->left);
    printf("%2d ", node->data);
    midOrderTraverse(node->right);
}





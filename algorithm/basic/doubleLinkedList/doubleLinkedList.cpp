/*This Program implement double linked list
Written by : seongjin.kim
Date : 2019.09.09
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _NODE{
    int data;
    struct _NODE* prev;
    struct _NODE* next;
}NODE;

NODE* head;
NODE* end;

void insertData(int data);
void deleteData(int target);
void printList();

int main(void){
    head = (NODE*)malloc(sizeof(NODE));
    end = (NODE*)malloc(sizeof(NODE));
    
    head->next = end;
    head->prev = NULL;
    end->prev = head;
    end->next = NULL;
    
    insertData(2);
    insertData(4);
    insertData(3);
    
    deleteData(3);
    printList();
}

void insertData(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    NODE* walker = head;
    if (!newNode){
        printf("Memory warning");
        exit(101);
    }
    newNode -> data = data;
    
    while (walker->next != end) {
        if(walker->next->data > data && walker->data < data){
            break;
        }
        walker = walker->next;
    }
    
    newNode -> next = walker -> next; //step1. concreate new node next and walker next
    walker->next->prev = newNode;     //step2. concreate walker next prev and new node
    walker->next = newNode;           //step3. concreate walker next to new node
    newNode -> prev = walker;         //step4. concreate new node prev to walker
}

void deleteData(int target){
    NODE* walker = head;
    NODE* toDel = NULL;
    
    while(walker != end){
        if(walker->next->data == target){
            toDel = walker->next;
            break;
        }
        walker = walker->next;
    }
    
    if(toDel==NULL){
        printf("can not find %d", target);
        return;
    }
    walker->next = toDel->next;
    toDel->next->prev = walker;
    free(toDel);
    return;

}

void printList(){
    NODE* walker = head->next;
    while(walker != end){
        printf("%d ", walker->data);
        walker = walker->next;
    }
    printf("\n");
    return;
}

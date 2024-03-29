﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "(Dia,KEHyeon)-MyEnglishNote(Header).h"

int main() {
    int menu = 1;
    linkedList_h* L;
    listNode* p;

    printf("Making LinkedList...");
    L = createLinkedList_h();  //create new linkedlist

    printFirst();  //Print some sentences when it start

    while(menu != 0) {
        menu = printMenu;  //Print menu and return to mode number
        if(menu == 0) break;
        else switch(menu) {
            case 1:
                manual();
                break;
            case 2:
                NewEnglishVoca();
                break;
            case 3:
                DeleteEnglishVoca();
                break;
            case 4: 
                PrintEnglishVoca();
                break;
            case 5:
                TestEnglishVoca();
                break;
        }
    }
    
    printf("Unlink LinkedList...");
    freeLinkedList_h(L);
    return 0;
}

void manual() {

}

void printFirst() {
    printf("===============\n");
    printf("This is your own computer English vocabulary!\n");
} 

void printMenu() {
    int menu;
    printf("===============\n");
    printf("Here is your menu!\n");
    printf("1. Manual!");
    printf("2. Enter New English vocabulary.\n");
    printf("3. Delete English vocabulary.\n");
    printf("4. Print all vocabulary.\n");
    printf("5. Quiz\n");
    printf("0: End this program.");
    printf("===============\n");
    printf("What do you want to do? : ");
    scanf("%d",&menu);
    while(1) {
        if(menu < 6) return menu;
        printf("You entered wrong number! Please enter again! : ");
        scanf("%d",&menu);
    }
    
}

void NewEnglishVoca() {

}

void DeleteEnglishVoca() {

}

void PrintEnglishVoca() {

}

void TestEnglishVoca() {

}

linkedList_h* createLinkedList_h() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(linkedList_h* L) {
    free(L);
}

void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p!=NULL) 
    {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(",");
    }
    printf(") \n");
}

void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = pre->link;
    pre->link = newNode;
}

void insertLastNode(linkedList_h* L, char* x) {
    listNode* lastNode;
    listNode* temp;
    lastNode = (listNode*)malloc(sizeof(listNode));
    strcpy(lastNode->data, x);
    lastNode->link = NULL;
    if (L->head == NULL) {
        L->head = lastNode;
        return;
    }

    temp = L->head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = lastNode;
}

listNode* searchNode(linkedList_h* L, char* x) {
    listNode* p;
    p = L->head;
    while (p != NULL) {
        if (strcmp((p->data), x) == 0) return p;
        p = p->link;
    }
}
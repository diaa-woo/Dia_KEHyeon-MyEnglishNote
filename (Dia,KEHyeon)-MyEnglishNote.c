﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "(Dia,KEHyeon)-MyEnglishNote(Header).h"

int main() {
    STACK s;
    int menu = 1;
    linkedList_h* L;
    listNode* p;
    createStack(&s);

    //FILE* fp = 0;

    printf("Welcome! MyEnglishNote ver b1.0.0!\n\n");
    printf("==============================================\n");

    nullCount = 0;
    while (1) {
        printf("Making LinkedList...\n");
        L = createLinkedList_h();  //create new linkedlist
        if (L != NULL) break;
        else printf("It's failed! retry...\n");
        nullCount++;
    }
    if (nullCount) printf("Linked! But...\nError counts: %d\n", nullCount);
    else printf("Linked!\n");
    nullCount = 0;
    printf("==============================================\n");

    /*while (1) {
        printf("File opening...\n");
        fp = file(fp, L);  //create new file
        if (fp != NULL) break;
        else printf("It's Failed! retry...\n");
        nullCount++;
    }
    if (nullCount) printf("Opened! But...\nError counts: %d\n", nullCount); 
    else printf("Opened!\n");*/
    nullCount = 0;
    
    printFirst();  //Print some sentences when it start

    while (menu != 0) {
        menu = printMenu();  //Print menu and return to mode number
        if (menu == 0) break;
        else switch (menu) {
        case 1:
            manual();
            break;
        case 2:
            NewEnglishVoca(L ,&s);
            break;
        case 3:
            DeleteEnglishVoca(L);
            break;
        case 4:
            PrintEnglishVoca(L);
            break;
        case 5:
            TestEnglishVoca(L, &s);
            break;
        }
    }

    //fclose(fp);

    printf("Unlink LinkedList...\n");
    freeLinkedList_h(L);
    printf("Unlinked!\n");
    printf("==============================================\n");
    printf("Done! Thank you!\n");
    return 0;
}

void printFirst() {
    printf("==============================================\n");
    printf("This is your own computer English vocabulary!\n");
}

int printMenu() {
    int menu;
    printf("==============================================\n");
    printf("Here is your menu!\n");
    printf("1. Manual!\n");
    printf("2. Enter New English vocabulary.\n");
    printf("3. Delete English vocabulary.\n");
    printf("4. Print all vocabulary.\n");
    printf("5. Quiz\n");
    printf("0: End this program.\n");
    printf("==============================================\n");
    printf("What do you want to do? : ");
    scanf_s("%d", &menu);
    while (1) {
        if (menu < 6) return menu;
        printf("You entered wrong number! Please enter again! : ");
        scanf_s("%d", &menu);
    }

}

FILE* file(FILE* fp, linkedList_h* L) {
    char buf[200] = { 0, };
    fp = fopen_s(&fp, "EnglishVocabulary.txt", "r+");
    if (fp == NULL) return fp;
    while (feof(fp) == 0) {
        fgets(buf, 200, fp);
    }
    return fp;
}

void manual() {
    printf("\n********************\n");
    printf("*                  *\n");
    printf("*       Used       *\n");
    printf("*   MIT - LICENSE  *\n");
    printf("*                  *\n");
    printf("*      made by     *\n");
    printf("*      diadntjr    *\n");
    printf("*      KEHyeon     *\n");
    printf("*                  *\n");
    printf("********************\n\n");
    printf("This is a comfortable English notebook\n");
    printf("When you enter some English vocabulary, it save to linkedlist.\n");
    printf("And it can delete vocabulary, and print all vocabulary in linkedlist.\n");
    printf("Also, It can make quiz for you.\n");
    printf("If you end this program, The linkedlist will be unlink and your vocabulary saved to text file.\n");
    printf("So, Have fun!\n");
}

void NewEnglishVoca(linkedList_h* L, STACK* s) {
    listNode* newNode;
    listNode* pre;
    newNode = (listNode*)malloc(sizeof(listNode));
    char voca[25] = { 0, };
    printf("Enter here!: ");
    scanf_s("%s", &voca, sizeof(voca));
    strcpy_s(newNode->data, MAX_LENGTHS, voca);
    newNode->link = L->head;
    L->head = newNode;
    for (int i = 0; voca[i] != '\0'; i++) {
        s->buf[i] = voca[i];
    }
    s->top++;
    return;
}

void DeleteEnglishVoca(linkedList_h* L) {
    listNode* deleteNode;
    listNode* p;
    deleteNode = (listNode*)malloc(sizeof(listNode));
    char voca[25] = { 0, };
    scanf_s("%s", &voca, sizeof(voca));
    p = searchNode(L, voca);
    if (p == NULL) printf("It doesn't have Data!\n\n");
    else {
        strcpy_s(deleteNode->data, MAX_LENGTHS, p->data);
        deleteNode->link = p->link;
        p->link = deleteNode;
        L->head = p->link;
        printf("Suecess\n\n");
    }
    return;
}

void PrintEnglishVoca(linkedList_h* L) {
    printList(L);
    printf("\n");
    return;
}

void TestEnglishVoca(linkedList_h* L, STACK* s) {
    char buf[50] = {0,};
    int random = 0, i = 5;
    random = rand() % (s->top);
    while (i--) {
        printf("%s? :");
        scanf_s("%s", buf);
    }
    return;
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
    while (p != NULL)
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
    strcpy_s(newNode->data, MAX_LENGTHS, x);
    newNode->link = L->head;
    L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy_s(newNode->data, MAX_LENGTHS, x);
    newNode->link = pre->link;
    pre->link = newNode;
}

void insertLastNode(linkedList_h* L, char* x) {
    listNode* lastNode;
    listNode* temp;
    lastNode = (listNode*)malloc(sizeof(listNode));
    strcpy_s(lastNode->data, MAX_LENGTHS, x);
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
    return NULL;
}

void createStack(STACK* s) {
    s->top = -1;
    return;
}

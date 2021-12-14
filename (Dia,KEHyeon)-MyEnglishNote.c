#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTHS 25

typedef struct listNode {
    char data[25];
    struct listNode* link;
}listNode;

typedef struct {
    listNode* head;
}linkedList_h;;

// 공백 연결 리스트 생성
linkedList_h* createLinkedList_h();

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L);

// 연결 리스트를 순서대로 출력하는 연사
void printList(linkedList_h* L);

// 첫번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x);

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);

// 마지막에 노드를 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x);

// 리스트에서 x 노드를 탐색하기
listNode* searchNode(linkedList_h* L, char* x);

int InputEnglishWord();

int main() {
    linkedList_h* L;
    listNode* p;

    printf("(1) 공백리스트 생성하기! \n");
    L = createLinkedList_h();  //create new linkedlist
    printList(L);

    printf("(2) 리스트 처음에 [수]노드 삽입하기! \n");
    insertFirstNode(L, "수");  //insert first node in linkedlist 
    printList(L);

    printf("(3) 리스트 마지막에 [금]노드 삽입하기! \n");
    insertLastNode(L, "금");  //insert last node in linkedlist
    printList(L);

    printf("(4) 리스트 첫 번째에 [월]노드 삽입하기! \n");
    insertFirstNode(L, "월");  //insert any place node in linkedlist
    printList(L);

    printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기! \n");
    p = searchNode(L, "수");  //search in linkedlist
    if (p == NULL) printf("찾는 데이터가 없습니다.\n");
    else insertMiddleNode(L, p, "목");
    printList(L);

    printf("(6) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
    freeLinkedList_h(L);  //Dobby is Free!
    printList(L);
    return 0;
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
    strcpy_s(newNode->data, MAX_LENGTHS,x);
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
    strcpy_s(lastNode->data, MAX_LENGTHS , x);
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
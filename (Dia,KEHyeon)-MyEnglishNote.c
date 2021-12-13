#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("공백리스트를 생성\n");
    L = createLinkedList_h();  //create new LinkedList
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
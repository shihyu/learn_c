/*=========================================================

    第 3-6 節:

      ListLength()
  =========================================================
*/

#include    <stdio.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;
    struct tagListNode* next;
} ListNode;
ListNode* listA;

int InsertTail(ListNode*, int);
int ListLength(ListNode*);
void ListTraverse(ListNode*);
void FreeAllNode(ListNode*);

void main(void) {
    FILE* fin;
    int insertdata, len;

    if ((fin = fopen("List.in", "r")) == NULL) {
        printf("File can not be opened, program terminate.");
        exit(1);
    }

    listA = (ListNode*)malloc(sizeof(ListNode));
    listA->next = NULL;
    fscanf(fin, "%d", &insertdata);

    while (!feof(fin)) {
        InsertTail(listA, insertdata);
        fscanf(fin, "%d", &insertdata);
    }

    fclose(fin);
    printf("\n The elements of the list are : \n");
    ListTraverse(listA);
    printf("\n ");
    len = ListLength(listA);
    printf("\n The length of the list is : %d \n", len);
    FreeAllNode(listA);     /*釋放所有節點*/
    exit(0);            /*結束程式*/
}

void ListTraverse(ListNode* head) {
    ListNode*   p = head;
    p = p->next ;

    while (p) {
        printf("\n%d", p->data);
        p = p->next ;
    }
}
int ListLength(ListNode* head) {
    int   counter = 0 ;
    ListNode* p = head ;

    while ((p = p->next) != NULL) { /* 空串列僅包含首節點 */
        counter ++ ;
    }

    return counter ;
}

int InsertTail(ListNode* head, int value) {
    ListNode* new_node, *p = head;

    if ((new_node = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        return (0);
    }

    new_node->data = value;
    new_node->next = NULL;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
    return (1);
}

void FreeAllNode(ListNode* head) {
    ListNode* next_node;

    while (head != NULL) {
        next_node = head->next;
        free(head);
        head = next_node;
    }
}


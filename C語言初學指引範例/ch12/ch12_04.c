/*******************************
    檔名:ch12_04.c
    功能:鏈結串列的練習
 *******************************/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int temp[5] = {1, 6, 8, 9, 2};
struct node {                /*  宣告節點結構資料型態 */
    int data;
    struct node* next;
};

typedef struct node* node_point;   /*  定義指向節點結構的指標別名*/

void trace_data(node_point* ptr);
void insert(node_point* ptr, node_point* worknode, int item);
void del(node_point* ptr, node_point* worknode, node_point* beforenode);

void insert(node_point* ptr, node_point* worknode, int item) {
    /*插入節點於worknode之後*/
    node_point newone = (node_point)malloc(sizeof(struct node));

    if (!(newone)) {
        printf("Memoey Full,can't alloc any node");
        return;
    }

    if (*ptr) {
        newone->data = item;
        newone->next = (*worknode)->next;
        (*worknode)->next = newone;
    } else {
        newone->data = item;
        newone->next = NULL;
        *ptr = newone;
    }
}
void del(node_point* ptr, node_point* worknode, node_point* beforenode) {
    /*刪除worknode節點，beforenode為worknode之前一節點後*/
    if (*ptr) {
        if (*beforenode) {
            (*beforenode)->next = (*worknode)->next;
            free(*worknode);
            *worknode = (*beforenode)->next;
        } else {
            *ptr = (*worknode)->next;
            free(*worknode);
            worknode = ptr;
        }
    } else {
        printf("linked list is empty ,can't delete any node");
        return;
    }
}

void trace_data(node_point* ptr) {
    node_point tracenode = *ptr;

    if (tracenode == NULL) {
        printf("no any node");
        return;
    }

    while (tracenode != NULL) {
        printf("%d \t", tracenode->data);
        tracenode = tracenode->next;
    }
}

void main(void) {
    node_point head = NULL;     /*   1.   建立串列名稱  */
    node_point worknode = NULL;
    node_point beforenode = NULL;
    int i;

    /***********************************/
    /*   2.   建立{1,6,8,9,2}          */
    for (i = 0; i < 5 ; i++) {
        insert(&head, &worknode, temp[i]);
        worknode = head;

        while (worknode->next != NULL) {
            worknode = worknode->next;
        }
    }

    /***********************************/
    /*   3.   刪除9, ---->{1,6,8,2}    */
    worknode = head;

    while (worknode->data != 9) {
        worknode = worknode->next;
    }

    beforenode = head;

    while (beforenode->next != worknode) {
        beforenode = beforenode->next;
    }

    del(&head, &worknode, &beforenode);    /*實際執行刪除9*/
    /***********************************/
    /*   4.   插入4, ---->{1,6,4,8,2}  */
    worknode = head;

    while (worknode->data != 6) {
        worknode = worknode->next;
    }

    insert(&head, &worknode, 4);           /*實際執行插入4*/
    /***********************************/
    trace_data(&head);                     /*循序瀏覽所有節點並列印資料*/
    /* system("pause"); */
}

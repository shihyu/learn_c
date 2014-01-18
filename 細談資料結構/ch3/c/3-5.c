/*=========================================================

    第 3-5 節

      InsertAfter() 插入節點
      DeleteNode()  刪除節點
      InsertTail()  於串列尾端增一新節點
      GetPreNode()  找尋指定節點之前一節點
      PrintList()   印出節點內容
      FreeAllNode() 釋放所有節點之記憶體空間

  =========================================================
*/

#include    <stdio.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;
    struct tagListNode* next;
} ListNode;
ListNode* listA;

int InsertAfter(ListNode*, int);
int DeleteNode(ListNode*, ListNode*);
int InsertTail(ListNode*, int);
ListNode* GetPreNode(ListNode*, ListNode*);
void FreeAllNode(ListNode*);
void PrintList(ListNode*);

void main(void) {
    int choose, i, insertdata, num;
    ListNode* p;
    FILE* fin;

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

    while (1) {
        printf("\n串列內容( Content of list )=>");
        PrintList(listA);
        printf("\n(1)附加節點(Append new node)\n(2)插入節點(Insert new node)\n(3)刪除節點(Delete node)\n(0)結束(exit)=>");
        scanf("%d", &choose);

        switch (choose) {
        case 0:
            FreeAllNode(listA);     /*釋放所有節點*/
            exit(0);            /*結束程式*/

        case 1:
            printf("請輸入欲附加之資料(Input new data )=>");
            scanf("%d", &insertdata);
            InsertTail(listA, insertdata);
            break;

        case 2:
            printf("請輸入欲插入之資料(Input new data)=>");
            scanf("%d", &insertdata);
            printf("請輸入欲插入之位置(New Position)=>");
            scanf("%d", &num);

            for (i = 1, p = listA; i != num && p != NULL; p = p->next, i++);

            if (p == NULL) {
                printf("插入失敗 ( Insert Failed )");
            } else if (InsertAfter(p, insertdata) == 0) {
                printf("插入失敗 ( Insert Failed )");
            }

            break;

        case 3:
            printf("請輸入欲刪除之資料 ( data to be deleted )=>");
            scanf("%d", &num);

            for (i = 0, p = listA; p != NULL && p->data != num; p = p->next, i++);

            if (p == NULL) {
                printf("此資料不在串列中( the data is not in list )");
            } else if (DeleteNode(listA, p) == 0) {
                printf("刪除失敗( Delete Failed)");
            }

            break;

        default:
            printf("選項錯誤 ( Wrong option ) !!");
        }
    }
}

int InsertAfter(ListNode* p, int value) {
    ListNode* newnode;
    newnode = (ListNode*)malloc(sizeof(ListNode));

    if (newnode == NULL) {
        return (0);
    }

    newnode->data = value;
    newnode->next = p->next;
    p->next = newnode;
    return (1);
}

int DeleteNode(ListNode* head, ListNode* node) {
    ListNode* GetPreNode(), *prenode;

    if (head == node) {
        return 0;
    }

    prenode = GetPreNode(head, node);

    if (prenode == NULL) {
        return 0;
    }

    prenode->next = node->next;
    free(node);
    return (1);
}

ListNode* GetPreNode(ListNode* head, ListNode* node) {
    ListNode* p, *q;
    p = head;
    q = head->next;

    while ((q != NULL) && (q != node)) {
        p = q;
        q = q->next;
    }

    if (q != NULL) {
        return (p);
    } else {
        return (NULL);
    }
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

void PrintList(ListNode* p) {
    for (p = p->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
}

void FreeAllNode(ListNode* head) {
    ListNode* next_node;

    while (head != NULL) {
        next_node = head->next;
        free(head);
        head = next_node;
    }
}

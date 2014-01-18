/*=========================================================

    3-8 節  雙向鏈結串列


      InsertAfter() 插入節點
      DeleteNode()  刪除節點
      PrintLIst()    印出節點內容
      FreeAllNode() 釋放所有節點之記憶體空間

  =========================================================
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tagDListNode {
    struct tagDListNode* left;
    int    data;
    struct tagDListNode* right;
} DListNode;

int     InsertAfter(DListNode*, int);
int     DeleteNode(DListNode*);
void    FreeAllNode(DListNode*);
void    PrintList(DListNode*);

void main(void) {
    int choose, i, insertdata, num;
    DListNode* p;
    DListNode* listA;
    FILE* fin;
    listA = (DListNode*)malloc(sizeof(DListNode));
    listA->left = listA;
    listA->right = listA;
    p = listA;

    if ((fin = fopen("List.in", "r")) == NULL) {
        printf("開檔失敗,結束程式 (File can not be opened, program terminate.)");
    } else {
        fscanf(fin, "%d", &insertdata);

        while (!feof(fin)) {
            InsertAfter(p, insertdata);
            p = p->right;
            fscanf(fin, "%d", &insertdata);
        }

        fclose(fin);

        while (1) {
            printf("\n環狀雙向鏈結串列內容( Content of circular doubly linked list )=>\n");
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

                for (p = listA; p->right != listA; p = p->right);

                InsertAfter(p, insertdata);
                break;

            case 2:
                printf("請輸入欲插入之資料(Input new data )=>");
                scanf("%d", &insertdata);
                printf("請輸入欲插入之位置(New Position)=>");
                scanf("%d", &num);

                for (i = 1, p = listA; i != num && p->right != listA; p = p->right, i++);

                if (p == NULL) {
                    printf("插入失敗( Insert Failed )");
                } else if (InsertAfter(p, insertdata) == 0) {
                    printf("插入失敗( Insert Failed )");
                }

                break;

            case 3:
                printf("請輸入欲刪除之資料 ( data to be deleted )=>");
                scanf("%d", &num);

                for (i = 0, p = listA->right; p != listA && p->data != num ; p = p->right, i++);

                if (p == listA) {
                    printf("此資料不在串列中( the data is not in list )");
                } else if (DeleteNode(p) == 0) {
                    printf("刪除失敗( Delete Failed)");
                }

                break;

            default:
                printf("選項錯誤 ( Wrong option )");
            }
        }
    }
}

int InsertAfter(DListNode* p, int value) {
    DListNode* newnode;
    newnode = (DListNode*)malloc(sizeof(DListNode));

    if (newnode == NULL) {
        return 0;
    }

    newnode->data = value;
    newnode->left = p;
    newnode->right = p->right;
    p->right->left = newnode;
    p->right = newnode;
    return 1;
}

int DeleteNode(DListNode* p) {
    if (p == NULL) {
        return (0);
    }

    p->left->right = p->right;
    p->right->left = p->left;
    free(p);
    return 1;
}

void PrintList(DListNode* head) {
    DListNode* p = head;

    for (p = p->right; p != head; p = p->right) {
        printf("%d ", p->data);
    }
}

void FreeAllNode(DListNode* head) {
    DListNode* CurrentNode = head->right, *NextNode;

    while (CurrentNode != head) {
        NextNode = CurrentNode->right;
        free(CurrentNode);
        CurrentNode = NextNode;
    }

    free(head);
}


/*=========================================================

      4-3節 用鏈結串列實作堆疊

      Push()    推入堆疊
      Pop()     自堆疊彈出資料

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
    int data;            /*資料欄位*/
    struct tagNode* next;
} StkNode;
StkNode TopOfS;
int Push(StkNode*, int);
int Pop(StkNode*, int*);
void PrintStack(StkNode*);

void main(void) {
    int choose, data, LoopFlag = 1;

    while (LoopFlag) {
        printf("\n堆疊內容由上到下 : \n");
        PrintStack(&TopOfS);
        printf("\n(1)ＰＵＳＨ資料\n(2)ＰＯＰ資料\n(0)結束=>");
        scanf("%d", &choose);

        switch (choose) {
        case 0:
            LoopFlag = 0;       /*結束程式*/
            break;

        case 1:
            printf("請輸入欲ＰＵＳＨ之資料=>");
            scanf("\n%d", &data);

            if (Push(&TopOfS, data) == 0) {
                printf("記憶體配置不成功,ＰＵＳＨ失敗");
            }

            break;

        case 2:
            if (Pop(&TopOfS, &data) == 0) {
                printf("堆疊已空,ＰＯＰ失敗");
            } else {
                printf("Pop 出 : %d", data);
            }

            break;

        default:
            printf("選項錯誤");
        }
    }
}

void PrintStack(StkNode* S) {
    StkNode*  p;

    for (p = S->next; p != NULL; p = p->next) {
        printf("%d\t", p->data);
    }
}

int Push(StkNode* S, int X) {
    StkNode* p;

    if ((p = (StkNode*)malloc(sizeof(StkNode))) == NULL) {
        return (0);
    }

    p->data = X;
    p->next = S->next;
    S->next = p;
    return (1);
}
int Pop(StkNode* S, int* X) {
    StkNode* p = S->next;

    if (p == NULL) {
        return (0);
    }

    *X = p->data;
    S->next = p->next;
    free(p);
    return (1);
}

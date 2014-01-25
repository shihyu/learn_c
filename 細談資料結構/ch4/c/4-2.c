/*=========================================================
    4-2節

      Push()    推入堆疊
      IsFull()  測試是否已滿
      Pop()     自堆疊彈出資料
      IsEmpty() 測試是否已空

  =========================================================
*/

#include <stdio.h>

#define MAX_ITEM    9

typedef struct tagSTACK {
    int item[MAX_ITEM];        /*資料欄位*/
    int  top;
} STACK;

int Push(STACK*, int);
int IsFull(STACK*);
int Pop(STACK*, int*);
int IsEmpty(STACK*);
void PrintStack(STACK*);

int main(void) {
    STACK S;
    int choose, LoopFlag = 1;
    int data;
    S.top = -1;

    while (LoopFlag) {
        printf("\n 堆疊內容由上到下 : \n");
        PrintStack(&S);
        printf("\n(1)ＰＵＳＨ資料\n(2)ＰＯＰ資料\n(0)結束=>");
        scanf("%d", &choose);

        switch (choose) {
        case 0:
            LoopFlag = 0;       /*結束程式*/
            break;

        case 1:
            printf("請輸入欲ＰＵＳＨ之資料=>");
            scanf("\n%d", &data);

            if (Push(&S, data) == 0) {
                printf("堆疊已滿,ＰＵＳＨ失敗");
            }

            break;

        case 2:
            if (Pop(&S, &data) == 0) {
                printf("堆疊已空,ＰＯＰ失敗");
            } else {
                printf("Pop 出 : %d", data);
            }

            break;

        default:
            printf("選項錯誤");
        }
    }

    return 0;
}

void PrintStack(STACK* s) {
    int i;

    if (IsEmpty(s)) {
        return ;
    }

    for (i = s->top; i >= 0; i--) {
        printf("%d ", s->item[i]);
    }

    printf("\n");
}

int Push(STACK* S, int X) {
    if (IsFull(S)) {
        return (0);
    }

    S->top = S->top + 1;
    S->item[S->top] = X;
    return (1);
}

int IsFull(STACK* S) {
    if (S->top == (MAX_ITEM - 1)) {
        return (1);
    } else {
        return (0);
    }
}

int Pop(STACK* S, int* X) {
    if (IsEmpty(S)) {
        return (0);
    }

    *X = S->item[S->top];
    S->top--;
    return (1);
}

int IsEmpty(STACK* S) {
    if (S->top == -1) {
        return (1);
    } else {
        return (0);
    }
}

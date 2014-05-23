/*
    堆疊的實作範例
*/

#include  <stdio.h>
#include  <stdlib.h>

/*--- 實作堆疊的結構 ---*/
typedef struct {
    int  max;       /* 堆疊的大小 */
    int  ptr;       /* 堆疊指標 */
    int*  stk;      /* 堆疊(指向堆疊前頭的指標) */
} Stack;

/*--- 確保堆疊，並初始化 ---*/
int StackAlloc(Stack* s, int max) {
    s->ptr = 0;

    if ((s->stk = calloc(max, sizeof(int))) == NULL) {  /* 堆疊確保失敗 */
        s->max = 0;
        return (-1);
    }

    s->max = max;
    return (0);
}

/*--- 釋放堆疊 ---*/
void StackFree(Stack* s) {
    if (s->stk != NULL) {           /* 若堆疊有正確產生的話 */
        free(s->stk);
        s->max = s->ptr = 0;
    }
}

/*--- 對堆疊push資料 ---*/
int StackPush(Stack* s, int x) {
    if (s->ptr >= s->max) {                 /* 堆疊已經滿了 */
        return (-1);
    }

    s->stk[s->ptr++] = x;
    return (0);
}

/*--- 從堆疊將資料pop出來 ---*/
int StackPop(Stack* s, int* x) {
    if (s->ptr <= 0) {                      /* 堆疊是空的 */
        return (-1);
    }

    *x = s->stk[--s->ptr];
    return (0);
}

/*--- 從堆疊將資料peek ---*/
int StackPeek(const Stack* s, int* x) {
    if (s->ptr <= 0) {                      /* 堆疊是空的 */
        return (-1);
    }

    *x = s->stk[s->ptr];
    return (0);
}


/*--- 傳回堆疊的大小 ---*/
int StackSize(const Stack* s) {
    return (s->max);
}

/*--- 傳回堆疊中所存放的資料數 ---*/
int StackNo(const Stack* s) {
    return (s->ptr);
}

/*--- 堆疊是否為空的 ---*/
int StackIsEmpty(const Stack* s) {
    return (s->ptr <= 0);
}

/*--- 堆疊是否為滿的 ---*/
int StackIsFull(const Stack* s) {
    return (s->ptr >= s->max);
}

/*--- 將堆疊清空 ---*/
void StackClear(Stack* s) {
    s->ptr = 0;
}

int main(void) {
    Stack  stk;

    if (StackAlloc(&stk, 100) == -1) {
        puts("堆疊確保失敗。");
        return (1);
    }

    while (1) {
        int  m, x;

        printf("現在的資料數 : %d/%d\n", StackNo(&stk), StackSize(&stk));
        printf("(1)push  (2)pop  (0)結束 : ");
        scanf("%d", &m);

        if (m == 0) {
            break;
        }

        switch (m) {
        case 1:
            printf("資料 : ");
            scanf("%d", &x);

            if (StackPush(&stk, x) == -1) {
                puts("無法push");
            }

            break;

        case 2:
            if (StackPop(&stk, &x) == -1) {
                puts("無法pop");
            } else {
                printf("pop的資料為%d。\n", x);
            }

            break;
        }
    }

    StackFree(&stk);

    return (0);
}

/*
  二元搜尋樹的實作範例．第2版
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define MAX_LEN     128             /* 名稱的字串長度 */
#define STK_SIZE    100             /* 堆疊的元素個數 */

/*--- 選單 ---*/
typedef enum {
    Term, Insert, Search, Next, Prev, Print
} Menu;

/*--- 二元樹的節點 ---*/
typedef struct __bnode {
    char            name[MAX_LEN];  /* 名稱 */
    struct __bnode*  left;          /* 指向左子的指標 */
    struct __bnode*  right;         /* 指向右子的指標 */
} BinNode;

/*--- 確保節點 ---*/
BinNode* AllocNode(void) {
    return ((BinNode*)calloc(1, sizeof(BinNode)));
}

BinNode* stk[STK_SIZE];             /* 搜尋用指標的堆疊 */
int     ptr;                        /* 堆疊指標 */

/*--- 錯誤顯示 ---*/
void Error(void) {
    puts("ERROR");
}

/*--- 插入節點 ---*/
BinNode* ApndNode(BinNode* p, BinNode* w) {
    int  cond;

    if (p == NULL) {
        p = AllocNode();
        strcpy(p->name, w->name);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w->name, p->name)) == 0) {
        printf("【錯誤】%s已被登錄。\n", w->name);
    } else if (cond < 0) {
        p->left    = ApndNode(p->left, w);    /* 注意到左子節點 */
    } else {
        p->right = ApndNode(p->right, w);    /* 注意到右子節點 */
    }

    return (p);
}

/*--- 節點的搜尋 ---*/
void SrchNode(BinNode* root, BinNode* w) {
    if (root != NULL) {
        BinNode*  p = root;
        ptr = 0;

        while (1) {
            if (p != NULL) {
                int  cond;

                stk[ptr++] = p;                 /* 放到堆疊中 */

                if ((cond = strcmp(w->name, p->name)) == 0) {
                    printf("%s已被登錄。\n", w->name);
                    ptr--;
                    break;
                }

                p = (cond < 0) ? p->left : p->right;
            } else {
                printf("%s未被登錄。\n", w->name);
                ptr = -1;
                break;
            }
        }
    }
}

/*--- 從以root為根的部分樹，找出最小(sw = 0)及最大(sw =1) ---*/
BinNode* SearchMinMax(BinNode* root, int sw) {
    if (root == NULL) {
        return (NULL);
    } else {
        BinNode*  p = root;

        while (p != NULL) {
            stk[++ptr] = p;                         /* 放入到堆疊 */
            p = (sw == 0) ? p->left : p->right;
        }

        return (stk[ptr]);
    }
}

/*--- 搜尋下一個(大一號)節點 ---*/
void SrchNext(void) {
    if (ptr == -1) {                                /* 堆疊為空的 */
        Error();
    } else {
        BinNode*  p;

        if (stk[ptr]->right != NULL) {              /* 右子存在 */
            p = SearchMinMax(stk[ptr]->right, 0);
        } else {                                    /* 右子不存在 */
            char*  name = stk[ptr]->name;

            while (1) {
                if (--ptr < 0) {
                    p = NULL;
                    break;
                }

                if (strcmp(stk[ptr]->name, name) > 0) {
                    p = stk[ptr];
                    break;
                }
            }
        }

        if (p == NULL) {
            Error();
        } else {
            printf("資料為[%s]。\n", p->name);
        }
    }
}

/*--- 搜尋上一個(小一號)節點 ---*/
void SrchPrev(void) {
    if (ptr == -1) {                                /* 堆疊為空的 */
        Error();
    } else {
        BinNode*  p;

        if (stk[ptr]->left != NULL) {               /* 左子存在 */
            p = SearchMinMax(stk[ptr]->left, 1);
        } else {                                    /* 左子不存在 */
            char*  name = stk[ptr]->name;

            while (1) {
                if (--ptr < 0) {
                    p = NULL;
                    break;
                }

                if (strcmp(stk[ptr]->name, name) < 0) {
                    p = stk[ptr];
                    break;
                }
            }
        }

        if (p == NULL) {
            Error();
        } else {
            printf("資料為[%s]。\n", p->name);
        }
    }
}

/*--- 將樹的全元素依鍵值由小而大顯示(非遞迴) ---*/
void PrintTree(BinNode* root) {
    if (root != NULL) {
        BinNode*  p = root;
        BinNode*  stk[STK_SIZE];            /* 堆疊 */
        int      ptr = 0;                   /* 堆疊指標 */

        while (1) {
            if (p != NULL) {
                stk[ptr++] = p;             /* 將p推入 */
                p = p->left;                /* 注意到左子 */
            } else if (ptr > 0) {
                p = stk[--ptr];             /* 取出 */
                printf("%s\n", p->name);    /* 顯示 */
                p = p->right;               /* 注目到右子 */
            } else {
                break;
            }
        }
    }
}

/*--- 將樹的全元素釋放 ---*/
void FreeTree(BinNode* p) {
    if (p != NULL) {
        FreeTree(p->left);                      /* 將p的左部分樹釋放 */
        FreeTree(p->right);                     /* 將p的右部分樹釋放 */
        free(p);                                /* 將p釋放 */
    }
}

/*--- 資料輸入 ---*/
BinNode Read(char* message) {
    BinNode  temp;

    printf("請輸入欲%s的名稱 : ", message);
    scanf("%s", temp.name);
    return (temp);
}

/*--- 選單選項 ---*/
Menu SelectMenu(void) {
    int  ch;

    do {
        printf(
            "\n(1)插入 (2)搜尋 (3)下一個節點 (4)前一個節點 (5)顯示 (0)結束 : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Print);

    return ((Menu)ch);
}

/*--- 主程式 ---*/
int main(void) {
    Menu     menu;
    BinNode*  root;

    root = NULL;
    ptr  = -1;

    do {
        BinNode  x;

        switch (menu = SelectMenu()) {
        case Insert :
            x = Read("插入");
            root = ApndNode(root, &x);
            break;

        case Search :
            x = Read("搜尋");
            SrchNode(root, &x);
            break;

        case Next   :
            SrchNext();
            break;

        case Prev   :
            SrchPrev();
            break;

        case Print  :
            puts("--- 一覽表 ---");
            PrintTree(root);
            break;
        }
    } while (menu != Term);

    FreeTree(root);

    return (0);
}

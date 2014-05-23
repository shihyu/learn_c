/*
  二元搜尋樹的實作範例
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define MAX_LEN     128             /* 名稱的字串長度 */

/*--- 選單 ---*/
typedef enum {
    Term, Insert, Search, Print
} Menu;

/*--- 二元樹的節點 ---*/
typedef struct __bnode {
    char            name[MAX_LEN];  /* 名稱 */
    struct __bnode*  left;          /* 指向左節點的指標 */
    struct __bnode*  right;         /* 指向右節點的指標 */
} BinNode;

/*--- 確保節點 ---*/
BinNode* AllocNode(void) {
    return ((BinNode*)calloc(1, sizeof(BinNode)));
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
        p->left    = ApndNode(p->left, w);    /* 看到左子節點 */
    } else {
        p->right = ApndNode(p->right, w);    /* 看到右子節點 */
    }

    return (p);
}

/*--- 節點的探索 ---*/
void SrchNode(BinNode* p, BinNode* w) {
    int  cond;

    if (p == NULL) {
        printf("%s未被登錄。\n", w->name);
    } else if ((cond = strcmp(w->name, p->name)) == 0) {
        printf("%s已被登錄。\n",   w->name);
    } else if (cond < 0) {
        SrchNode(p->left,  w);    /* 從左部分樹探索 */
    } else {
        SrchNode(p->right, w);    /* 從右部分樹探索 */
    }
}

/*--- 將樹的全要素依鍵值由小而大顯示 ---*/
void PrintTree(BinNode* p) {
    if (p != NULL) {
        PrintTree(p->left);                     /* 顯示p的左部分樹 */
        printf("%s\n", p->name);                /* 顯示p */
        PrintTree(p->right);                    /* 顯示p的右部分樹 */
    }
}

/*--- 將樹的全要素釋放 ---*/
void FreeTree(BinNode* p) {
    if (p != NULL) {
        FreeTree(p->left);                      /* 將p的左部分樹釋放 */
        FreeTree(p->right);                     /* 將p的右部分樹釋放 */
        free(p);                                /* 將p釋放 */
    }
}

/*--- 輸入資料 ---*/
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
        printf("\n(1)插入(2)探索(3)顯示(0)結束 : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Print);

    return ((Menu)ch);
}

/*--- 主程式 ---*/
int main(void) {
    Menu     menu;
    BinNode*  root;

    root = NULL;

    do {
        BinNode  x;

        switch (menu = SelectMenu()) {
        case Insert :
            x = Read("插入");
            root = ApndNode(root, &x);
            break;

        case Search :
            x = Read("探索");
            SrchNode(root, &x);
            break;

        case Print  :
            puts("--- 一覽表 ---");
            PrintTree(root);
        }
    } while (menu != Term);

    FreeTree(root);

    return (0);
}

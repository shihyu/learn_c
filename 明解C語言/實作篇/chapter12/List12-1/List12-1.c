/*
    線性清單的實作例
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

/*--- 選單 ---*/
typedef enum {
    Term, Insert, Append, Delete, Print, Clear
} Menu;

/*-- 節點 ---*/
typedef struct __node {
    int            no;          /* 會員號碼 */
    char           name[10];    /* 名稱 */
    struct __node*  next;       /* 指向後面節點的指標 */
} Node;

/*--- 在節點的各成員設定值 ----*/
void SetNode(Node* x, int no, char* name, Node* next) {
    x->no   = no;
    x->next = next;
    strcpy(x->name, name);
}

/*--- 確保一個節點 ---*/
Node* AllocNode(void) {
    return (calloc(1, sizeof(Node)));
}

/*--- 在前頭插入節點 ---*/
void InsertNode(Node** top, int no, char* name) {
    Node*  ptr = *top;
    *top = AllocNode();
    SetNode(*top, no, name, ptr);   /* next將指著之前為前頭的節點 */
}

/*--- 在末尾插入節點 ---*/
void AppendNode(Node** top, int no, char* name) {
    if (*top == NULL) {                     /* 若清單為空的話 */
        InsertNode(top, no, name);    /* 插入至前頭 */
    } else {
        Node*  ptr = *top;

        while (ptr->next != NULL) {         /* 找出末尾節點 */
            ptr = ptr->next;
        }

        ptr->next = AllocNode();
        SetNode(ptr->next, no, name, NULL);
    }
}

/*--- 刪除前頭的節點 ---*/
void DeleteNode(Node** top) {
    if (*top != NULL) {
        Node*  ptr = (*top)->next;
        free(*top);
        *top = ptr;
    }
}

/*--- 刪除全部的節點 ---*/
void ClearList(Node** top) {
    while (*top != NULL) {                  /* 刪除前頭的節點 */
        DeleteNode(top);    /* 直到清單清空為止 */
    }
}

/*--- 顯示全部的節點 ---*/
void PrintList(Node** top) {
    Node*  ptr = *top;

    puts("【一覽表】");

    while (ptr != NULL) {
        printf("%5d %-10.10s\n", ptr->no, ptr->name);
        ptr = ptr->next;
    }
}

/*--- 將線性清單初始化 ---*/
void InitList(Node** top) {
    *top = NULL;
}

/*--- 線性清單使用結束 ---*/
void TermList(Node** top) {
    ClearList(top);                     /* 刪除全部的節點 */
}

/*--- 輸入資料 ---*/
Node Read(char* message) {
    Node  temp;

    printf("請輸入要%s的資料。\n", message);

    printf("號碼 : ");
    scanf("%d", &temp.no);
    printf("名稱 : ");
    scanf("%s", temp.name);

    return (temp);
}

/*--- 選單選項 ---*/
Menu SelectMenu(void) {
    int  ch;

    do {
        printf("\n(1)在前頭插入節點	(2)在末尾插入節點\n");
        printf("(3)刪除前頭的節點	(4)顯示全部的節點\n");
        printf("(5)刪除全部的節點	(0)結　束　處　理 : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Clear);

    return ((Menu)ch);
}

/*--- 主程式 ---*/
int main(void) {
    Menu  menu;
    Node*  list;

    InitList(&list);

    do {
        Node  x;

        switch (menu = SelectMenu()) {
        case Insert:
            x = Read("插入");
            InsertNode(&list, x.no, x.name);
            break;

        case Append:
            x = Read("插入");
            AppendNode(&list, x.no, x.name);
            break;

        case Delete:
            DeleteNode(&list);
            break;

        case Print :
            PrintList(&list);
            break;

        case Clear :
            ClearList(&list);
            break;
        }
    } while (menu != Term);

    TermList(&list);
    return (0);
}

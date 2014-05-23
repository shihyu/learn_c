/*
  使用陣列的線性清單(附索引)
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define Null      -1            /* 空編號 */

typedef enum {
    Term, Insert, Append, Delete, Clear, Print, Print1, Print2
} Menu;

typedef int       Index;        /* 編號型 */

/* 會員號碼編號 */
typedef struct {
    int     no;
    Index   ptr;
} key1;

/* 名稱編號 */
typedef struct {
    char    name[10];
    Index   ptr;
} key2;

/*--- 元素 ---*/
typedef struct {
    int     no;             /* 會員號碼 */
    char    name[10];       /* 名稱 */
    Index   next;           /* 下一個元素的編號 */
    Index   Dnext;          /* 刪除清單指標 */
} Node;

/*--- 線性清單 ---*/
typedef struct {
    Node*    n;             /* 清單本體(陣列) */
    Index   top;            /* 清單前頭元素的編號 */
    Index   max;            /* 使用記錄的最大編號 */
    Index   deleted;        /* 刪除清單的前頭元素的編號 */
    Index   max2;           /* 現在被登錄的記錄數 */
    key1*    idx1;          /* 號碼編號表 */
    key2*    idx2;          /* 名稱編號表 */
} List;

#define Top     (list->top)             /* 清單的前頭 */

#define Second  (list->n[Top].next)     /* 清單第二個資料 */

#define Next(x) (list->n[(x)].next)     /* 第x記錄的下一個元素 */

/*--- 從號碼編號表做搜尋 ---*/
int Search1(List* list, int no, Index* flag) {
    int  i = 0;
    int  j = list->max2 - 1;

    if (j == -1) {                          /* 清單是空的 */
        *flag = 0;
        return (0);
    }

    do {                                    /* 使用二元樹的搜尋 */
        int  k = (i + j) / 2;
        int  cmp = no - list->idx1[k].no;

        if (!cmp) {
            *flag = k;
            return (1);
        } else if (cmp > 0) {
            i = k + 1;
        } else {
            j = k - 1;
        }
    } while (i <= j);

    *flag = i;

    return (0);
}

/*--- 從名稱編號表做搜尋 ---*/
int Search2(List* list, char* name, Index* flag) {
    int  i = 0;
    int  j = list->max2 - 1;

    if (j == -1) {                          /* 清單是空的 */
        *flag = 0;
        return (0);
    }

    do {                                    /* 使用二元樹的搜尋 */
        int  k = (i + j) / 2;
        int  cmp = strcmp(name, list->idx2[k].name);

        if (!cmp) {
            *flag = k;
            return (1);
        } else if (cmp > 0) {
            i = k + 1;
        } else {
            j = k - 1;
        }
    } while (i <= j);

    *flag = i;

    return (0);
}

/*---- 插入動作發生時更新編號表 ----*/
void Apnd(List* list, int no, char* name, Index rec) {
    Index  i;
    Index  idx;

    Search1(list, no, &idx);                    /*--- 號碼 ---*/

    for (i = list->max2; i > idx; i--) {
        list->idx1[i] = list->idx1[i - 1];
    }

    list->idx1[idx].no  = list->n[rec].no;
    list->idx1[idx].ptr = rec;

    Search2(list, name, &idx);                  /*--- 名稱 ---*/

    for (i = list->max2; i > idx; i--) {
        list->idx2[i] = list->idx2[i - 1];
    }

    strcpy(list->idx2[idx].name, list->n[rec].name);
    list->idx2[idx].ptr = rec;

    list->max2++;
}

/*---- 從清單刪除第rec個記錄 ----*/
void Delt(List* list, Index rec) {
    Index  i;

    for (i = 0; list->idx1[i].ptr != rec; i++)  /*--- 號碼 ---*/
        ;

    for (; i < list->max2; i++) {
        list->idx1[i] = list->idx1[i + 1];
    }

    for (i = 0; list->idx2[i].ptr != rec; i++)  /*--- 名稱 ---*/
        ;

    for (; i < list->max2; i++) {
        list->idx2[i] = list->idx2[i + 1];
    }

    list->max2--;
}

/*--- 傳回欲插入的記錄的編號 ---*/
int GetIndex(List* list) {
    if (list->deleted == Null) {        /* 無刪除記錄時 */
        return (++(list->max));
    } else {
        Index  rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return (rec);
    }
}

/*--- 將指定的記錄登錄至刪除清單 ---*/
void DeleteIndex(List* list, Index idx) {
    if (list->deleted == Null) {        /* 無刪除清單時 */
        list->deleted = idx;
        list->n[idx].Dnext = Null;
    } else {
        Index  ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

/*--- 在元素的各成員設定值 ----*/
void SetNode(Node* x, int no, char* name, Index next) {
    x->no   = no;
    x->next = next;
    strcpy(x->name, name);
}

/*--- 在前頭插入元素 ---*/
void InsertNode(List* list, int no, char* name) {
    Index  ptr = Top;

    Top = GetIndex(list);
    SetNode(&list->n[Top], no, name, ptr);
    Apnd(list, no, name, Top);
}

/*--- 在末尾插入元素 ----*/
void AppendNode(List* list, int no, char* name) {
    if (Top == Null) {                          /* 若清單是空的話 */
        InsertNode(list, no, name);    /* 則插入至前頭 */
    } else {
        Index  ptr = Top;

        while (Next(ptr) != Null) {             /* 找出末尾節點 */
            ptr = Next(ptr);
        }

        Next(ptr) = GetIndex(list);
        SetNode(&list->n[Next(ptr)], no, name, Null);
        Apnd(list, no, name, Next(ptr));
    }
}

/*--- 刪除前頭元素 ---*/
void DeleteNode(List* list) {
    if (Top != Null) {
        Index  ptr = Second;
        DeleteIndex(list, Top);
        Delt(list, Top);
        Top = ptr;
    }
}

/*--- 刪除全部的元素 ---*/
void ClearList(List* list) {
    while (Top != Null) {                   /* 刪除前頭節點 */
        DeleteNode(list);    /* 直到清單全空 */
    }
}

/*--- 顯示所有的元素(依清單順序) ---*/
void PrintList(List* list) {
    Index  ptr = Top;

    puts("【一覽表】");

    while (ptr != Null) {
        printf("%5d %-10.10s\n", list->n[ptr].no, list->n[ptr].name);
        ptr = Next(ptr);
    }
}

/*--- 顯示全部的元素(依號碼) ---*/
void PrintList1(List* list) {
    Index  i;

    puts("【一覽表/依號碼】");

    for (i = 0; i < list->max2; i++) {
        Index  j = list->idx1[i].ptr;
        printf("%5d %-10.10s\n", list->n[j].no, list->n[j].name);
    }
}

/*--- 顯示全部的元素(依名稱) ---*/
void PrintList2(List* list) {
    Index  i;

    puts("【一覽表/依名稱】");

    for (i = 0; i < list->max2; i++) {
        Index  j = list->idx2[i].ptr;
        printf("%5d %-10.10s\n", list->n[j].no, list->n[j].name);
    }
}

/*--- 將線性清單初始化 ---*/
void InitList(List* list, int size) {
    list->n    = calloc(size, sizeof(Node));        /* 清單本體 */
    list->idx1 = calloc(size, sizeof(key1));        /* 會員號碼清單本體 */
    list->idx2 = calloc(size, sizeof(key2));
    list->max2 = 0;
    list->top  = list->max = list->deleted = Null;
}

/*--- 結束線性清單的使用 ---*/
void TermList(List* list) {
    ClearList(list);                /* 刪除所有的節點 */
    free(list->n);
    free(list->idx1);
    free(list->idx2);
}

/*--- 資料的輸入 ---*/
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
        printf("\n(1)在前頭插入元素	(2)在末尾插入元素\n");
        printf("(3)刪除前頭的元素	(4)刪除全部的元素\n");
        printf("(5)將全部元素顯示(依清單順序)\n");
        printf("(6)將全部元素顯示(依　號　碼)\n");
        printf("(7)將全部元素顯示(依　名　稱)\n");
        printf("(0)處　　　理　　　結　　　束 : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Print2);

    return ((Menu)ch);
}

/*--- 主程式 ---*/
int main(void) {
    Menu  menu;
    List  list;

    InitList(&list, 100);               /* 最大節點數為100個 */

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

        case Clear :
            ClearList(&list);
            break;

        case Print :
            PrintList(&list);
            break;

        case Print1:
            PrintList1(&list);
            break;

        case Print2:
            PrintList2(&list);
            break;
        }
    } while (menu != Term);

    TermList(&list);

    return (0);
}

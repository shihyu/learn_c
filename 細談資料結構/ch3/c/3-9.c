/*=========================================================

    第3-9節: 鏈結串列的應用 -- 多項式的加法

      InsertAfter() 插入節點
      DeleteNode()  刪除節點
      Read_data()   自指定檔案讀入資料
      ViewP()   印出多項式
      FreeAllNode() 釋放所有節點之記憶體空間

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tagPListNode {
    float coef;          /*係數*/
    int   expo;          /*冪次*/
    struct tagPListNode* next;
} PListNode;

PListNode* AddTail(PListNode*, float, int);
PListNode*   PolyAdd(PListNode*, PListNode*);
void FreeAllNode(PListNode*);
void ViewP(PListNode*);
void Read_data(FILE*, PListNode*);

void main(void) {
    FILE* fin1, *fin2;
    PListNode*    Pa, *Pb, *Pc;

    if ((fin1 = fopen("PolyA.in", "r")) == NULL || (fin2 = fopen("PolyB.in", "r")) == NULL) {
        printf("開檔失敗,結束程式");
        exit(1);
    }

    Pa = (PListNode*)malloc(sizeof(PListNode));
    Pb = (PListNode*)malloc(sizeof(PListNode));
    Read_data(fin1, Pa);
    Read_data(fin2, Pb);
    Pc = PolyAdd(Pa, Pb);
    ViewP(Pa);
    printf("\n+\n");
    ViewP(Pb);
    printf("\n=\n");
    ViewP(Pc);
    FreeAllNode(Pa);
    FreeAllNode(Pb);
    FreeAllNode(Pc);
}

PListNode* AddTail(PListNode* tail, float co, int ex) {
    PListNode* p;
    p = (PListNode*)malloc(sizeof(PListNode));
    p->coef = co;
    p->expo = ex;
    p->next = NULL;
    tail->next = p;
    tail = p;
    return (tail);
}

PListNode* PolyAdd(PListNode* pa, PListNode* pb) {
    PListNode* c, *ctail;
    c = (PListNode*)malloc(sizeof(PListNode));
    ctail = c;
    pa = pa->next;
    pb = pb->next;

    while (pa && pb) {
        if (pa->expo > pb->expo) {
            ctail = AddTail(ctail, pa->coef, pa->expo);
            pa = pa->next;
        } else if (pa->expo < pb->expo) {
            ctail = AddTail(ctail, pb->coef, pb->expo);
            pb = pb->next;
        } else {
            if ((pa->coef + pb->coef) != 0) {
                ctail = AddTail(ctail, pa->coef + pb->coef, pa->expo);
            }

            pa = pa->next;
            pb = pb->next;
        }
    }

    while (pa) {
        ctail = AddTail(ctail, pa->coef, pa->expo);
        pa = pa->next;
    }

    while (pb) {
        ctail = AddTail(ctail, pb->coef, pb->expo);
        pb = pb->next;
    }

    return (c);
}
void Read_data(FILE* f, PListNode* Tail) {
    int expo;
    float coef;
    fscanf(f, "%f", &coef);      /*先讀讀看係數及乘冪,若未達檔尾,即*/
    fscanf(f, "%d", &expo);      /*都讀入成功後才建立此節點,否則會造*/

    while (!feof(f)) {           /*成最後一筆資料會建立兩次*/
        Tail = AddTail(Tail, coef, expo);
        fscanf(f, "%f", &coef);
        fscanf(f, "%d", &expo);
    }
}

void ViewP(PListNode* p) {
    for (; p->next != NULL; p = p->next) {
        printf("%2.3fx^%d+", p->next->coef, p->next->expo);
    }

    printf("%2.3fx^%d\n", p->coef, p->expo);
}

void FreeAllNode(PListNode* head) {
    PListNode* next_node;

    while (head->next != NULL) {
        next_node = head->next;
        free(head);
        head = next_node;
    }

    free(head);
}


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
#include <fstream.h>
#include <stdlib.h>

typedef struct tagPListNode {
    float coef;          //係數
    int   expo;          //冪次
    struct tagPListNode* next;
} PListNode;

PListNode* AddTail(PListNode*, float, int);
PListNode*   PolyAdd(PListNode*, PListNode*);
void FreeAllNode(PListNode*);
void ViewP(PListNode*);
void Read_data(PListNode*);
void PrintList(PListNode* head);
ifstream fin;

void main(void) {
    PListNode*   Pa, *Pb, *Pc;
    fin.open("POLYA.in", ios::in);

    if (!fin.good()) {
        cout << "File1 can not be opened, program terminate.";
        exit(1);
    }

    Pa = new PListNode;
    Read_data(Pa);
    fin.close();
    fin.open("POLYB.in", ios::in);

    if (!fin.good()) {
        cout << "File2 can not be opened, program terminate.";
        exit(1);
    }

    Pb = new PListNode;
    Read_data(Pb);
    fin.close();
    Pc = PolyAdd(Pa, Pb);
    ViewP(Pa);
    cout << "\n+\n";
    ViewP(Pb);
    cout << "\n=\n";
    ViewP(Pc);
    cout << "\n";
    FreeAllNode(Pa);
    FreeAllNode(Pb);
    FreeAllNode(Pc);
}

PListNode* AddTail(PListNode* tail, float co, int ex) {
    PListNode* p;
    p = new PListNode;
    p->coef = co;
    p->expo = ex;
    p->next = NULL;
    tail->next = p;
    tail = p;
    return (tail);
}

PListNode* PolyAdd(PListNode* pa, PListNode* pb) {
    PListNode* c, *ctail;
    c = new PListNode;
    ctail = c;
    pa = pa->next;
    pb = pb->next;

    while ((pa != NULL) && (pb != NULL)) {
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
void Read_data(PListNode* Tail) {
    int expo;
    float coef;
    fin >> coef >>  expo ;        //先讀讀看係數及乘冪,若未達檔尾,即都讀入成功後才建立此節點,否則會造

    while (!fin.eof()) {     //成最後一筆資料會建立兩次
        Tail = AddTail(Tail, coef, expo);
        fin >> coef >> expo ;
    }
}

void ViewP(PListNode* p) {
    for (; p->next != NULL; p = p->next) {
        cout << p->next->coef << "x^" << p->next->expo << " + ";
    }

    cout << p->coef << "x^" << p->expo;
}

void FreeAllNode(PListNode* head) {
    PListNode* next_node;

    while (head->next != NULL) {
        next_node = head->next;
        delete head;
        head = next_node;
    }

    free(head);
}

void PrintList(PListNode* head) {
    PListNode*   p = head;
    p = p->next ;

    while (p) {
        cout <<  "\n" << p->coef << " " << p->expo  ;
        p = p->next ;
    }
}


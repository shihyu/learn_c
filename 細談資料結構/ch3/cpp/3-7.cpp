/*=========================================================

    第 3-7 節:

      CListTraverse(), CListLength(), CInsertTail();
  =========================================================
*/

#include    <fstream.h>
#include    <iostream.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;
    struct tagListNode* next;
} ListNode;
ListNode* listA;

int CInsertTail(ListNode*, int);
int CListLength(ListNode*);
void CListTraverse(ListNode*);
void CFreeAllNode(ListNode*);

void main(void) {
    fstream fin;
    int insertdata, len;
    fin.open("List.in", ios::in);

    if (!fin) {
        cout << "File can not be opened, program terminate.";
        exit(1);
    }

    listA = new ListNode;
    listA->next = listA; //a simple circle
    fin >> insertdata;

    while (!fin.eof()) {
        CInsertTail(listA, insertdata);
        fin >> insertdata;
    }

    fin.close();
    cout << "\n The elements of the list are : \n";
    CListTraverse(listA);
    cout << endl;
    len = CListLength(listA);
    cout << "\n The length of the list is :" << len << "\n" ;
    CFreeAllNode(listA);        /*釋放所有節點*/
}

void CListTraverse(ListNode* head) {
    ListNode*   p = head;
    p = p->next ;

    while (p != head) {
        cout << endl << p->data ;
        p = p->next ;
    }
}
int CListLength(ListNode* head) {
    int   counter = 0 ;
    ListNode* p = head ;

    while ((p = p->next) != head) {
        counter ++ ;
    }

    return counter ;
}

int CInsertTail(ListNode* head, int value) {
    ListNode* new_node, *p = head;

    if ((new_node = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        return (0);
    }

    new_node->data = value;
    new_node->next = head;

    while (p->next != head) {
        p = p->next;
    }

    p->next = new_node;
    return (1);
}

void CFreeAllNode(ListNode* head) {
    ListNode* next_node, *ptr = head->next;

    while (ptr != head) {
        next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    }
}


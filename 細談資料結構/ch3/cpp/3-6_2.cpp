/*=========================================================

    第3-6節:

        ListConcate()
  =========================================================
*/

#include    <stdio.h>
#include    <fstream.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;                // 資料欄位
    struct tagListNode* next;   // 鏈結欄位
} ListNode;

int InsertTail(ListNode*, int);
int ListLength(ListNode*);
void ListTraverse(ListNode*);
void  ListConcate(ListNode*, ListNode*);
void FreeAllNode(ListNode*);

void main(void) {
    ListNode* listA, *listB;
    int insertdata;
    ifstream fin;
    fin.open("List.in", ios::in);

    if (!fin.good()) {
        cout << "File can not be opened, program terminate.";
        exit(1);
    }

    listA = new ListNode;
    listA->next = NULL;
    listB = new ListNode;
    listB->next = NULL;
    fin >> insertdata;

    while (!fin.eof()) {
        InsertTail(listA, insertdata);
        InsertTail(listB, insertdata);
        fin >> insertdata;
    }

    fin.close();
    cout << "\n The elements of the listA are : \n";
    ListTraverse(listA);
    cout << "\n ";
    cout << "\n The elements of the listB are : \n";
    ListTraverse(listB);
    cout << "\n ";
    ListConcate(listA, listB);
    cout << "\n The elements of the listA ( after concatenation ) are : \n";
    ListTraverse(listA);
    cout << "\n ";
    FreeAllNode(listA);     //釋放所有節點
    FreeAllNode(listB);     //釋放所有節點
}

void ListTraverse(ListNode* head) {
    ListNode*   p = head;
    p = p->next ;

    while (p) {
        cout << "  " << p->data ;
        p = p->next ;
    }
}
void  ListConcate(ListNode* listA, ListNode* listB) {
    ListNode* p = listA ;

    while (p->next != NULL) {
        p = p->next ;
    }

    p->next = listB->next ;
    listB->next = NULL ;
}

int InsertTail(ListNode* head, int value) {
    ListNode* new_node, *p = head;

    if ((new_node = new ListNode) == NULL) {
        return (0);
    }

    new_node->data = value;
    new_node->next = NULL;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
    return (1);
}

void FreeAllNode(ListNode* head) {
    ListNode* next_node;

    while (head != NULL) {
        next_node = head->next;
        delete head;
        head = next_node;
    }
}


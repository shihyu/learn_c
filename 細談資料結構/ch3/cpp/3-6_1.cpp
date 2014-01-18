/*=========================================================

    第3-6節

       ListLength()
  =========================================================
*/

#include    <stdio.h>
#include    <fstream.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;                // 資料欄位
    struct tagListNode* next;   // 鏈結欄位
} ListNode;
ListNode* listA;

int InsertTail(ListNode*, int);
int ListLength(ListNode*);
void ListTraverse(ListNode*);
void FreeAllNode(ListNode*);

void main(void) {
    int insertdata, len;
    ifstream fin;
    fin.open("List.in", ios::in);

    if (!fin.good()) {
        cout << "File can not be opened, program terminate.";
        exit(1);
    }

    listA = new ListNode;
    listA->next = NULL;
    fin >> insertdata;

    while (!fin.eof()) {
        InsertTail(listA, insertdata);
        fin >> insertdata;
    }

    fin.close();
    cout << "\n The elements of the list are : \n";
    ListTraverse(listA);
    cout << "\n ";
    len = ListLength(listA);
    cout << "\n The length of the list is : " << len << "\n";
    FreeAllNode(listA);     //釋放所有節點
}

void ListTraverse(ListNode* head) {
    ListNode*   p = head;
    p = p->next ;

    while (p) {
        cout <<  "\n" << p->data ;
        p = p->next ;
    }
}
int ListLength(ListNode* head) {
    int   counter = 0 ;
    ListNode* p = head ;

    while ((p = p->next) != NULL) { /* 空串列僅包含首節點 */
        counter ++ ;
    }

    return counter ;
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

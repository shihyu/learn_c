/*=========================================================

    3-5節

      InsertAfter() 插入節點
      DeleteNode()  刪除節點
      InsertTail()  於串列尾端增一新節點
      GetPreNode()  找尋指定節點之前一節點
      PrintList()   印出節點內容
      FreeAllNode() 釋放所有節點之記憶體空間

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

int InsertAfter(ListNode*, int);
int DeleteNode(ListNode*, ListNode*);
int InsertTail(ListNode*, int);
ListNode* GetPreNode(ListNode*, ListNode*);
void FreeAllNode(ListNode*);
void PrintList(ListNode*);
void main(void) {
    int choose, i, insertdata, num;
    ListNode* p;
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

    while (1) {
        cout << "\n串列內容( Content of list ) => ";
        PrintList(listA);
        cout << "\n(1)附加節點(Append new node)\n(2)插入節點(Insert new node)\n(3)刪除節點(Delete node)\n(0)結束(exit)=>";
        cin >> choose;

        switch (choose) {
        case 0:
            FreeAllNode(listA);     /*釋放所有節點*/
            exit(0);            /*結束程式*/

        case 1:
            cout << "請輸入欲附加之資料(Input new data )=>";
            cin >> insertdata;
            InsertTail(listA, insertdata);
            break;

        case 2:
            cout << "請輸入欲插入之資料(Input new data)=> ";
            cin >> insertdata;
            cout << "請輸入欲插入之位置(New Position)=> ";
            cin >> num;

            for (i = 1, p = listA; i != num && p != NULL; p = p->next, i++);

            if (p == NULL) {
                cout << "插入失敗 ( Insert Failed )";
            } else if (InsertAfter(p, insertdata) == 0) {
                cout << "插入失敗 ( Insert Failed )";
            }

            break;

        case 3:
            cout << "請輸入欲刪除之資料 ( data to be deleted )=> ";
            cin >> num;

            for (i = 0, p = listA; p != NULL && p->data != num; p = p->next, i++);

            if (p == NULL) {
                cout << "此資料不在串列中( the data is not in list )";
            } else if (DeleteNode(listA, p) == 0) {
                cout << "刪除失敗( Delete Failed)";
            }

            break;

        default:
            cout << "選項錯誤 ( Wrong option ) !!";
        }
    }
}

int InsertAfter(ListNode* p, int value) {
    ListNode* newnode;
    newnode = new ListNode;

    if (newnode == NULL) {
        return (0);
    }

    newnode->data = value;
    newnode->next = p->next;
    p->next = newnode;
    return (1);
}

int DeleteNode(ListNode* head, ListNode* node) {
    ListNode* prenode;

    if (head == node) {
        return 0;
    }

    prenode = GetPreNode(head, node);

    if (prenode == NULL) {
        return 0;
    }

    prenode->next = node->next;
    free(node);
    return (1);
}

ListNode* GetPreNode(ListNode* head, ListNode* node) {
    ListNode* p, *q;
    p = head;
    q = head->next;

    while ((q != NULL) && (q != node)) {
        p = q;
        q = q->next;
    }

    if (q != NULL) {
        return (p);
    } else {
        return (NULL);
    }
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

void PrintList(ListNode* p) {
    for (p = p->next; p != NULL; p = p->next) {
        cout << p->data << "  ";
    }
}

void FreeAllNode(ListNode* head) {
    ListNode* next_node;

    while (head != NULL) {
        next_node = head->next;
        delete head;
        head = next_node;
    }
}

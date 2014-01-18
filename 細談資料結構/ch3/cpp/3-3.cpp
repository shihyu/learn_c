/*=========================================================

    第三章:

        Array_List

      InsertAfter()     插入節點
      ListDelete()      刪除節點
      GetPreNode()      傳回指定節點之前一個節點
      PrintList()       顯示節點內容
      SearchNode()  找尋資料所在節點
      GetFreeNode()     找尋空節點
      SearchTwoNodes()  刪除時找到兩個節點
      table[MAX_NODE]   陣列鏈結串列
      MAX_NODE      串列空間數目(陣列大小)

  =========================================================
*/

#include <iostream.h>
#include <string.h>

#define MAX_NODE    9
#define TRUE    1
#define FALSE   -1

typedef struct tagListNode {
    char data[8];    /*資料欄位*/
    int  next;
} ListNode;
ListNode table[MAX_NODE] = {{"HEAD", 3}, {"USA", 6}, {"", -1},
    {"ROC", 1}, {"", -1}, {"", -1},
    {"UK", 7}, {"USSR", 0}, {"", -1}
};

int     InsertAfter(ListNode [], char [], char []);
int     SearchNode(ListNode [], char []);
int     GetPreNode(ListNode [], int);
int     ListDelete(ListNode [], char []);
void    PrintList(ListNode []);
unsigned GetFreeNode(ListNode []);
int     SearchTwoNodes(ListNode [], char [], int*, int*);

int main(void) {
    int choice = 0, loopflag = 1;
    char NewData[255], OldData[255];
    cout << "原串列 :\n";
    PrintList(table);

    while (loopflag) {
        cout << "(1)插入節點,(2)刪除節點, (其它鍵) 離開 =>";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n請輸入欲插入之資料=>";
            cin >> NewData;
            strupr(NewData);
            cout << "請輸入欲插入那一資料之後 ( 輸入HEAD代表成為第一個資料 ) =>";
            cin >> OldData;
            strupr(OldData);

            if (InsertAfter(table, OldData, NewData) == FALSE) {
                cout << "插入失敗\n";
                break;
            }

            cout << "插入 " << NewData << " 之後的串列 :\n";
            PrintList(table);
            break;

        case 2:
            cout << "\n請輸入欲刪除那一資料=>";
            cin >> OldData;
            strupr(OldData);

            if (ListDelete(table, OldData) == FALSE) {
                cout << "找不到資料,刪除失敗\n";
                break;
            }

            cout << "刪除 " << OldData << " 之後的串列 :\n";
            PrintList(table);
            break;

        default:
            loopflag = 0;
        }
    }

    return 0;
}

/*將資料插入串列中*/
int InsertAfter(ListNode table[], char OldData[], char NewData[]) {
    /*在資料為OldData的節點之後，加入新節點，資料為NewData[]*/
    int EmptyNode, i;
    EmptyNode = GetFreeNode(table); /*找空節點*/

    if (EmptyNode == 0) {           /*已經沒有空節點*/
        return FALSE;    /*告訴呼叫者此動作失敗*/
    }

    strcpy(table[EmptyNode].data, NewData);     /*複製資料到新節點*/
    i = SearchNode(table, OldData);     /*找出舊節點的位置*/

    if (i == FALSE) {
        return FALSE;
    }

    table[EmptyNode].next = table[i].next;  /*舊節點的次一元素變成新節點的次一元素*/
    table[i].next = EmptyNode;          /*改變舊節點的次一元素位置*/
    return TRUE;                        /*成功*/
}

/*找尋資料之所在節點*/
int SearchNode(ListNode table[], char KeyData[]) {
    /*找出資料為KeyData的節點，成功傳回位置，失敗傳回FALSE(-1)*/
    int current = table[0].next ;

    while (current != 0) {
        if (strcmp(KeyData, table[current].data) == 0) { /*比對相等*/
            return current;    /*告訴呼叫者位置*/
        }

        current = table[current].next;      /*比對失敗，試下一個*/
    }

    if (strcmp(KeyData, table[0].data) == 0) { /*為了適應本程式 */
        return 0;
    }

    return FALSE;                       /*告訴呼叫者失敗*/
}


/*刪除串列中一筆資料*/
int ListDelete(ListNode table[], char Data[]) {
    int PreNode, Node;

    if (SearchTwoNodes(table, Data, &PreNode, &Node) == FALSE)  /*找出欲刪除元素的
                               位置及欲刪除元素的前一元素位置*/
    {
        return FALSE;
    }

    table[PreNode].next = table[Node].next;
    table[Node].next = -1;
    return TRUE;
}


/*尋找欲刪除處之上一個節點*/
int GetPreNode(ListNode table[], int i) {
    int prenode = 0, node = table[prenode].next;

    while (node != i && node != 0) {
        prenode = node;
        node = table[node].next;
    }

    return (prenode);
}

/*顯示串列所有內容*/
void PrintList(ListNode table[]) {
    int i;

    for (i = table[0].next; i != 0; i = table[i].next) {
        cout << table[i].data << endl;
    }
}


/*找空節點*/
unsigned GetFreeNode(ListNode table[]) {
    unsigned i = 1;

    for (; i <= MAX_NODE ; i ++)
        if (table[i].next == -1) {
            return i;
        }

    return 0;
}

int SearchTwoNodes(ListNode table[], char Key[], int* left, int* right) {
    int prenode = 0, node = table[0].next;

    while ((node != 0) && strcmp(Key, table[node].data)) {
        /*未到串列末尾且未找到*/
        prenode = node;         /*prenode往下一個節點*/
        node = table[node].next;        /*node往下一個節點*/
    }

    if (node == 0) {
        return FALSE;
    }

    *left = prenode;
    *right = node;
    return TRUE;
}

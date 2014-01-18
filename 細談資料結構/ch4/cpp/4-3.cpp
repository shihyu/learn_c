/*=========================================================

       4-3節 用鏈結串列實作堆疊

      Push()    推入堆疊
      Pop()     自堆疊彈出資料

  =========================================================
*/

#include <iostream.h>
#include <malloc.h>

typedef struct tagnode {
    int data;                    //資料欄位
    struct tagnode* next;        //鏈結欄位
} StkNode;
StkNode TopOfS;
int Push(StkNode*, int);
int Pop(StkNode*, int*);
void PrintStack(StkNode*);

void main(void) {
    int choose, data, LoopFlag = 1;

    while (LoopFlag) {
        cout << "\n堆疊內容由上到下 : \n";
        PrintStack(&TopOfS);
        cout << "\n(1)ＰＵＳＨ資料\n(2)ＰＯＰ資料\n(0)結束 => ";
        cin >> choose;

        switch (choose) {
        case 0:
            LoopFlag = 0;       /*結束程式*/
            break;

        case 1:
            cout << "請輸入欲ＰＵＳＨ之資料 => ";
            cin >> data;

            if (Push(&TopOfS, data) == 0) {
                cout << "記憶體配置不成功,ＰＵＳＨ失敗";
            }

            break;

        case 2:
            if (Pop(&TopOfS, &data) == 0) {
                cout << "堆疊已空,ＰＯＰ失敗";
            } else {
                cout << "Pop 出 : " << data;
            }

            break;

        default:
            cout << "選項錯誤";
        }
    }
}

void PrintStack(StkNode* S) {
    StkNode*  p;

    for (p = S->next; p != NULL; p = p->next) {
        cout << "  " << p->data;
    }
}

int Push(StkNode* S, int X) {
    StkNode* p;

    if ((p = new StkNode) == NULL) {
        return (0);
    }

    p->data = X;
    p->next = S->next;
    S->next = p;
    return (1);
}
int Pop(StkNode* S, int* X) {
    StkNode* p = S->next;

    if (p == NULL) {
        return (0);
    }

    *X = p->data;
    S->next = p->next;
    delete p;
    return (1);
}

/*=========================================================

      4-6節  用陣列結構實作佇列

      Enqueue() 將資料自後端加入
      Dequeue() 將資料自前端刪除

  =========================================================
*/

#include <iostream.h>

#define MAX_ITEM    7

typedef struct tagQueue {
    int item[MAX_ITEM];        //資料
    int  front;
    int  rear;
} QUEUE;
QUEUE Que;

void PrintQueue(QUEUE&);
int  Enqueue(QUEUE&, int);
int  Dequeue(QUEUE&, int&);

void main(void) {
    int choose, LoopFlag = 1;
    int data;
    Que.front = 0;
    Que.rear = 0;

    while (LoopFlag) {
        cout << "\n佇列內容由前到後: ";
        PrintQueue(Que);
        cout << "\n(1)從佇列後端放資料\n(2)從佇列前端取資料\n(0)結束 => ";
        cin >> choose;

        switch (choose) {
        case 0:
            LoopFlag = 0;       /*結束程式*/
            break;

        case 1:
            cout << "請輸入欲放入之資料=> ";
            cin >> data;

            if (Enqueue(Que, data) == 0) {
                cout << "佇列已滿,Enqueue失敗 \n";
            }

            break;

        case 2:
            if (Dequeue(Que, data) == 0) {
                cout << "佇列已空,Dequeue失敗 \n ";
            } else {
                cout << "取出之資料為 => " << data << "\n";
            }

            break;

        default:
            cout << "選項錯誤\n";
        }
    }
}

void PrintQueue(QUEUE& q) {
    int i;

    if (q.front == q.rear) {
        return;    /* queue empty */
    }

    for (i = (q.front + 1) % MAX_ITEM; i != q.rear ;
            i = (i + 1) % MAX_ITEM) {
        cout << "  " << q.item[i];
    }

    cout << "  " << q.item[q.rear];
}

int Enqueue(QUEUE& q, int x) {
    if ((q.rear + 1) % MAX_ITEM == q.front) {
        return (0);
    }

    q.rear = (q.rear + 1) % MAX_ITEM;
    q.item [q.rear] = x;
    return (1);
}

int Dequeue(QUEUE& q, int& x) {
    if (q.front == q.rear) {
        return (0);
    }

    q.front = (q.front + 1) % MAX_ITEM;
    x = q.item[q.front];
    return 1;
}

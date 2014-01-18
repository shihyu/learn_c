/*=========================================================

      5-3節 廣度優先拜訪(BFS)

      BFS ()
      visit()       對頂點Vx作拜訪
      Enqueue()     將頂點Vx放入佇列
      Dequeue()     從佇列拿出一個頂點給Vx
      is_empty()    測試佇列是否為空
      Find_Adj()    找出與Vx相鄰且未被拜訪過的節點

  =========================================================
*/

#include <stdio.h>

#define MAX_ITEM 50
#define V   9   /*頂點數目*/

typedef struct tagQueue {
    int item[MAX_ITEM];
    int front;
    int rear;
} QUEUE;
QUEUE q;

int Col;
int visited[V];
int a[V][V] = {   {0, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0}
};

void BFS(int);
void visit(int);
int Enqueue(int);
int Dequeue(int*);
int is_empty(void);
char Find_Adj(int, char);

void main(void) {
    int V0;
    printf("請輸入起點: ");
    scanf("%d", &V0);
    BFS(V0);
}

void BFS(int V0) {
    int Vx, Vy;
    visit(V0);
    Enqueue(V0);

    while (!is_empty()) {
        Dequeue(&Vx);
        Vy = Find_Adj(Vx, 1);

        while (Vy != -1) {
            visit(Vy);
            Enqueue(Vy);
            Vy = Find_Adj(Vx, 0);
        }
    }
}

void visit(int Vx) {
    visited[Vx] = 1;
    printf("V%2d\n", Vx);
}

int Enqueue(int Vx) {
    if ((q.rear + 1) % MAX_ITEM == q.front) {
        return (0);
    }

    q.rear = (q.rear + 1) % MAX_ITEM;
    q.item[q.rear] = Vx;
    return (1);
}

int Dequeue(int* Vx) {
    if (is_empty()) {
        return (0);
    }

    q.front = ((q.front + 1) % MAX_ITEM);
    *Vx = q.item[q.front];
    return (1);
}

int is_empty(void) {
    if (q.front == q.rear) {
        return (1);
    } else {
        return (0);
    }
}

char Find_Adj(int Vx, char first) {
    if (first) {
        Col = 0;
    } else {
        Col++;
    }

    while (Col < V) {
        if (a[Vx][Col] == 0 || visited[Col]) {
            Col++;
        } else {
            return (Col);
        }
    }

    return (-1);
}

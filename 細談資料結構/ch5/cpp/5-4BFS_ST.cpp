/*=========================================================

      5-4節 廣度優先拜訪的展開樹 (BFS_ST)

      BFS_ST()
      visit()       對頂點Vx作拜訪
      Enqueue()     將頂點Vx放入佇列
      Dequeue()     從佇列拿出一個頂點給Vx
      is_empty()    測試佇列是否為空
      Find_Adj()    找出與Vx相鄰且未被拜訪過的節點

  =========================================================
*/

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

#define MAX_ITEM 20
#define MAX_V   20  //最多頂點數目

void BFS_ST(int);
void AddEdge(int, int);
void Visit(int);
int Enqueue(int);
int Dequeue(int*);
int IsEmpty(void);
char Find_Adj(int, char);
void ReadAdjMatrix(void);

typedef struct tagQueue {
    int item[MAX_ITEM];
    int front;
    int rear;
} QUEUE;
QUEUE q;
int RealV;
int Col;
int Visited[MAX_V];
int A[MAX_V][MAX_V];

void main(void) {
    int V0;
    ReadAdjMatrix();
    cout << "請輸入起點: ";
    cin >> V0;
    BFS_ST(V0);
}

void ReadAdjMatrix(void) {
    int i, j;
    ifstream    fin;
    fin.open("BFS.DAT", ios::in);

    if (!fin.good()) {
        cout << "BFS.dat Not Found !\n";
        exit(1);
    }

    fin >> RealV;

    if (RealV > MAX_V) {
        RealV = MAX_V;
    }

    for (i = 0 ; i < RealV; i++)
        for (j = 0; j < RealV; j++) {
            fin >> A[i][j];
        }

    fin.close();
}
void BFS_ST(int V0) {
    int Vx, Vy;
    Visit(V0);
    Enqueue(V0);

    while (!IsEmpty()) {
        Dequeue(&Vx);
        Vy = Find_Adj(Vx, 1);

        while (Vy != -1) {
            Visit(Vy);
            AddEdge(Vx, Vy);
            Enqueue(Vy);
            Vy = Find_Adj(Vx, 0);
        }
    }
}

void AddEdge(int Vx, int Vy) {
    cout << "Add Edge (V" << Vx << ",V" << Vy << ")\n";
}

void Visit(int Vx) {
    Visited[Vx] = 1;
    cout << "V" << Vx << "\n";
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
    if (IsEmpty()) {
        return (0);
    }

    q.front = ((q.front + 1) % MAX_ITEM);
    *Vx = q.item[q.front];
    return (1);
}

int IsEmpty(void) {
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

    while (Col < RealV)
        if (A[Vx][Col] == 0 || Visited[Col]) {
            Col++;
        } else {
            return (Col);
        }

    return (-1);
}

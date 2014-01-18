/*=========================================================

      5-5節 從某一點到其餘各點的最短路徑

      Dijkstra()    Dijkstra演算法
      find_min()    找出Decided[]=0且Dist最小者

      Cost[V][V]    圖形的加權鄰接矩陣
      Dist[V]   從起點到各點的最短距離
      Prior[V]  各點最短路徑中的前一個頂點
      Decided[V]    最短路逕是否已決定

  =========================================================
*/

#include <iostream.h>

#define V   7

int Cost[V][V] = {{0, 1, 4, 5, 15000, 15000, 15000},
    {1, 0, 15000, 2, 15000, 15000, 15000},
    {4, 15000, 0, 4, 15000, 3, 15000},
    {5, 2, 4, 0, 5, 2, 15000},
    {15000, 15000, 15000, 5, 0, 15000, 6},
    {15000, 15000, 3, 2, 15000, 0, 4},
    {15000, 15000, 15000, 15000, 6, 4, 0}
};

int Dist[V], Prior[V], Decided[V];

void Dijstra(int);
void find_min(int*);
void PrintPath(int, int);

void main(void) {
    int i, V0;
    cout << "請輸入起點: ";
    cin >> V0;
    Dijstra(V0);

    for (i = 0; i < V; i++) {
        if (i == V0) {
            continue;
        }

        cout << endl << "V" << V0 << " --> V" << i << "  Cost == " << Dist[i] << endl;
        PrintPath(V0, i);
    }
}

void Dijstra(int V0) {
    int Vx;
    int i, w;

    for (i = 0; i < V; i++) {
        Dist[i] = Cost[V0][i];
        Prior[i] = 0;
        Decided[i] = 0;
    }

    Decided[0] = 1;

    for (i = 1; i < V; i++) {
        find_min(&Vx);
        Decided[Vx] = 1;

        for (w = 0; w < V; w++) {
            if (!Decided[w] && (Dist[w] > (Dist[Vx] + Cost[Vx][w]))) {
                Dist[w] = Dist[Vx] + Cost[Vx][w];
                Prior[w] = Vx;
            }
        }
    }
}

void find_min(int* Vx) {
    int i;
    int l = 0, lowest = 32767;

    for (i = 0; i < V; i++)
        if (!Decided[i] && Dist[i] < lowest) {
            lowest = Dist[i];
            l = i;
        }

    *Vx = l;
}

void PrintPath(int V0, int Vx) {
    int i;
    cout << "V" << Vx << " 前一站是 ";

    for (i = Prior[Vx]; i != V0 ; i = Prior[i]) {
        cout << "V" << i << ", V" << i << "前一站是 ";
    }

    cout << "V" << V0 << endl;
}

/***************************************
* About:    有向圖的Dijkstra算法實現
* Author:   Tanky Woo
* Blog:     www.WuTianQi.com
***************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

const int maxnum = 100;
const int maxint = 999999;

// 各數組都從下標1開始
int dist[maxnum];     // 表示當前點到源點的最短路徑長度
int prev[maxnum];     // 記錄當前點的前一個結點
int c[maxnum][maxnum];   // 記錄圖的兩點間路徑長度
int n, line;             // 圖的結點數和路徑數

// n -- n nodes
// v -- the source node
// dist[] -- the distance from the ith node to the source node
// prev[] -- the previous node of the ith node
// c[][] -- every two nodes' distance
void Dijkstra(int n, int v, int* dist, int* prev, int c[maxnum][maxnum])
{
    bool s[maxnum];    // 判斷是否已存入該點到S集閤中

    for (int i = 1; i <= n; ++i) {
        dist[i] = c[v][i];
        s[i] = 0;     // 初始都未用過該點

        if (dist[i] == maxint) {
            prev[i] = 0;
        } else {
            prev[i] = v;
        }
    }

    dist[v] = 0;
    s[v] = 1;

    // 依次將未放入S集合的結點中，取dist[]最小值的結點，放入結合S中
    // 一旦S包含了所有V中頂點，dist就記錄了從源點到所有其他頂點之間的最短路徑長度
    // 注意是從第二個節點開始，第一個爲源點
    for (int i = 2; i <= n; ++i) {
        int tmp = maxint;
        int u = v;

        // 找出當前未使用的點j的dist[j]最小值
        for (int j = 1; j <= n; ++j)
            if ((!s[j]) && dist[j] < tmp) {
                u = j;              // u保存當前鄰接點中距離最小的點的號碼
                tmp = dist[j];
            }

        s[u] = 1;    // 表示u點已存入S集閤中

        // 更新dist
        for (int j = 1; j <= n; ++j)
            if ((!s[j]) && c[u][j] < maxint) {
                int newdist = dist[u] + c[u][j];

                if (newdist < dist[j]) {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

// 查找從源點v到終點u的路徑，並輸出
void searchPath(int* prev, int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];

    while (tmp != v) {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }

    que[tot] = v;

    for (int i = tot; i >= 1; --i)
        if (i != 1) {
            cout << que[i] << " -> ";
        } else {
            cout << que[i] << endl;
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    // 各數組都從下標1開始

    // 輸入結點數
    cin >> n;
    // 輸入路徑數
    cin >> line;
    int p, q, len;          // 輸入p, q兩點及其路徑長度

    // 初始化c[][]爲maxint
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            c[i][j] = maxint;
        }

    for (int i = 1; i <= line; ++i) {
        cin >> p >> q >> len;

        if (len < c[p][q]) {    // 有重邊
            c[p][q] = len;      // p指向q
            c[q][p] = len;      // q指向p，這樣表示無向圖
        }
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = maxint;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%8d", c[i][j]);
        }

        printf("\n");
    }

    Dijkstra(n, 1, dist, prev, c);

    // 最短路徑長度
    cout << "源點到最後一個頂點的最短路徑長度: " << dist[n] << endl;

    // 路徑
    cout << "源點到最後一個頂點的路徑爲: ";
    searchPath(prev, 1, n);
}

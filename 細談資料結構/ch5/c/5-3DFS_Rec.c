/*=========================================================

     5-3節 深度優先拜訪(DFS): 用遞迴函式

      DFS ()
      visit()       對頂點Vx作拜訪
      Find_Adj()    找出與Vx相鄰且未被拜訪過的節點

  =========================================================
*/

#include <stdio.h>

#define V   9   /*頂點數目*/

void DFS(int);
void visit(int);
char Find_Adj(int, char);

int visited[V], Col;
int a[V][V] = {   {0, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0}
};

void main(void) {
    int V0;
    printf("請輸入起點: ");
    scanf("%d", &V0);
    DFS(V0);
}

void DFS(int V0) {
    int Vx, temp;
    visit(V0);
    Vx = Find_Adj(V0, 1);

    while (Vx != -1) {
        temp = Col; /*將Col先存起來,以免遞迴呼叫時被更改*/
        DFS(Vx);
        Col = temp;
        Vx = Find_Adj(V0, 0);
    }
}

void visit(int Vx) {
    visited[Vx] = 1;
    printf("V%2d\n", Vx);
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

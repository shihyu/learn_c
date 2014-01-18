/*=========================================================

      5-4節 Kruskal

      Kruskal() Kruskal演算法函式
      init()    開檔讀入 E  陣列
      SelectEdge()  選出花費最小且未入選的邊
      Cycle()   判斷ex加入 ST 之後是否會造成環路
      PrintST() 印出最後的結果
      FindRoot()    尋找同一集合的根(代表)
      AddEdge() 把一邊加入 ST 中

  =========================================================
*/

#include <stdio.h>

#define     e   7
#define     V   5

typedef struct edge {
    int Vx, Vy;
    int cost;
    char selected;
} EDGE;
EDGE E[e];

int Vertex[V];
FILE*  fin;

int init(void);
void Kruskal(void);
int SelectEdge(void);
char Cycle(int);
void AddEdge(int);
void PrintST(void);
int  FindRoot(int);

void main(void) {
    int FlagInit;
    FlagInit = init();

    if (FlagInit) {
        Kruskal();
    }
}

int init(void) {
    int i;

    for (i = 0; i < V; i++) {
        Vertex[i] = i;    /* 初設 */
    }

    if ((fin = fopen("kruskal.in", "r")) == NULL) {
        printf("開檔失敗, 結束程式");
        return 0;
    }

    printf("  Vx    Vy    Cost\n");

    for (i = 0; i < e; i++) {
        fscanf(fin, "%d", &E[i].Vx);
        fscanf(fin, "%d", &E[i].Vy);
        fscanf(fin, "%d", &E[i].cost);
        fscanf(fin, "%d", &E[i].selected);
        printf("  %d     %d     %d\n", E[i].Vx, E[i].Vy, E[i].cost);
    }

    return 1;
}

void Kruskal(void) {
    int edge = 0;
    int ex;

    while (edge < V - 1) {
        ex = SelectEdge();

        if (!Cycle(ex)) {
            AddEdge(ex);
            edge++;
        } else {
            E[ex].selected = 2;
        }
    }

    PrintST();
}

int SelectEdge(void) {
    int ex = 0, i;
    int min_cost = 32767;

    for (i = 0; i < e; i++)
        if (!E[i].selected && E[i].cost < min_cost) {
            ex = i;
            min_cost = E[i].cost;
        }

    return (ex);
}

int FindRoot(int vx) {
    while (Vertex[vx] != vx) {
        vx = Vertex[vx];
    }

    return (vx);
}

char Cycle(int ex) {
    int i, j;
    i = FindRoot(E[ex].Vx);
    j = FindRoot(E[ex].Vy);

    if (i == j) {      /* 屬於同一集合 */
        return (1);
    }

    return (0);
}

void AddEdge(int ex) {
    int i, j;
    E[ex].selected = 1;
    i = FindRoot(E[ex].Vx);
    j = FindRoot(E[ex].Vy);
    Vertex[i] = j;      /*合成一集合*/
}

void PrintST(void) {
    int cost = 0;
    int i;

    for (i = 0; i < e; i++)
        if (E[i].selected == 1) {
            printf("V%d,V%d selected, cost=%d\n", E[i].Vx, E[i].Vy, E[i].cost);
            cost = cost + E[i].cost;
        }

    printf("Totol Cost is :%d\n", cost);
}

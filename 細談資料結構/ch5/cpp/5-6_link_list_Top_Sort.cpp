/*=========================================================

      5-6節 拓樸排序:使用鄰接串列

      topolody_sort()  拓樸排序函式
      M_to_List()      將鄰接矩陣作成鄰接串列

  =========================================================
*/

#include <iostream.h>

#define V   7
typedef struct node {
    int vertex;
    struct node* next;
} ANODE;
ANODE AdjList[V];

int M[V][V] = {   {0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0}
};

void M_to_List(void);
void topology_sort(void);

void main(void) {
    M_to_List();
    topology_sort();
}

void topology_sort(void) {
    int i, n, top = -1, k;
    ANODE* p;

    for (i = 0; i < V; i++)
        if (AdjList[i].vertex == 0) {
            AdjList[i].vertex = top;
            top = i;
        }

    for (i = 0; i < V; i++) {
        if (top == -1) {
            cout << "NetWork has a cycle";
            break;
        }

        n = top;
        top = AdjList[top].vertex;
        cout << " V" << n ;
        p = AdjList[n].next;

        while (p != NULL) {
            k = p->vertex;
            (AdjList[k].vertex)--;

            if (AdjList[k].vertex == 0) {
                AdjList[k].vertex = top;
                top = k;
            }

            p = p->next;
        }

        cout << endl;
    }
}

void M_to_List(void) {
    int i, j;
    ANODE* New_Node, *p;

    for (i = 0; i < V; i++) {
        AdjList[i].next = NULL;
        p = &AdjList[i];

        for (j = 0; j < V; j++)
            if (M[i][j] == 1) {
                AdjList[j].vertex++;
                New_Node = new ANODE;
                New_Node->vertex = j;
                New_Node->next = NULL;
                p->next = New_Node;
                p = p->next;
            }
    }
}

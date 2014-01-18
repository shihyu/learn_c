/*=========================================================

      6-6節 引線二元樹

          *TBTCreate()         建立引線二元樹
          *TBTInsert()         插入節點
          *TBTInorder()     中序追蹤

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>

#define THREAD  1
#define POINTER 0
#define TRUE    1
#define FALSE   0
#define LEFT    1
#define RIGHT   0
typedef struct tagNODE {
    char left_thread;
    struct tagNODE* left_c;
    int data;
    char right_thread;
    struct tagNODE* right_c;
} Th_Node;

void TBTCreate(Th_Node*);
void TBTInsert(Th_Node*, Th_Node*);
Th_Node* InorderSuccessor(Th_Node*);
void  TBTInorder(Th_Node*);
void  visit(Th_Node*);

void main(void) {
    Th_Node ThreadBT;
    ThreadBT.left_thread = THREAD;
    ThreadBT.right_thread = POINTER;
    ThreadBT.right_c = ThreadBT.left_c = &ThreadBT;
    TBTCreate(&ThreadBT);
    printf("The nodes of a Threaded Binary Tree are (inorder) :\n");
    TBTInorder(&ThreadBT);
    printf("\n");
}

void visit(Th_Node* p) {
    printf(" %d ", p->data);
}

Th_Node* InorderSuccessor(Th_Node* p) {
    if (p->right_thread == THREAD) {
        p = p->right_c;
    } else {
        p = p->right_c;

        while (p->left_thread == POINTER) {
            p = p->left_c;
        }
    }

    return (p);
}

void TBTInorder(Th_Node* TBT) {
    Th_Node* p = TBT;

    while ((p = InorderSuccessor(p)) != TBT) {
        visit(p);
    }
}

int TestLeaf(Th_Node* p, int Direction) {
    if (Direction == LEFT) {
        if (p->left_thread == THREAD) {
            return TRUE;
        } else {
            return    FALSE;
        }
    } else {
        if (p->right_thread == THREAD) {
            return TRUE;
        } else {
            return    FALSE;
        }
    }
}
void TBTInsert(Th_Node* TBT, Th_Node* p) {
    Th_Node* r = TBT->left_c;
    int Dir, FlagLeaf = FALSE;

    if (r == TBT) { // only Head
        r->left_thread = POINTER;
        r->left_c = p;
        p->right_c = r;
        return;
    }

    FlagLeaf = FALSE;

    do {
        if (p->data < r->data) {
            Dir = LEFT;

            if (!TestLeaf(r, Dir)) {
                r = r->left_c;
            } else {
                FlagLeaf = TRUE;
            }
        } else {
            Dir = RIGHT;

            if (!TestLeaf(r, Dir)) {
                r = r->right_c;
            } else {
                FlagLeaf = TRUE;
            }
        }
    } while (!FlagLeaf);

    if (Dir == LEFT) {
        p->right_c = r;
        p->left_c = r->left_c;
        r->left_c = p;
        r->left_thread = POINTER;
    } else {
        p->left_c = r;
        p->right_c = r->right_c;
        r->right_c = p;
        r->right_thread = POINTER;
    }
}


void TBTCreate(Th_Node* TBT) {
    FILE* filedata;
    int data;
    Th_Node* p;
    filedata = fopen("BST.dat", "r");

    while (fscanf(filedata, "%d", &data) != EOF) {
        p = (Th_Node*)malloc(sizeof(Th_Node));
        p->left_thread = p->right_thread = THREAD;
        p->data = data;
        TBTInsert(TBT, p);
    }
}


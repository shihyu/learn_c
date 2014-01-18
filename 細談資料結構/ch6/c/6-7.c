/*=========================================================
     6-7節 二元搜尋樹的建立,節點插入,節點搜尋,節點刪除

          *bst_create()         建立二元搜尋樹
          *bst_insert()         插入節點
          *bst_search()         搜尋節點
          *bst_delete()         刪除節點

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
    char left_thread;
    struct tagNode* left_c;
    int data;
    char right_thread;
    struct tagNode* right_c;
} TNode;
TNode* listA;

TNode* bst_create(void);
TNode* bst_insert(TNode*, TNode*);
TNode* bst_search(TNode* t, int);
TNode* bst_delete(TNode* t, int);
void  inorder(TNode* t);
void  visit(TNode*);

void main(void) {
    TNode* p;
    int choose, data, LoopFlag = 1;
    listA = bst_create();

    while (LoopFlag) {
        printf("BST中序: ");
        inorder(listA);
        printf("\n(1)插入資料\n(2)搜尋資料\n(3)刪除資料\n(0)結束=>");
        scanf("%d", &choose);

        switch (choose) {
        case 0:
            LoopFlag = 0;
            break;                        /*結束程式*/

        case 1:
            printf("請輸入欲建立之資料=>");
            scanf("%d", &data);
            p = (TNode*)malloc(sizeof(TNode));
            p->data = data;
            listA = bst_insert(listA, p);
            break;

        case 2:
            printf("請輸入欲搜尋之資料=>");
            scanf("%d", &data);

            if (bst_search(listA, data) == NULL) {
                printf("找不到資料\n");
            } else {
                printf("找到!!!\n");
            }

            break;

        case 3:
            printf("請輸入欲刪除之資料=>");
            scanf("%d", &data);

            if (bst_delete(listA, data) == NULL) {
                printf("刪除資料錯誤失敗!!\n");
            } else {
                printf("刪除完成!!\n");
            }

            break;

        default:
            printf("選項錯誤");
        }
    }
}

void visit(TNode* p) {
    printf("%d ", p->data);
}


void inorder(TNode* p) {
    if (p != NULL) {
        inorder(p->left_c);
        visit(p);
        inorder(p->right_c);
    }
}

TNode* bst_insert(TNode* t, TNode* p) {
    TNode* r, *q;
    char direction;
    p->left_c = p->right_c = NULL;

    if (t == NULL) {
        t = p;
    } else {
        q = t;

        while (q != NULL) {
            if (p->data < q->data) {
                direction = 1;
                r = q;
                q = q->left_c;
            } else if (p->data > q->data) {
                direction = 0;
                r = q;
                q = q->right_c;
            } else {
                return (t);
            }
        }

        if (direction == 1) {
            r->left_c = p;
        } else {
            r->right_c = p;
        }
    }

    return (t);
}


TNode* bst_create(void) {
    FILE* filedata;
    int data;
    TNode* t, *p;
    filedata = fopen("bst.dat", "r");
    t = NULL;

    while (!feof(filedata)) {
        fscanf(filedata, "%d", &data);
        p = malloc(sizeof(TNode));
        p->data = data;
        t = bst_insert(t, p);
    }

    return (t);
}


TNode* bst_search(TNode* t, int key) {
    while (t != NULL) {
        if (key == t->data) {
            return (t);
        } else if (key < t->data) {
            t = t->left_c;
        } else {
            t = t->right_c;
        }
    }

    return (NULL);
}


TNode* bst_delete(TNode* p, int key) {
    int found = 0, direction = 0;
    TNode* r, *q, *s, *t;
    r = q = s = NULL;
    t = p;

    while (p != NULL && !found) {
        if (key == p->data) {
            found = 1;
        } else if (key < p->data) {
            direction = 1;
            r = p;
            p = p->left_c;
        } else {
            direction = 0;
            r = p;
            p = p->right_c;
        }
    }

    if (p == NULL) {
        return (NULL);
    }

    if (r == NULL) {
        if (p->right_c == NULL) {
            return (p->left_c);
        } else if (p->left_c == NULL) {
            return (p->right_c);
        }
    }

    if (p->right_c == NULL) {
        if (direction == 1) {
            r->left_c = p->left_c;
        } else {
            r->right_c = p->left_c;
        }
    } else if (p->left_c == NULL) {
        if (direction == 1) {
            r->left_c = p->right_c;
        } else {
            r->right_c = p->right_c;
        }
    } else {
        s = p;
        q = p->left_c;

        while (q->right_c != NULL) {
            s = q;
            q = q->right_c;
        }

        p->data = q->data;

        if (p == s) {
            s->left_c = q->left_c;
        } else {
            s->right_c = q->left_c;
        }
    }

    return (t);
}

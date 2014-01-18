/*=========================================================
     6-7節 二元搜尋樹的建立,節點插入,節點搜尋,節點刪除

          *bst_create()         建立二元搜尋樹
          *bst_insert()         插入節點
          *bst_search()         搜尋節點
          *bst_delete()         刪除節點

  =========================================================
*/

#include <iostream.h>
#include <fstream.h>

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
        cout << " BST中序: ";
        inorder(listA);
        cout << endl << "(1)插入資料\n(2)搜尋資料\n(3)刪除資料\n(0)結束=> ";
        cin >> choose;

        switch (choose) {
        case 0:
            LoopFlag = 0;
            break;                        /*結束程式*/

        case 1:
            cout << "請輸入欲建立之資料=> ";
            cin >> data;
            p = new TNode;
            p->data = data;
            listA = bst_insert(listA, p);
            break;

        case 2:
            cout << "請輸入欲搜尋之資料=> ";
            cin >> data;

            if (bst_search(listA, data) == NULL) {
                cout << "找不到資料" << endl;
            } else {
                cout << "找到!!!" << endl;
            }

            break;

        case 3:
            cout << "請輸入欲刪除之資料=>";
            cin >> data;

            if (bst_delete(listA, data) == NULL) {
                cout << "刪除資料錯誤失敗!!" << endl;
            } else {
                cout << "刪除完成!!" << endl;
            }

            break;

        default:
            cout << "選項錯誤" << endl;
        }
    }
}

void visit(TNode* p) {
    cout << p->data << " ";
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
    fstream datafile;
    int data;
    TNode* t, *p;
    datafile.open("bst.dat", ios::in);
    t = NULL;
    datafile >> data;

    while (!datafile.eof()) {
        p = new TNode;
        p->data = data;
        t = bst_insert(t, p);
        datafile >> data;
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

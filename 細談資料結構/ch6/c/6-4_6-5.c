/*=========================================================

       6-4節    二元樹的建立
       6-5節    二元樹的走訪

          *Create_BinTree()     二元樹建立函式
          preorder()            前序走訪函式
          inorder()             中序走訪函式
          postorder()           後序走訪函式
          visit()               拜訪節點
          visit2()              拜訪節點順便將記億體釋回
                                本例利用後序拜訪時一一將
                                子樹所占之記憶體釋回

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>
#include <conio.h>

typedef struct Tnode {
    struct Tnode* left_c;
    char    data;
    struct Tnode* right_c;
} TNode;

TNode* Create_BinTree(void);
void preorder(TNode*);
void inorder(TNode*);
void postorder(TNode*);

void main(void) {
    TNode* tree;
    printf("輸入節點資料 (例如 ab00c00 ): \n");
    tree = Create_BinTree();
    printf("\n前序走訪結果=> ");
    preorder(tree);
    printf("\n中序走訪結果=> ");
    inorder(tree);
    printf("\n後序走訪結果=> ");
    postorder(tree);
    printf("\n");
}

TNode* Create_BinTree(void) {
    TNode* ptr;
    char data;
    data = getche();

    if (data == '0') {
        return (NULL);
    }

    ptr = (TNode*)malloc(sizeof(TNode));
    ptr->data = data;
    ptr->left_c = Create_BinTree();
    ptr->right_c = Create_BinTree();
    return (ptr);
}

void visit(TNode* p) {
    printf("%c ", p->data);
}

/*後序走訪時*/
void visit2(TNode* p) {
    printf("%c ", p->data);
    free(p);
}

void preorder(TNode* p) {
    if (p != NULL) {
        visit(p);
        preorder(p->left_c);
        preorder(p->right_c);
    }
}

void inorder(TNode* p) {
    if (p != NULL) {
        inorder(p->left_c);
        visit(p);
        inorder(p->right_c);
    }
}

void postorder(TNode* p) {
    if (p != NULL) {
        postorder(p->left_c);
        postorder(p->right_c);
        visit2(p);
    }
}

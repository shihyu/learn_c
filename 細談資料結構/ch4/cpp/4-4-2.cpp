/*=========================================================
    4-4-2節

     堆疊的應用:運算式轉換及求值
        中序轉後序
        後序式求值

      in_to_post()  中序轉後序
      priority()    判斷運算元的優先順序
      post_evaluate()後序式求值
      evaluate()    一指定運算元計算
      Push()    推入堆疊
      Pop()     自堆疊彈出資料

  =========================================================
*/
#include <iostream.h>
#include <stdio.h>

#define MAX_OP 5
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/'))?1:0
#define operands(c) ((c)>='a' && (c)<='z')?1:0
#define MAX_ITEM 100
typedef struct tagSTACK {
    int item [MAX_ITEM];
    int top;
} STACK;
STACK S;

char op[MAX_OP] = {'(', '+', '-', '*', '/'};
char prio[MAX_OP] = {0, 1, 1, 2, 2};
int op_value[26] = {10, 30, 6, 9, 8, 11, 12, 13, 7, 8, 22, 56, 77, 76,
                    55, 56, 43, 40, 13, 19, 18, 16, 46, 52, 61, 63
                   };

void    in_to_post(char*, char*);
void    Push(int);
void    Pop(int*);
int     post_evaluate(char*);
int     evaluate(char , int , int);
int     priority(int);

void main(void) {
    int i;
    char infix[MAX_ITEM];
    char postfix[MAX_ITEM];
    S.top = -1;
    cout << " 請輸入中序式, 例如 (a+b)*c-d/e : ";
    cin >> infix;
    in_to_post(infix, postfix);
    cout << " 中序式 => " << infix << "\n後序式=> " << postfix;
    cout << "\n若 a ~ z 的值分別是=> ";

    for (i = 0; i < 26; i++) {
        cout << op_value[i] << "  " ;
    }

    cout << "\n上式之結果= " << post_evaluate(postfix) << "\n";
}

void in_to_post(char* infix, char* postfix) {
    int i, j, element;
    char token;
    i = j = 0;

    while ((token = infix[i]) != '\0') {
        i = i + 1;

        if (operands(token)) {
            postfix [j++] = token;
        } else if (token == '(') {
            Push(token);
        } else if (token == ')')
            while (S.top >= 0) {
                Pop(&(int)element);

                if (element == '(') {
                    break;
                }

                postfix [j++] = element;
            }
        else if (operator(token)) {
            while (S.top >= 0) {
                element = S.item[S.top];

                if (priority(token) <= priority(element)) {
                    Pop(&(int)element);
                    postfix[j++] = element;
                } else {
                    break;
                }
            }

            Push(token);
        }
    }

    while (S.top >= 0) {
        Pop(& element);
        postfix[j++] = element;
    }

    postfix[j] = '\0';
}

void Push(int x) {
    if (S.top < MAX_ITEM - 1) {
        S.top++;
        S.item[S.top] = x;
    }
}
void Pop(int* x) {
    if (S.top >= 0) {
        *x = S.item[S.top];
        S.top--;
    }
}

int priority(int c) {
    int i = 0;

    for (; i < MAX_OP; i++)
        if (op[i] == c) {
            return (prio [i]);
        }

    return (-1);
}


int post_evaluate(char* postfix) {
    char token;
    int op1, op2, result, i = 0;

    while ((token = postfix[i]) != '\0') {
        i = i + 1;

        if (operands(token)) {
            Push(op_value[token - 'a']);
        } else if (operator(token)) {
            Pop(&op2);
            Pop(&op1);
            result = evaluate(token, op1, op2);
            Push(result);
        }
    }

    Pop(&result);
    return (result);
}
int evaluate(char optr, int op1, int op2) {
    int result;

    switch (optr) {
    case '+':
        result = op1 + op2;
        break;

    case '-':
        result = op1 - op2;
        break;

    case '*':
        result = op1 * op2;
        break;

    case '/':
        result = op1 / op2;
        break;
    }

    return (result);
}

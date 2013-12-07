/*******************************
    檔名:ch12_01.c
    功能:實現堆疊之推入與彈出
 *******************************/

#include <stdlib.h>
#include <stdio.h>
#define STACK_SIZE 100

void push(int item, int* stack, int max_size, int* top);
int  pop(int* stack, int* bottom, int* top);

void push(int item, int* stack, int max_size, int* top) {
    if (*top >= max_size - 1) {
        printf("STACK FULL!\n");
    } else {
        stack[++*top] = item;
    }
}

int pop(int* stack, int* bottom, int* top) {
    if (*bottom > *top) {
        printf("STACK EMPTY!\n");
        return NULL;
    } else {
        return stack[(*top)--];
    }
}

void main(void) {
    int stack[STACK_SIZE];
    int top = -1, bottom = 0, InputData = 10, i;
    printf("推入資料:");

    for (i = 1; i <= 5; i++) {
        InputData++;
        printf("%d\t", InputData);
        push(InputData, stack, STACK_SIZE, &top); /*推入資料的語法 */
    }

    printf("\n彈出資料:");

    for (i = 1; i <= 5; i++) {
        printf("%d\t", pop(stack, &bottom, &top)); /*彈出資料的語法*/
    }

    /* system("pause"); */
}

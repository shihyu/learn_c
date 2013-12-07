/*******************************
    檔名:ch12_02.c
    功能:實現佇列之加入與刪除
 *******************************/

#include <stdlib.h>
#include <stdio.h>
#define QUEUE_SIZE 100

void add_q(int item, int* queue, int max_size, int* rear);
int  delete_q(int* queue, int* front, int* rear);

void add_q(int item, int* queue, int max_size, int* rear) {
    if (*rear >= max_size - 1) {
        printf("QUEUE FULL!\n");
    } else {
        queue[++*rear] = item;
    }
}

int delete_q(int* queue, int* front, int* rear) {
    if (*front == *rear) {
        printf("QUEUE EMPTY!\n");
        return NULL;
    } else {
        return queue[++*front];
    }
}

void main(void) {
    int queue[QUEUE_SIZE];
    int rear = -1, front = -1, InputData = 10, i;
    printf("加入資料:");

    for (i = 1; i <= 5; i++) {
        InputData++;
        printf("%d\t", InputData);
        add_q(InputData, queue, QUEUE_SIZE, &rear); /*加入資料的語法 */
    }

    printf("\n取出資料:");

    for (i = 1; i <= 5; i++) {
        printf("%d\t", delete_q(queue, &front, &rear)); /*刪除(取出)資料的語法*/
    }

    /* system("pause"); */
}

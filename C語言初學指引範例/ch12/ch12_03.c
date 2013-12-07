/**********************************
    檔名:ch12_03.c
    功能:實現環狀佇列之加入與刪除
 **********************************/

#include <stdlib.h>
#include <stdio.h>
#define CQUEUE_SIZE 100

void add_cq(int item, int* cqueue, int max_size, int* front, int* rear);
int  delete_cq(int* cqueue, int max_size, int* front, int* rear);

void add_cq(int item, int* cqueue, int max_size, int* front, int* rear) {
    if (*front == (*rear + 1) % max_size) {
        printf("QUEUE FULL!\n");
    } else {
        *rear = (*rear + 1) % max_size;
        cqueue[*rear] = item;
    }
}

int delete_cq(int* cqueue, int max_size, int* front, int* rear) {
    if (*front == *rear) {
        printf("QUEUE EMPTY!\n");
        return NULL;
    } else {
        *front = (*front + 1) % max_size;
        return cqueue[*front];
    }
}

void main(void) {
    int cqueue[CQUEUE_SIZE];
    int rear = 0, front = 0, InputData = 10, i;
    printf("加入資料:");

    for (i = 1; i <= 5; i++) {
        InputData++;
        printf("%d\t", InputData);
        add_cq(InputData, cqueue, CQUEUE_SIZE, &front, &rear); /*加入資料的語法 */
    }

    printf("\n取出資料:");

    for (i = 1; i <= 5; i++) {
        printf("%d\t", delete_cq(cqueue, CQUEUE_SIZE, &front, &rear));
        /*刪除(取出)資料的語法*/
    }

    /* system("pause"); */
}

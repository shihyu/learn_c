/*
    顯示將空指標轉換為整數的值
*/

#include  <stdio.h>

int main(void) {
    printf("空指標的內容為%lu。\n", (unsigned long)(void*)NULL);

    system("PAUSE");
    return (0);
}

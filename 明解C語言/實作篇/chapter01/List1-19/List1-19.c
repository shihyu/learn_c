/*
    將擁有自動記憶域期間的陣列初始化
*/

#include  <stdio.h>

int  vx[3] = {1, 2, 3};                /*靜態*/

int main(void) {
    int  i;
    int  ma[3] = {1, 2, 3};            /*自動 : 在K&R中不可使用*/
    static int  ms[3] = {1, 2, 3};     /*靜態*/

    for (i = 0; i < 3; i++)
        printf("vx[%d] = %d  ma[%d] = %d  ms[%d] = %d\n",
               i, vx[i], i, ma[i], i, ms[i]);

    system("PAUSE");
    return (0);
}

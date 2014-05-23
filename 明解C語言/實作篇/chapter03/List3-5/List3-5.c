/*
    家族人數的增減(錯誤版)
*/

#include  <stdio.h>

/*--- 人數增加 ---*/
void fueta(int num) {
    ++num;              /* 將num的值加1 */
}

/*--- 人數減少 ---*/
void hetta(int num) {
    --num;              /* 將num的值減1 */
}

int main(void) {
    int  x = 5;         /* x家有5人 */
    int  y = 3;         /* y家有3人 */

    fueta(x);           /* x家增加1人*/
    hetta(y);           /* y家減少1人*/

    printf("x家的構成人數=%d\n", x);
    printf("y家的構成人數=%d\n", y);

    system("PAUSE");
    return (0);
}

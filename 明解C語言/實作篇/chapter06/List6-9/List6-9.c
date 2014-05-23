/*
    將整數值加起來的值顯示(K&R風格)
*/

#include  <stdio.h>

/*--- 求出x與y的和 ---*/
int add(x, y)
int x, y;
{
    return (x + y);
}

main() {
    int  x, y;

    printf("請輸入整數值 : ");
    scanf("%d", &x);
    printf("請輸入整數值 : ");
    scanf("%d", &y);

    printf("兩數的和為%d。\n", add(x, y));

    system("PAUSE");
}

/*
函式引數與指標
*/

#include  <stdio.h>

/*---lily（拉長其不足180㎝的身高）---*/
void lily(int* height) {
    if (*height < 180) {
        *height = 180;
    }
}

int main(void) {
    int   soong = 178;      /* 宋小瑜的身高 */
    int   chang = 175;      /* 張小雄的身高 */
    int   chen  = 165;      /* 陳小扁的身高 */
    int   lin   = 179;      /* 林小雄的身高 */

    lily(&lin);

    printf("宋小瑜的身高：%d\n", soong);
    printf("張小雄的身高：%d\n", chang);
    printf("陳小扁的身高：%d\n", chen);
    printf("林小雄的身高：%d\n", lin);

    return (0);
}

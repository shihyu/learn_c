/*
    有著同一前頭順序的共同空間的使用例
*/

#include  <stdio.h>

/*--- 動物(狗/猴子)共同空間 ---*/
typedef union {
    struct {
        int     type;       /* 種類 */
    } code;

    struct {
        int     type;       /* 1:狗 */
        char*    name;      /* 名稱 */
    } dog;

    struct {
        int     type;       /* 2:猴子 */
        double  weight;     /* 體重 */
    } monkey;
} Animal;

/*--- 將動物的資料依照種別來顯示 ---*/
void print_animal(Animal x) {
    switch (x.code.type) {
    case 1:
        printf("狗。名稱為%s。\n", x.dog.name);
        break;

    case 2:
        printf("猴子。體重為%.1f。\n", x.monkey.weight);
        break;
    }
}

int main(void) {
    Animal  a, b;
    Animal*  p;

    a.dog.type = 1;             /* a是狗， */
    a.dog.name = "Taro";        /* 名稱為"Taro" */

    b.monkey.type = 2;          /* b是猴子   */
    b.monkey.weight = 25.8;     /* 體重為25.8kg  */

    p = &a;
    print_animal(*p);           /* 顯示a */

    p = &b;
    print_animal(*p);           /* 顯示b */

    system("PAUSE");
    return (0);
}

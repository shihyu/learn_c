/*
驗證識別碼的有效範圍
*/

#include  <stdio.h>

int   x = 700;      /* 檔案的有效範圍 */

void print_x(void) {
    printf("x = %d\n", x);
}

int main(void) {
    int   i;
    int   x = 800;               /*資料段的有效範圍 */

    print_x();

    printf("x = %d\n", x);

    for (i = 0; i < 5; i++) {
        int    x = i * 100;     /*資料段的有效範圍 */
        printf("x = %d\n", x);
    }

    printf("x = %d\n", x);

    return (0);
}

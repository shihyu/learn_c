/*
    將二進位檔使用純字元模式來開啟
*/

#include  <stdio.h>

#define MAX     10

int main(void) {
    FILE*  fp;
    int   i, x, y;
    int   a[MAX];

    /*--- 將陣列a與變數x，y的值從檔案讀出 ---*/
    if ((fp = fopen("TEMP", "r")) != NULL) {
        fread(a, sizeof(int), MAX, fp);      /* 將a讀出 */
        fread(&x, sizeof(int),   1, fp);        /* 將x讀出 */
        fread(&y, sizeof(int),   1, fp);        /* 將y讀出 */

        fclose(fp);

        /*--- 將讀入的值顯示 ---*/
        for (i = 0; i < MAX; i++) {
            printf("a[%d] = %d\n", i, a[i]);
        }

        printf("x = %d\n", x);
        printf("y = %d\n", y);
    }

    system("PAUSE");
    return (0);
}

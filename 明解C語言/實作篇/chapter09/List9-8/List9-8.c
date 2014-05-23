/*
    二進位檔的輸入輸出範例
*/

#include  <stdio.h>

#define MAX     10

int main(void) {
    FILE*  fp;
    int   i;
    int   x = 2573;
    int   y = 12609;
    int   a[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    if ((fp = fopen("TEMP", "wb")) != NULL) {
        /*--- 將陣列a與變數x，y的值寫入至檔案 ---*/
        fwrite(a, sizeof(int), MAX, fp);         /* 將a寫入 */
        fwrite(&x, sizeof(int),   1, fp);       /* 將x寫入 */
        fwrite(&y, sizeof(int),   1, fp);       /* 將y寫入 */
        fclose(fp);

        x = y = 0;

        for (i = 0; i < MAX; i++) {
            a[i] = 0;
        }

        /*--- 將陣列a與變數x，y的值從檔案讀出 ---*/
        if ((fp = fopen("TEMP", "rb")) != NULL) {
            fread(a, sizeof(int), MAX, fp);  /* 將a讀出 */
            fread(&x, sizeof(int),   1, fp);    /* 將x讀出 */
            fread(&y, sizeof(int),   1, fp);    /* 將y讀出 */
            fclose(fp);

            /*--- 將讀出後的值顯示 ---*/
            for (i = 0; i < MAX; i++) {
                printf("a[%d] = %d\n", i, a[i]);
            }

            printf("x = %d\n", x);
            printf("y = %d\n", y);
        }
    }

    system("PAUSE");
    return (0);
}


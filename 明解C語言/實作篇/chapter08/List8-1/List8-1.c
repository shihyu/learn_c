/*
    從檔案讀入項目來顯示(讀者Y的程式)
*/

#include  <stdio.h>

FILE*  fp;
char*  field = "%s\t%s\t%s\t%s\t%s";
char  a[9];     /* 下單日 */
char  b[7];     /* 商品種類 */
char  c[9];     /* 交貨日 */
char  d[10];    /* 金額 */
char  e[8];     /* 單價 */

int main(void) {
    fp = fopen("data1.txt", "r");

    while (fscanf(fp, field, a, b, c, d, e) != EOF) {
        printf(field, a, b, c, d, e);
        putchar('\n');
    }

    fclose(fp);

    system("PAUSE");
    return (0);
}

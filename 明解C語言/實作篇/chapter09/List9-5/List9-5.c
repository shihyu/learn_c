/*
    對純文字檔寫入整數值123
*/

#include  <stdio.h>

int main(void) {
    FILE*  fp;
    int   no = 123;

    fp = fopen("TESTA", "w");

    if (fp != NULL) {
        fprintf(fp, "%d", no);
        fclose(fp);
    }

    system("PAUSE");
    return (0);
}

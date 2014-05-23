/*
    對二進檔寫入整數值123
*/

#include  <stdio.h>

int main(void) {
    FILE*  fp;
    int   no = 123;

    fp = fopen("TESTB", "wb");

    if (fp != NULL) {
        fwrite(&no, sizeof(int), 1, fp);
        fclose(fp);
    }

    return (0);
}

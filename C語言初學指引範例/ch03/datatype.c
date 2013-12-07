/****************************************
    檔名:datatype.c
    功能:測試資料型態所佔記憶體空間數量
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    printf("在此作業系統使用該編譯器的資料型態記憶體分佈如下:\n");
    printf("int          資料型態佔%2d個位元組\n", sizeof(int));
    printf("float        資料型態佔%2d個位元組\n", sizeof(float));
    printf("double       資料型態佔%2d個位元組\n", sizeof(double));
    printf("short int    資料型態佔%2d個位元組\n", sizeof(short int));
    printf("long int     資料型態佔%2d個位元組\n", sizeof(long int));
    printf("unsigned int 資料型態佔%2d個位元組\n", sizeof(unsigned int));
    printf("long double  資料型態佔%2d個位元組\n", sizeof(long double));
    system("pause");
}

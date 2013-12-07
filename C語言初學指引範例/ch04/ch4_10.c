/***************************
    檔名:ch4_10.c
    功能:scanf()格式化符號
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch1;
    int data1;
    float f1;
    char* str1;
    str1 = (char*)malloc(sizeof(char));
    printf("請輸入字元,字串,整數,浮點數(使用Enter加以間隔)\n");
    scanf("%c%s%d%f", &ch1, str1, &data1, &f1);
    printf("======正在輸出=======\n");
    printf("ch1=%c\n", ch1);
    printf("str1=%s\n", str1);
    printf("data1=%d\n", data1);
    printf("f1=%f\n", f1);
    /*  system("pause");  */
    system("pause");
    return 0;
}

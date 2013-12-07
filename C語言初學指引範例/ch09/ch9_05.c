/*******************************
    檔名:ch9_05.c
    功能:auto變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    auto int var2 = 30;
    printf("區段外var2 = %d\n", var2);
    /* printf("區段外var3 = %d\n",var3); */
    {
        auto int var3 = 40;
        printf("區段內var3 = %d\n", var3);
        printf("區段內var2 = %d\n", var2);
    }
    /* printf("區段外var3 = %d\n",var3); */
}

void main(void) {
    auto int var1 = 10;
    printf("區段外var1 = %d\n", var1);
    {
        auto int var1 = 20;
        printf("區段內var1 = %d\n", var1);
    }
    func1();
    /*  system("pause");  */
}

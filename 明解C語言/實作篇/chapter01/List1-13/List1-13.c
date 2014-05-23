/*
有著自動記憶域期間的物件之初始化
*/

#include <math.h>
#include <stdio.h>

void func(int no) {
    register int i;
    auto int x = 100;

    printf("x = %d\n", x);

    for (i = 0; i < no; i++) {
        double x = sin((double)i / no);
        printf("x = %f\n", x);
    }

    printf("x = %d\n", x);
}

int main(void) {
    func(10);

    system("PAUSE");
    return (0);
}

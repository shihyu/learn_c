#include <stdio.h>

int main(int argc, char* argv[]) {
    int a = 100;
    int b = 200;
    int* ptr;  // 宣個 ptr 為 int* 型態指標

    printf("a=%d, address=%p\n", a, &a);
    printf("b=%d, address=%p\n", b, &b);

    ptr = &a; // ptr 指標指向a變數位址
    *ptr = 10; // *ptr 相當於取a位址的內容改為10
    printf("a=%d, address=%p\n", a, &a);

    ptr = &b; // ptr 指標指向a變數位址
    *ptr = 20; // *ptr 相當於取b位址的內容改為20
    printf("b=%d, address=%p\n", b, &b);
    return 0;
}

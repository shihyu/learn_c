#include <stdio.h>

void swap(int* p1, int* p2) {
    printf("swap[+] a=%d, b=%d p1=%p p2=%p\n", *p1, *p2, p1, p2);
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("swap[-] a=%d, b=%d p1=%p p2=%p\n", *p1, *p2, p1, p2);
}

int main(int argc, char* argv[]) {
    int a, b;
    a = 50;
    b = 100;
    printf("main [+]a=%d, b=%d a address=%p b address=%p\n", a, b, &a, &b);
    swap(&a, &b);
    printf("main [-]a=%d, b=%d a address=%p b address=%p\n", a, b, &a, &b);
    return 0;
}

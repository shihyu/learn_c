
#include  <stdio.h>

#define para    10

void func(int para);

int main(void) {
    func(para);

    return (0);
}

void func(int no) {
    while (--no) {
        printf("%d\n", no);
    }
}


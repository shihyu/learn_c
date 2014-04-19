#include <stdio.h>

// decla
void test();
int test1();
float test2();
double test3();
char test4();
char *test5();
int *test6();


int g;

int sum(int a, int b) {
    return a + b;
}

int main(int argc, char *argv[]) {
    printf("%d\n", sum(10, 50));
    test();
    printf("%d\n", g);
    return 0;
}


// implement
void test() {
    g = 100;
}

int test1() {
    return 0;
}

float test2() {
    return 0;
}

double test3() {
    return 0.0f;
}

char test4() {
    return 0;
}

char *test5() {
    return 0;
}

int *test6() {
    return 0;
}

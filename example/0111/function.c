#include <stdio.h>

void test(void);
int test1(void);
int test2(int);
int test3(int, int);
float test4(float, float);
void test5(int a[]);  // void test5(int *a)
void test6(float a[]);  // void test5(int *a)
void *my_malloc(size_t size);

int main(int argc, char *argv[]) {
    return 0;
}

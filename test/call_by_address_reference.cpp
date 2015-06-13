#include <iostream>
using namespace std;

// call_by_value 兩塊不同記憶體 , 只是單純 assign 值
void call_by_value(int a, int b) {
    int temp;

    printf("call_by_value a=%d,b=%d &a=%p, &b=%p\n",a,b,&a,&b);

    temp = a;
    a = b;
    b = temp;

    printf("call_by_value a=%d,b=%d &a=%p, &b=%p\n",a,b,&a,&b);
}

void call_by_address(int *p) 
{
    int call_by_address_a = 99;

    printf("call_by_address_a=%d\n", call_by_address_a);
    printf("*p=%d\n", *p);
    *p = 100;

    p = &call_by_address_a;
    *p = 40;

    printf("%d\n", call_by_address_a);

    printf("%p\n", p);
}

void call_by_refence(int &p) 
{
    printf("%d\n",p);
    p = 200;
    printf("%p\n", &p);
}

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 30;

    printf("%p\n", &a);

    call_by_address(&a);
    printf("%d\n", a);



    call_by_refence(a);
    printf("%d\n", a);

    printf("main a=%d,b=%d &a=%p, &b=%p\n",a,b,&a,&b);
    call_by_value(a, b);
    printf("main a=%d,b=%d &a=%p, &b=%p\n",a,b,&a,&b);

    return 0;
}

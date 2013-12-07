#include <stdio.h>
#include <stdlib.h>

union u_member {
    short int id;
    int income;
};

struct s_member {
    short int id;
    int income;
};

int main(void) {
    u_member John;
    s_member Mary;
    John.income  = 0x00000000;
    John.income  = 0x66666666;
    John.id      = 0x0010;
    Mary.income  = 0x00000000;
    Mary.income  = 0x55555555;
    Mary.id      = 0x0011;
    printf("John.income  =%X\n", John.income);
    printf("John.id      =%X\n", John.id);
    printf("Mary.phone   =%X\n", Mary.income);
    printf("Mary.id      =%X\n", Mary.id);
    system("pause");
    return 0;
}

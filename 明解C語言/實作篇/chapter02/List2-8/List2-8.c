/*
  確認將-1轉換成unsigned int型之後的結果會變成UINT_MAX
*/

#include  <stdio.h>
#include  <limits.h>

int main(void) {
    printf("(unsinged)-1 = %u\n", (unsigned) - 1);
    printf("UINT_MAX     = %u\n", UINT_MAX);

    system("PAUSE");
    return (0);
}

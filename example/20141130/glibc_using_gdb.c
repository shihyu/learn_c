/* gcc -g glibc_using_gdb.c -o glibc_using_gdb */

#include <stdio.h>                                                        
 
int main(void){
    int num;

    puts("Please enter a num: ");
    scanf("%d", &num);

    printf("%x\n",num);
 
    if (num == 0)
        puts("The number you entered is 0 ");
    else if (num >= 0)
        puts("The number you entered is Positive ");
    else if (num <= 0 )
        puts("The number you entered is Negative ");
    else
        puts("Unexpected Errors!");
 
    return 0;
}

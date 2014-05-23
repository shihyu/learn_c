/*
    同樣拼字的字串字面值
*/

#include  <stdio.h>

int main(void) {
    char*  s1 = "ABCD";         /* s1是指"ABCD" */
    char*  s2 = "ABCD";         /* s2是指"ABCD" */

    *s1 = 'Z';                  /* 將s1所指的字元改寫 */

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    system("PAUSE");
    return (0);
}

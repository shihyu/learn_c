/*
    進行字串的複製
*/

#include  <stdio.h>

/*--- 將字串f複製到t ---*/
void scp1(char* f, char* t) {
    while (*f != '\0') {
        *t = *f;
        f++;
        t++;
    }

    *t = '\0';
}

/*--- 將字串f複製到t(有bug) ---*/
void scp2(char* f, char* t) {
    do {
        *t++ = *f++;
    } while (*f);
}

int main(void) {
    char  astr[8] = "ABC";
    char  bstr[8] = "XXXXXXX";
    char  cstr[8] = "YYYYYYY";

    scp1(astr, bstr);   /* 在函式scp1中，將astr複製到bstr */
    scp2(astr, cstr);   /* 在函式scp2中，將astr複製到cstr */

    printf("astr = %s\n", astr);
    printf("bstr = %s\n", bstr);
    printf("cstr = %s\n", cstr);

    system("PAUSE");
    return (0);
}

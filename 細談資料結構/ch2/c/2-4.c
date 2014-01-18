/*=========================================================
    String


  =========================================================
*/

#include <stdio.h>
#include <conio.h>
#define MAX_LEN 255

int strlen(char []);
void    strcpy1(char [], char []);
void    strcpy2(char [], char []);
void    strcpy3(char [], char []);
int strcmp(char [], char []);
void    substr(char [], char [], int , int);


void main(void) {
    char S1[MAX_LEN], S2[MAX_LEN];
    int len, result, start;
    /* Test string length*/
    printf(" Please Input a string =>");
    gets(S1);
    len = strlen(S1);
    printf("\n The length of string '%s' is %d character(s)", S1, len);
    /* Test string length 1 */
    printf("\n Please Input a string =>");
    gets(S1);//printf("\n The string1 is %s ",S1);
    strcpy1(S2, S1);
    printf("\n The clone string is %s ", S2);
    /* Test string length 2*/
    printf("\n Please Input a string =>");
    gets(S1);
    strcpy2(S2, S1);
    printf("\n The clone string is %s ", S2);
    /* Test string length 3 */
    printf("\n Please Input a string =>");
    gets(S1);
    strcpy3(S2, S1);
    printf("\n The clone string is %s ", S2);
    /* Test string comparison */
    printf("\n Please Input string 1 =>");
    gets(S1);
    printf("\n Please Input string 2 =>");
    gets(S2);
    result = strcmp(S1, S2);

    switch (result) {
    case 0:
        printf("\n  '%s' =  '%s'", S1, S2);
        break;

    case 1:
        printf("\n  '%s' <  '%s'", S1, S2);
        break;

    case -1:
        printf("\n  '%s' >  '%s'", S1, S2);
        break;
    }

    printf("\n");
    /* Test sub string */
    printf("\n Please Input string =>");
    gets(S1);
    printf("\n Please Input start position and length like 5 9 =>");
    scanf("%d %d", &start, &len);
    substr(S2, S1, start, len);
    printf("\n  Substring is '%s' \n", S2);
}

int strlen(char S[]) {
    int    len ;

    for (len = 0; S[len] != '\0'; len++) ;

    return (len) ;
}

void    strcpy1(char S1[], char S2[]) {
    int  i ;

    for (i = 0; S2[i] != '\0'; i++) {
        S1[i] = S2[i] ;
    }

    S1[i] = '\0' ;
}
void    strcpy2(char S1[], char S2[]) {
    int   i ;

    for (i = 0; (S1[i] = S2[i]) != '\0' ;  i++) ;
}
void    strcpy3(char S1[], char S2[]) {
    for (; (*S1 = *S2) != '\0' ; S1++, S2++) ;
}

int   strcmp(char S1[], char S2[]) {
    int   i ;

    for (i = 0; S1[i] == S2[i]; i++)
        if (S1[i] == '\0' && S2[i] == '\0') {
            return 0;
        }

    if (S1[i] > S2[i]) {
        return (-1) ;
    } else {
        return (1) ;
    }
}
void    substr(char S1[], char S[], int i, int n) {
    int  len, end, j , k ;
    len = strlen(S) ;
    end = i + n ;

    if ((end > len) || (n == 0)) {
        end = len ;
    }

    for (j = i, k = 0 ; j < end ; j++, k++) {
        S1[k] = S[j];
    }

    S1[k] = '\0' ;
}

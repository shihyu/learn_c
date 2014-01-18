/*=========================================================
    String
  =========================================================
*/

#include <iostream.h>
#define MAX_LEN 255

int     strlen1(char []);
void    strcpy1(char [], char []);
void    strcpy2(char [], char []);
void    strcpy3(char [], char []);
int     strcmp1(char [], char []);
void    substr1(char [], char [], int , int);

void main(void) {
    char S1[MAX_LEN], S2[MAX_LEN];
    int len, result, start;
    /* Test string length*/
    cout << " Please Input a string => ";
    cin.getline(S1, MAX_LEN);
    len = strlen1(S1);
    cout << "\n The length of string  '" << S1 << "' is " << len << " character(s) \n";
    /* Test string length 1 */
    cout << "\n Please Input a string => ";
    cin.getline(S1, MAX_LEN);
    strcpy1(S2, S1);
    cout << "\n The clone string is  " << S2;
    /* Test string length 2*/
    cout << "\n Please Input a string => ";
    cin.getline(S1, MAX_LEN);
    strcpy2(S2, S1);
    cout << "\n The clone string is  " << S2;
    /* Test string length 3 */
    cout << "\n Please Input a string => ";
    cin.getline(S1, MAX_LEN);
    strcpy3(S2, S1);
    cout << "\n The clone string is  " << S2;
    /* Test string comparison */
    cout << "\n Please Input string 1 =>";
    cin.getline(S1, MAX_LEN);
    cout << "\n Please Input string 2 =>";
    cin.getline(S2, MAX_LEN);
    result = strcmp1(S1, S2);

    switch (result) {
    case 0:
        cout << "\n "  << S1 << " = " << S2 ;
        break;

    case 1:
        cout << "\n "  << S1 << " < " << S2;
        break;

    case -1:
        cout << "\n "  << S1 << " > " << S2;
        break;
    }

    cout << "\n";
    /* Test sub string */
    cout << "\n Please Input string => ";
    cin.getline(S1, MAX_LEN);
    cout << "\n Please Input start position and length like 5 9 => ";
    cin >> start >> len;
    substr1(S2, S1, start, len);
    cout << "\n Substring is " << S2 << "\n";
}

int strlen1(char S[]) {
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

int   strcmp1(char S1[], char S2[]) {
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
void    substr1(char S1[], char S[], int i, int n) {
    int  len, end, j , k ;
    len = strlen1(S) ;
    end = i + n ;

    if ((end > len) || (n == 0)) {
        end = len ;
    }

    for (j = i, k = 0 ; j < end ; j++, k++) {
        S1[k] = S[j];
    }

    S1[k] = '\0' ;
}

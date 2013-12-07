/**********************************
    檔名:ch3_10.c
    功能:atoi、atof、atol型態轉換
 **********************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char* string;
    double d;
    int i;
    long l;
    string = "1234567";
    l = atol(string);
    printf("%s \t轉換為long=>%d\n", string, l);
    string = "12345jhchen";
    l = atol(string);
    printf("%s \t轉換為long=>%d\n", string, l);
    string = "1234567persons";
    i = atoi(string);
    printf("%s \t轉換為int=>%d\n", string, i);
    string = "-1234.56E-7";
    d = atof(string);
    printf("%s \t轉換為double=>%.9f\n", string, d);
    system("pause");
}

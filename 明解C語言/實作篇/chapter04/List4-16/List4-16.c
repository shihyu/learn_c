/*
    進行字串複製的函式的實現例
*/

/*--- 複製字串(1) ---*/
char* scpy1(char* d, const char* s) {
    int  i = 0;

    while ((d[i] = s[i]) != '\0') {
        i++;
    }

    return (d);
}

/*--- 複製字串(2) ---*/
char* scpy2(char* d, const char* s) {
    char*  p = d;

    while ((*d = *s) != '\0') {
        d++;
        s++;
    }

    return (p);
}

/*--- 複製字串(3) ---*/
char* scpy3(char* d, const char* s) {
    char*  p = d;

    while ((*d++ = *s++) != '\0')
        ;

    return (p);
}

/*--- 複製字串(4) ---*/
char* scpy4(char* d, const char* s) {
    char*  p = d;

    while (*d++ = *s++)
        ;

    system("PAUSE");
    return (0);
}

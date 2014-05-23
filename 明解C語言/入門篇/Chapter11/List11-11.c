/*---把字串s2連接到s1---*/
char* strcat(char* s1, const char* s2) {
    char* tmp = s1;

    while (*s1) {
        s1++;    /* 將s1移前到末端 */
    }

    while (*s1++ = *s2++) ;      /* 將'\0'出現之前的S1複製到S2 */

    return (tmp);
}

/*---把字串s2連接到s1，但最多n個字元---*/
char* strncat(char* s1, const char* s2, size_t n) {
    char* tmp = s1;

    while (*s1) {
        s1++;    /*將 s1移前到末端 */
    }

    while (n--)
        if (!(*s1++ = *s2++)) {
            break;    /* 若中途出現 '\0'則結束 */
        }

    *s1 = '\0';                            /* 在s1的最後面加上'\0' */
    return (tmp);
}

/*---將字串s2複製到s1---*/
char* strcpy(char* s1, const char* s2) {
    char* tmp = s1;

    while (*s1++ = *s2++)
        ;

    return (tmp);
}

/*---將字串s2複製到s1，但最多n個字元---*/
char* strncpy(char* s1, const char* s2, size_t n) {
    char* tmp = s1;

    while (n) {
        if (!(*s1++ = *s2++)) {
            break;    /*如遇到 '\0'，則結束 */
        }

        n--;
    }

    while (n--) {
        *s1++ = '\0';    /* 其餘的部份以'\0'填滿 */
    }

    return (tmp);
}

/*---比較字串s1與s2---*/
int strcmp(const char* s1, const char* s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            return (0);    /* 相等 */
        }

        s1++;
        s2++;
    }

    return ((unsigned char) * s1 - (unsigned char) * s2);
}

/*---比較字串s1與s2的前n個字元---*/
int strncmp(const char* s1, const char* s2, size_t n) {
    while (n && *s1 && *s2) {
        if (*s1 != *s2) {                   /* 不相等 */
            return ((unsigned char) * s1 - (unsigned char) * s2);
        }

        s1++;
        s2++;
        n--;
    }

    if (!n) {
        return (0);    /* 相等 */
    }

    if (*s1) {
        return (1);    /* s1 > s2 */
    }

    return (-1);                             /* s1 < s2 */
}

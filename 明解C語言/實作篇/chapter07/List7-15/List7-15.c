/*
    化學物質資料庫字的結構定義(一部分)
*/

typedef struct {
    /* …(中略)… */
    char  formA[16];        /* 成分A的分子式 */
    char  nameA[65];        /* 成分A的物質名 */
    char  formB[16];        /* 成分B的分子式 */
    char  nameB[65];        /* 成分B的物質名 */
    /* …(中略)… */
} Rec;

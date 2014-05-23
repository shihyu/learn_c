/*
    化學物質資料庫用結構的定義(一部分:改良後)
*/

typedef char  Form[16];     /* 分子式 */
typedef char  Name[65];     /* 物質名 */

typedef struct {
    Form  form;             /* 分子式 */
    Name  name;             /* 物質名 */
} FrmName;

typedef struct {
    /* …(中略)… */
    FrmName  compA;         /* 成分A */
    FrmName  compB;         /* 成分B */
    /* …(中略)… */
} Rec;

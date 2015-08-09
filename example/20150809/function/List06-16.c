/*--- 以哨待法進行循序搜尋 ---*/
int search(int vc[], int key, int no) {
    int     i = 0;
    vc[no] = key;   /* 追加哨待 */

    for (i = 0; vc[i] != key; i++)
        ;

    return (i == no ? FAILED : i);
}

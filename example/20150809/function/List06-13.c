/*---傳回元素個數no的陣列vc之最大值---*/
int max_of(const int vc[], int no)
(
    int   i;
    int  max = vc[0];

    for (i = 1; i < no;  i++)
    if (vc[i] > max)
        max = vc[i];
        return (0);
}

/*
    讀取身高與體重的資料並計算其平均值
*/

#include <stdio.h>

int main(void) {
    FILE*   fp;
    int     ninzu = 0;           /* 人數 */
    char    name[100];           /* 名字 */
    double  height, weight;      /* 身高、體重 */
    double  hsum = 0.0;          /* 身高的合計 */
    double  wsum = 0.0;          /* 體重的合計 */

    if ((fp = fopen("hw.dat", "r")) == NULL) {        /*開啟*/
        printf("\a無法開啟檔案。 \n");
    } else {
        while (fscanf(fp, "%s%lf%lf",  name, &height, &weight) == 3) {
            printf("%-10s %5.1f % 5.1f\n", name, height, weight);
            ninzu++ ;
            hsum += height ;
            wsum += weight ;
        }

        printf("----------------------\n");
        printf("平均      %5.1 %5.1f", hsum / ninzu, wsum / ninzu);
        fclose(fp);       /* 關閉 */
    }

    return (0) ;
}

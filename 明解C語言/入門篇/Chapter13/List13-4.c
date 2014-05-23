/*
     顯示上次執行程式的日期與時間
*/

#include <time.h>
#include <stdio.h>

char date_file[ ] = "datetime.dat";           /* 檔案名稱 */
/*---取得並顯示上次執行的日期與時間---*/
void get_date(void) {
    FILE*   fp;

    if ((fp = fopen(date_file, "r")) == NULL) {            /* 開啟 */
        printf("這是第一次執行這個程式。\n") ;
    } else {
        int  year, month, day, h, m, s;

        fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
        printf("上次執行是在%d年%d月%d日%d時%d分%d秒。\n",
               year, month, day, h, m, s);
        fclose(fp);                                                /* 關閉 */
    }
}

/*---寫入這次執行的日期與時間 ---*/
void put_date(void) {
    FILE*  fp;
    time_t     t;
    struct tm*  local;

    time(&t);
    local = localtime(&t);

    if ((fp = fopen(date_file, "w")) == NULL) {             /* 開啟 */
        printf("\a無法開啟檔案。\n");
    } else {
        fprintf(fp, "%d %d %d %d %d %d \n",
                local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
                local->tm_hour,       local->tm_min,    local->tm_sec) ;
        fclose(fp) ;                                          /* 關閉 */
    }
}

int main(void) {
    get_date() ;          /* 取得並顯示上次執行的日期與時間 */
    put_date() ;          /* 寫入這次執行的日期與時間 */
    return (0) ;
}

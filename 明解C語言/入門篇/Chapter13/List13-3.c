/*
   將執行程式的時間與日期紀錄在檔案中
*/

#include <time.h>
#include <stdio.h>

int main(void) {
    FILE*  fp;
    time_t      t;
    struct tm*   local;

    time(&t);
    local = localtime(&t);

    if ((fp = fopen("dt_dat", "w")) == NULL) {     /* 開啟 */
        printf("\a無法開啟檔案 \n");
    } else {
        printf("現在的日期、時間已紀錄完畢");
        fprintf(fp, "%d %d %d %d %d %d\n",
                local->tm_year + 1900,  local->tm_mon + 1,   local->tm_mday,
                local->tm_hour,        local->tm_min,       local->tm_sec);
        fclose(fp);                              /* 關閉 */
    }

    return (0) ;
}

/*
輸出今天的日期
*/

#include  <time.h>
#include  <stdio.h>

void put_date(void) {
    time_t     current;
    struct tm*                 local;
    char  wday_name[][3] = { "日", "一", "二", "三", "四", "五", "六" };

    time(&current);                    /* 取得現在時刻 */
    local = localtime(&current);       /* 換成當地的時間架構 */
    printf("%4d年%02d月%02d日(%s)", local->tm_year + 1900   /* 年 */
           , local->tm_mon + 1                     /* 月 */
           , local->tm_mday                        /* 日 */
           , wday_name[local->tm_wday]             /*星期*/
          );
}

int main(void) {
    printf("今天是");
    put_date();
    printf("。");

    return (0);
}

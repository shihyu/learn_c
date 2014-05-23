/*
    觀察堆疊溢位用的程式
*/

int  z[8000];           /* 靜態儲存區間 */

void func(void) {
    int x[8000];        /* 自動儲存區間 */
}

int main(void) {
    int a[8000];        /* 自動儲存區間 */

    func();

    return (0);
}

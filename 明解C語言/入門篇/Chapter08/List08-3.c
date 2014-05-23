/*
發出警告音同時輸出結果的巨集（這個是錯誤的示範, 不能編譯與執行）
*/

#include  <stdio.h>

#define putsa(str)  { putchar('\a'); puts(str); }

int main(void) {
    int  na;

    printf("請輸入一個整數：") ;
    scanf("%d", &na);

    if (na) {
        putsa("該數非0");
    } else {
        putsa("該數為0");
    }

    return (0);
}

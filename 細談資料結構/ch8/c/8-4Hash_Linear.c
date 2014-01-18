/*=========================================================

       8-4節  雜湊法: 解決碰撞的方法: 線性探測法

          hash_init()           啟始表格函式
          hash_insert()         安排資料函式
          hash()                雜湊函數
          hash_srch()           在以雜湊編排過的表格中搜尋
          is_full()             測示陣列空間是否已滿
          PrintTable()          印出雜湊表格
          table[m]              雜湊表格陣列
          m                     表格大小

  =========================================================
*/

#include <stdio.h>

#define         m       13
#define         EMPTY   -32768

int table[m];
int hash(int);
void hash_init(void);
void hash_insert(int);
int  hash_srch(int);
int  is_full(void);
void PrintTable(int []);

void main(void) {
    int in_data, addr;
    int choose, loopflag = 1;
    hash_init();

    while (loopflag) {
        printf("雜湊表內容(e表空格):");
        PrintTable(table);
        printf("\n(1)加入資料\n(2)搜尋資料\n(0)結束=>");
        scanf("%d", &choose);

        switch (choose) {
        case 0:
            loopflag = 0;                      /*結束程式*/
            break;

        case 1:
            if (is_full()) {
                printf("陣列已滿\n");
            } else {
                printf("請輸入欲加入之資料=>");
                scanf("%d", &in_data);
                hash_insert(in_data);
            }

            break;

        case 2:
            printf("請輸入欲搜尋之資料=>");
            scanf("%d", &in_data);

            if ((addr = hash_srch(in_data)) == -1) {
                printf("找不到資料\n");
            } else {
                printf("資料 %d 於表格第 %d 個位置\n", in_data, addr);
            }

            break;

        default:
            printf("Wrong Input !!!! \n");
        }
    }
}

/*雜湊函數*/
int hash(int key) {
    return (key % m);
}


void hash_init(void) {
    int i;

    for (i = 0; i < m; i++) {
        table[i] = EMPTY;    /*代表空格*/
    }
}


void hash_insert(int key) {
    int addr = hash(key);       /*呼叫雜湊函數得位置*/

    while (table[addr] != EMPTY) {
        addr = (addr + 1) % m;    /*才能再從table[0]開始*/
    }

    table[addr] = key;
}

/*搜尋鍵值為key,成功傳回表格位置,失敗傳回-1*/
int hash_srch(int key) {
    int addr;
    addr = hash(key);

    while (table[addr] != key) {
        addr = (addr + 1) % m;

        if (table[addr] == EMPTY || addr == hash(key)) { /*若是空格或又回到原點*/
            return (-1);    /*則傳回失敗*/
        }
    }

    return (addr);
}

int is_full(void) {
    int i;

    for (i = 0; i < m; i++)
        if (table[i] == EMPTY) {
            return (0);
        }

    return (1);
}

void PrintTable(int a[]) {
    int i;

    for (i = 0; i < m; i++)
        if (a[i] != EMPTY) {
            printf("%d ", a[i]);
        } else {
            printf("e ");
        }
}

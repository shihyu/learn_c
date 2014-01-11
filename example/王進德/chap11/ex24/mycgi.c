#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name_value_set {
    char name[250];   // 表單欄位名最長為250個字元
    char value[250];  // 表單欄位值最長為250個字元
} nv_set;

void makespace(char* s);
char* split(char* s, char stop);
char* convert(char* s);
int hexa(char c);

/* 將表單資料解碼,結果存入nv陣列中 */
int get_input(nv_set* nv) {
    char*  method;
    char*  my_data = 0;
    char*  tmp_ptr, *tmp;
    int   data_len;
    int   i;
    /* 表單以GET方法傳送資料 */
    method = getenv("REQUEST_METHOD");

    if (strcmp(method, "GET") == 0) {
        tmp_ptr = getenv("QUERY_STRING");
        data_len = strlen(tmp_ptr);
        /* 將表單編碼資料存入my_data中 */
        my_data = (char*)malloc(sizeof(char) * (data_len + 1));
        strcpy(my_data, getenv("QUERY_STRING"));
        my_data[data_len] = '\0';
    }

    /* 表單以POST方法傳送資料 */
    if (strcmp(method, "POST") == 0) {
        data_len = atoi(getenv("CONTENT_LENGTH"));
        /* 將表單編碼資料存入my_data中 */
        my_data = (char*)malloc(sizeof(char) * (data_len + 1));
        fread(my_data, 1, data_len, stdin);
    }

    i = 0;

    while (my_data[0] != '\0') {
        tmp = split(my_data, '='); // 分離資料對,取得欄位名
        makespace(tmp);     // 將+號還原成空白字元
        tmp = convert(tmp);     // 將十六進位碼還原成字元
        strcpy(nv[i].name, tmp); // 結果存入nv結構的name成員
        tmp = split(my_data, '&'); // 分離資料對,取得欄位值
        makespace(tmp);     // 將+號還原成空白字元
        tmp = convert(tmp);     // 將十六進位碼還原成字元
        strcpy(nv[i].value, tmp);   // 結果存入nv結構的value成員
        i++;
    }

    return i--;           // 傳回實際解碼的欄位數
}

/* 將+號還原成空白 */
void makespace(char* s) {
    int   i, len;
    len = strlen(s);

    for (i = 0; i < len; i++) {
        if (s[i] == '+') {
            s[i] = ' ';
        }
    }
}

/* 分離資料對 */
char* split(char* s, char stop) {
    char*  data;
    char*  tmp;
    int   i, len, j;
    len = strlen(s);
    tmp = s;
    data = (char*)malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) {
        if (s[i] != stop) {
            data[i] = s[i];    // 將停止字元前的字元存入data陣列
        } else {
            i += 1;   // 遇到停止字元後,便不再處理
            break;
        }
    }

    data[i] = '\0';

    for (j = i; j < len; j++) {
        s[j - i] = tmp[j];
    }

    s[len - i] = '\0';
    return data;
}

/* 將十六進位碼還原成字元 */
char* convert(char* s) {
    int   x, y, len;
    char*  data;
    len = strlen(s);
    data = (char*)malloc(sizeof(char) * (len + 1));
    y = 0;

    for (x = 0; x < len; x++) {
        if (s[x] != '%') {
            data[y] = s[x]; // 一般字元,不作處理
            y++;
        } else {
            /* 將%xx中的xx先各別轉換為十六進位值,相加後,再轉為字元 */
            data[y] = (char)(16 * hexa(s[x + 1]) + hexa(s[x + 2]));
            y++;
            x = x + 2;
        }
    }

    data[y] = '\0';
    return data;
}

/* 將字元轉為十六進位碼 */
int hexa(char c) {
    switch (c) {
    case '0':
        return 0;

    case '1':
        return 1;

    case '2':
        return 2;

    case '3':
        return 3;

    case '4':
        return 4;

    case '5':
        return 5;

    case '6':
        return 6;

    case '7':
        return 7;

    case '8':
        return 8;

    case '9':
        return 9;

    case 'A':
        return 10;

    case 'B':
        return 11;

    case 'C':
        return 12;

    case 'D':
        return 13;

    case 'E':
        return 14;

    case 'F':
        return 15;
    }

    return 0;
}







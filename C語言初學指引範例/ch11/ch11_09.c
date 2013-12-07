/*************************************
    檔名:ch11_09.c
    功能:配合結構體讀取二進位檔資料
 *************************************/

#include <stdlib.h>
#include <stdio.h>

struct student {
    char   stu_id[12];
    int    ScoreComputer;
    int    ScoreMath;
    int    ScoreEng;
    float  ScoreAvg;
};

FILE* fp;

void display(struct student);

void display(struct student tempStu) {
    printf("%s\t%d\t%d\t%d\t%.4f\n", \
           tempStu.stu_id, tempStu.ScoreComputer, tempStu.ScoreMath, \
           tempStu.ScoreEng, tempStu.ScoreAvg);
}

/**************main**************/
void main(void) {
    struct student IM[50];
    int i, num;

    if ((fp = fopen("data4", "rb")) == NULL) {
        printf("檔案錯誤\n");
        exit(0);
    }

    num = fread(IM, sizeof(struct student), 2, fp);
    printf("二進位檔讀取完成,前兩筆學生資料如下\n");
    fclose(fp);

    for (i = 0; i < 2; i++) {
        display(IM[i]);
    }

    /* system("pause"); */
}

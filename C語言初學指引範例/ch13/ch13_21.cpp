/************************************
    檔名:ch13_21.cpp
    功能:解構函式與動態記憶體配置
 ************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

class student {
public:

    ~student();
    int stu_size();
    void showdata();

private:
    struct stu {
        char   stu_id[12];
        int    ScoreComputer;
        int    ScoreMath;
        int    ScoreEng;
        float  ScoreAvg;
    };
    stu Entry;     //C++語法
};

student::~student() {
    cout << "正在刪除1個student類別的物件" << endl;
    //您還可以在這邊做其他事喔~
}

int student::stu_size() {
    return sizeof(stu);   //C++語法
}

void student::showdata() {
    cout << Entry.stu_id << "\t" << Entry.ScoreComputer << "\t" \
         << Entry.ScoreMath << "\t" << Entry.ScoreEng << "\t" \
         <<  Entry.ScoreAvg << endl;
}


FILE* fp;

/**************main**************/
void main(void) {
    student* IM;
    IM = new student[10];
    int i;

    if ((fp = fopen("data4", "rb")) == NULL) {
        cout << "檔案錯誤" << endl;
        exit(0);
    }

    int num = fread(IM, sizeof(student), 2, fp); //C++語法
    fclose(fp);
    cout << "二進位檔讀取完成,前兩筆學生資料如下" << endl;

    for (i = 0; i < 2; i++) {
        IM[i].showdata();
    }

    delete [] IM;
}

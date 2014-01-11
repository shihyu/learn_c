/*******************************
    檔名:ch13_24.cpp
    功能:寫入物件到二進位檔
 *******************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
private:
    string stu_id;
    int    ScoreComputer;
    int    ScoreMath;
    int    ScoreEng;
    float  ScoreAvg;
public:
    void setdata(string a, int b, int c, int d, float e) {
        stu_id = a;
        ScoreComputer = b;
        ScoreMath = c;
        ScoreEng = d;
        ScoreAvg = e;
    }
    void showdata() {
        cout << stu_id << "\t" << ScoreComputer << "\t" << ScoreMath << \
             "\t" << ScoreEng << "\t" << ScoreAvg << endl;
    }
};


/**************main**************/
void main(void) {
    string stu[3] = {"S9103501", "S9103502", "S9103503"};
    int score[3][3] = {{89, 84, 75},
        {77, 69, 87},
        {65, 68, 77}
    };
    ofstream writefile;
    int i, Total[3];
    student IM[3];

    for (i = 0; i < 3; i++) {
        Total[i] = 0;
        Total[i] = score[i][0] + score[i][1] + score[i][2];
        IM[i].setdata(stu[i], score[i][0], score[i][1] \
                      , score[i][2], float(Total[i]) / 3); //C++語法
    }

    writefile.open("data5", ios::out | ios::binary | ios::trunc);

    if (writefile.fail()) { //開檔失敗
        cout << "檔案發生錯誤" << endl;
        exit(1); //強迫結束程式
    }

    writefile.write((char*)&IM[i], sizeof(IM[i]) * 3);
    cout << "二進位檔寫入完成" << endl;
    writefile.close();
}

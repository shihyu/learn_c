#include"students.h"
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
int main();
void student_home(int);
string name;
int pwd = 0;
string list_academy;
void students_access()
{

    ifstream stu_acc;
    students stu;
    int length = 0;
    int length_end = 0;
    int count = 0;
reaccess:
    cout << "请输入帐号（学号10位）：";
    cin >> pwd;
    cout << "请输入密码（姓名）：";
    cin >> name;

    stu_acc.open("student.dat", ios::in | ios::binary);

    if (!stu_acc) {
        cerr << "open student.dat failed" << endl;
        exit(1);
    }

    stu_acc.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = stu_acc.tellg(); ///
    stu_acc.seekg(0, ios::beg); ///返回文件头

    while (!stu_acc.eof()) {
        stu_acc.read((char*)&stu, sizeof(stu));

        if (stu.get_student_num() == pwd) {
            cout << endl;
            cout << "学号已查询到！" << endl;

            if (stu.get_student_name() == name) {


                list_academy = stu.get_academy();
                cout << endl;
                cout << endl << "登录成功！" << endl;
                ++count;
                stu_acc.close();
                student_home(pwd);
                break;
            } else {
                cout << endl;
                cout << endl << "密码错误！重新登录!" << endl;
                stu_acc.close();
                goto reaccess;
            }
        }

        length = stu_acc.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }

    }

    if (count == 0) {
        cout << endl << "未注册的帐号！" << endl;
    }

    cout << endl;
    main();
}





void student_home(int xuehao)
{
    students s;
    int ch = 0;
reput:
    cout << endl;
    cout << "************欢迎 登录!***************" << endl;
    cout << "  " << name << "  " << pwd << "  " << list_academy << endl;
    cout << "------------------------------------" << endl;
    cout << "           1.借书              " << endl;
    cout << "           2.还书              " << endl;
    cout << "           3.借阅情况          " << endl;
    cout << "           4.书籍查询         " << endl;
    cout << "           5.馆藏图书          " << endl;
    cout << "           6.退出              " << endl;
    cout << "------------------------------------" << endl;
    cin >> ch;

    if (cin.eof() || cin.bad()) {
        cout << "输入错误！请重新输入！" << endl;
    }

    switch (ch) {
    case 1:
        s.rent_book(xuehao);
        break;

    case 2:
        s.return_book(xuehao);
        break;

    case 3:
        s.information(xuehao);
        break;

    case 4:
        s.stu_search(xuehao);
        break;

    case 5:
        s.display(xuehao);
        break;

    case 6:
        main();
        break;

    default: {
            cout << "输入错误！请重新输入！" << endl;
        }

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto reput;

}

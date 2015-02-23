#include"books_header.h"
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<iomanip>// 设置输出格式 （setw()等）

void admin_access();
void students_access();
int main()
{
    int ch = 0;
restart:
    cout << "--------------------------------------" << endl;
    cout << "--------------*图书管理系统*-----------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "              1.管理员登录             " << endl;
    cout << "              2.学生登录               " << endl;
    cout << "              3.馆藏图书               " << endl;
    cout << "              4.图书查询               " << endl;
    cout << "---------------------------------------" << endl;

    cin >> ch;

    if (cin.eof() ||
        cin.bad()) { // 输入ch之后  对输入的字符做判断（流结尾和非法字符），以避免死循环
        cout << endl << "非法字符！请重新输入！" << endl;
    }

    switch (ch) {
    case 1:
        admin_access();
        break;//管理员登录

    case 2:
        students_access();
        break;//学生登录

    case 3: {
            books book1;    //游客书籍查看
            book1.display(2);
            break;
        }

    case 4: {
            books book2;    //游客书籍查询
            book2.search(2);
            break;
        }

    default: {
            cout << endl << "输入错误！重新输入！" << endl;
        }
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //清楚输入流
    goto restart;//重新输入
    return 0;
}

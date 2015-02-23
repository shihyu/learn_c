#include"admin_header.h"
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
int main();
void admin_job();
//////////////////////////admin_access
void admin_access()
{
restart:
    string s;
    cout << "输入管理员密码（6位）" << endl;
    cin >> s;
    char passwd[6] = {0};
    ifstream pass;
    pass.open("admin_passwd.txt", ios::in);

    if (!pass) {
        cerr << "open admin_passwd.txt failed" << endl;
        exit(1);
    }

    pass.read((char*)passwd, 6);
    pass.close();

    if (passwd == s) {
        cout << "登录成功！" << endl;
        admin_job();
    } else {
        int ch;
        cout << "输入密码有误！请重新输入！" << endl;
        cout << "返回主界面请输入 1 继续输入 2" << endl;
        cin >> ch;

        if (ch == 1) {
            main();
        }

        goto restart;
    }

}
///////////////////////////////admin_job
void admin_job()
{
    admin admin_user;//生成操作对象
    cout << "---------------------------------------------------" << endl;
    cout << "------------------欢迎管理员登录！-----------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "                 1.添加 新书" << endl;
    cout << "                 2.删除 书籍" << endl;
    cout << "                 3.查找 书籍" << endl;
    cout << "                 4.列出 书籍信息" << endl;
    cout << "                 5.清空 图书信息(warning!)" << endl;
    cout << "                 6.添加 学生用户" << endl;
    cout << "                 7.删除 学生用户" << endl;
    cout << "                 8.列出 学生用户" << endl;
    cout << "                 9.退出" << endl;
    cout << "---------------------------------------------------" << endl;
    int ch = 0;
reput:
    cin >> ch;

    if (cin.eof() || cin.bad()) {
        cout << endl << "输入错误！重新输入" << endl;
    }

    switch (ch) {
    case 1:
        admin_user.add_books();
        break;

    case 2:
        admin_user.delete_books();
        break;

    case 3:
        admin_user.search(1);
        break;

    case 4:
        admin_user.show(admin_user);
        break;

    case 5: {
            ofstream out("books.dat");
            cout << endl << "已清空！" << endl;
            goto reput;
        }

    case 6:
        admin_user.add_stu();
        break;

    case 7:
        admin_user.delete_stu();
        break;

    case 8:
        admin_user.list_students();
        break;

    case 9:
        main();
        break;

    default:
        cout << endl << "输入错误！重新输入" << endl;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto reput;
}














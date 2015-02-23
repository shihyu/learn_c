#include"admin_header.h"
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
void admin_job();
admin::admin()
{

}
void admin::add_books()//添加书籍
{
    char s1[30] = {0}, s2[20] = {0}, s3[30] = {0}, s4[15] = {0};
    int t1 = 0, t3 = 0;
    double t2 = 0.0;
    int ch = 0;
    ofstream books_out;
    books_out.open("books.dat",
                   ios::out | ios::binary | ios::app); //以输出到文件，二进制追加的方式打开文件

    if (!books_out) {
        cerr << "open books.dat failed" << endl;
        exit(1);
    }

continue_input:
    cout << "输入   书名：";
    cin >> s1;

    cout << "输入   作者：";
    cin >> s2;

    cout << "输入   出版社：";
    cin >> s3;

    cout << "输入   isbn：";
    cin >> s4;

    cout << "输入   出版年份：";
    cin >> t1;
    cout << "输入   价格：";
    cin >> t2;
    cout << "输入   总量：";
    cin >> t3;

    books b(s1, s2, s3, s4, t1, t2, t3,
            0); //利用构造函数对对象成员初始化 写入数据
    cout << "导入成功！" << endl;
    books_out.write((char*)&b, sizeof(b));

    cout << "继续导入数据按 1  否则退出！" << endl;
    cin >> ch;

    if (ch == 1) {
        goto continue_input;
    } else { //不继续导入数据则返回 admin 界面
        books_out.close();
        admin_job();
    }

}
void admin::delete_books()
{
    int ch = 0; //输入
    int k = 0; //判断是否进行重新输入
    int count = 0; //是否馆藏此书
    int flag = 0; //删除动作 标记
    int length_end = 0;
    int length = 0;
    string delete_items;//输入要删除书籍的 信息
    books temp;
    ifstream books_in;
    ofstream books_temp;
    ofstream out("books_temp.dat");//以清空的方式打开，为写入数据做准备
    out.close();

    books_temp.open("books_temp.dat", ios::out | ios::binary);

    if (!books_temp) {
        cerr << "open books_temp.dat failed" << endl;
        exit(1);
    }

    books_in.open("books.dat", ios::in | ios::binary);

    if (!books_in) {
        cerr << "open books.dat failed" << endl;
        exit(1);
    }

    books_in.seekg(0, ios::end); //确定文件尾，避免多读取一个
    length_end = books_in.tellg(); //返回文件长度
    books_in.seekg(0, ios::beg); //将文件指针返回到文件首

choose:
    cout << "-------------------------------------" << endl;
    cout << "1.按 书名   删除" << endl << endl;
    cout << "2.按 作者   删除" << endl << endl;
    cout << "3.按 出版社 删除" << endl << endl;
    cout << "-------------------------------------" << endl;
    cin >> ch;

    if (cin.eof() || cin.bad()) {
        k = 1;
        cout << endl << "非法字符！请重新输入！" << endl;
    }

    switch (ch) {
    case 1: {
            k = 0;
            cout << "输入要删除的 书名:";
            cin >> delete_items;

            while (!books_in.eof()) {
                books_in.read((char*)&temp,
                              sizeof(temp)); //读出类的成员 存放在temp

                if (temp.get_book_name() != delete_items) {
                    books_temp.write((char*)&temp,
                                     sizeof(temp)); //不是要删除的 类 则写入第二个文件
                }

                else {

                    ++count;
                    flag = 1;
                    cout << endl << "删除书籍 :   " << temp.get_book_name() << "   " << endl;
                }

                length = books_in.tellg(); //返回当前指针的位置

                if (length_end == length) {
                    break;    //到文件尾结束
                }
            }

            break;
        }//end_case1

    case 2: {
            k = 0;
            cout << "输入要删除的书 作者名:";
            cin >> delete_items;

            while (!books_in.eof()) {

                books_in.read((char*)&temp, sizeof(temp));

                if (temp.get_author() != delete_items && temp.get_author() != 0) {
                    books_temp.write((char*)&temp, sizeof(temp));
                }

                else {
                    ++count;
                    flag = 1;
                    cout << endl << "删除书籍   作者名:  " << temp.get_author() << "   " <<
                         endl;
                }

                length = books_in.tellg();

                if (length_end == length) {
                    break;    //到文件尾结束
                }
            }

            break;
        }//end_case_2

    case 3: {
            k = 0;
            cout << "输入要删除的书 出版社名:";
            cin >> delete_items;

            while (!books_in.eof()) {
                books_in.read((char*)&temp, sizeof(temp));

                if (temp.get_press() != delete_items && temp.get_press() != 0) {
                    books_temp.write((char*)&temp, sizeof(temp));
                }

                else {
                    ++count;
                    flag = 1;
                    cout << "删除:   " << temp.get_press() << "   " << endl;
                }


                length = books_in.tellg();

                if (length_end == length) {
                    break;    //到文件尾结束
                }
            }

            break;
        }//end_case_3

    default: {
            k = 1;
            cout << endl << "输入错误！" << endl;
        }

    }//end_switch

    if (k == 1) { //输入非法字符重新输入
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto choose;
    }


    if (count == 0) {
        cout << endl << "未找到要删除的书籍！" << endl;
    }

    books_temp.close();
    books_in.close();
    //////////////////////////////////////////copy books_temp.dat to books.dat

    if (flag = 1) { //如果发生删除操作则进行文件拷贝
        length = 0;
        length_end = 0;
        books temp_n;
        ofstream books_out;
        ifstream books_temp_in;

        ofstream out_n("books.dat");//将原文件清空 准备写入删除后的 新数据
        out_n.close();


        books_temp_in.open("books_temp.dat", ios::in | ios::binary);

        if (!books_temp_in) {
            cerr << "open books_temp.dat failed" << endl;
            exit(1);
        }

        books_out.open("books.dat", ios::out | ios::binary);

        if (!books_out) {
            cerr << "open books.dat failed" << endl;
            exit(1);
        }

        books_temp_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
        length_end = books_temp_in.tellg();
        books_temp_in.seekg(0, ios::beg);

        while (!books_temp_in.eof()) {
            books_temp_in.read((char*)&temp_n,
                               sizeof(temp_n)); //执行拷贝，将新数据返回到原文件，以供操作

            books_out.write((char*)&temp_n, sizeof(temp_n));

            length = books_temp_in.tellg();

            if (length_end == length) {
                break;    //到文件尾结束
            }

        }

        books_temp_in.close();
        books_out.close();

        admin_job();
    }//end_if
}
void admin::add_stu()
{
    char name[15] = {0}, acad[15] = {0};
    int num = 0;

    ofstream creat;
    creat.open("student.dat", ios::out | ios::binary | ios::app);

    if (!creat) {
        cerr << "open student.dat failed" << endl;
        exit(1);
    }

    cout << "输入要创建的学生 姓名：";
    cin >> name;
    cout << "输入要创建的学生 学号(10位): ";
    cin >> num;
    cout << "输入要创建的学生 学院: ";
    cin >> acad;
    students stu(name, num,
                 acad); //利用构造函数对对象成员初始化 写入数据
    creat.write((char*)&stu,
                sizeof(stu)); //将数据以 类的整块形式 写入到 文件
    creat.close();
    admin_job();
}
void admin::delete_stu()
{
    cout << "只能通过 学号 精确删除！" << endl;
    students stu;
    ifstream stu_in;
    ofstream stu_out;
    int length_end = 0;
    int length = 0;
    int delete_items;
    int count = 0;

    ofstream out("student_temp.dat");
    out.close();

    stu_in.open("student.dat", ios::in | ios::binary);

    if (!stu_in) {
        cerr << "open student.dat failed" << endl;
        exit(1);
    }

    stu_out.open("student_temp.dat", ios::out | ios::binary);

    if (!stu_out) {
        cerr << "open student_temp.dat failed" << endl;
        exit(1);
    }

    stu_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = stu_in.tellg(); ///
    stu_in.seekg(0, ios::beg); ///
    cout << "要删除的学生 学号：";
    cin >> delete_items;

    ////////////////////////////////////////////////拷贝到student_temp.dat
    while (!stu_in.eof()) {
        stu_in.read((char*)&stu, sizeof(stu));

        if (stu.get_student_num() != delete_items && stu.get_student_num() > 1) {

            stu_out.write((char*)&stu, sizeof(stu));
        } else {
            ++count;
            cout << endl;

            cout << left << setw(5) << stu.get_student_name() << "  ";
            cout << left << setw(5) << stu.get_student_num() << "  ";
            cout << left << setw(7) << stu.get_academy() << "       ";
            cout << "该生信息已注销！" << endl;
        }

        length = stu_in.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }
    }

    if (count == 0) {
        cout << endl << "未找到该生信息！" << endl;
    }

    stu_in.close();
    stu_out.close();
    //////////////////////////////////////////////////拷贝回student.dat
    ifstream stu_temp;
    ofstream stu_new;
    students stud;
    length = 0;
    length_end = 0;
    ofstream outt("student.dat");
    outt.close();

    stu_temp.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = stu_temp.tellg(); ///
    stu_temp.seekg(0, ios::beg); ///

    stu_temp.open("student_temp.dat", ios::in | ios::binary);

    if (!stu_temp) {
        cerr << "open student_temp.dat failed" << endl;
        exit(1);
    }

    stu_new.open("student.dat", ios::out | ios::binary);

    if (!stu_new) {
        cerr << "open student.dat failed" << endl;
        exit(1);
    }

    while (!stu_temp.eof()) {
        stu_temp.read((char*)&stud, sizeof(stud));
        length = stu_temp.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }

        stu_new.write((char*)&stud, sizeof(stud));

    }

    stu_new.close();
    stu_temp.close();

    admin_job();
}
void admin::show(admin& admin_user)
{

    admin_user.display(1);
    admin_job();


}

void admin::list_students()
{
    students stu;
    ifstream students_show;
    students_show.open("student.dat", ios::out | ios::binary | ios::app);

    if (!students_show) {
        cerr << "open student.dat failed" << endl;
        exit(1);
    }

    students_show.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    int length_end = students_show.tellg(); ///
    students_show.seekg(0, ios::beg); ///
    int length = 0;
    cout << endl << endl;
    cout << "姓名      学号        学院" << endl;

    while (!students_show.eof()) {
        students_show.read((char*)&stu, sizeof(stu));

        cout << left << setw(8) << stu.get_student_name() << "  ";
        cout << left << setw(8) << stu.get_student_num() << "  ";
        cout << left << setw(8) << stu.get_academy() << "  " << endl;

        length = students_show.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }
    }

    students_show.close();
    admin_job();

}

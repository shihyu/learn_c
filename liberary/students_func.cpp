#include"students.h"
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
void student_home(int);
students::students()
{
    student_name[15] = {0};
    student_num = 0;
    academy[15] = {0};
}
students::students(char sn[15], int s, char a[15])
{
    strcpy(student_name, sn);
    student_num = s;
    strcpy(academy, a);
}
void students::rent_book(int xuehao)
{
    string book_name;
    string writer;
    books book;
    ifstream book_in;
    ofstream book_out;
    int length = 0;
    int length_end = 0;
    int count = 0;
    int judge = 0; //判断是否结束成功 不成功则无需拷贝
    cout << "请输入要借书籍的 书名：";
    cin >> book_name;
    cout << "请输入该书籍的 作者）：";
    cin >> writer;
    cout << endl;

    ofstream out("books_temp.dat");
    out.close();

    book_in.open("books.dat", ios::in | ios::binary);

    if (!book_in) {
        cerr << "open books.dat failed" << endl;
        exit(1);
    }

    book_out.open("books_temp.dat", ios::out | ios::binary);

    if (!book_out) {
        cerr << "open books_temp.dat failed" << endl;
        exit(1);
    }

    book_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = book_in.tellg(); ///
    book_in.seekg(0, ios::beg); ///返回文件头
    int i = 0;

    while (!book_in.eof()) {
        book_in.read((char*)&book, sizeof(book));

        if (book.get_book_name() == book_name && book.get_author() == writer) {
            ++count;

            for (i = 0; i < (book.get_num() + 4); i++) {
                if (book.rent_stu_number[i] < 10 && book.rent_stu_number[i] < 0)

                {
                    if (book.set_rent_num(0)) {

                        book.rent_stu_number[i] = xuehao;
                        judge = 1;

                        cout << endl << "借书成功！" << endl;
                        break;
                    }

                }


            }

            if (i >= (book.get_num() + 4)) {
                cout << endl << "不好意思，本书已借完！" << endl;
            }
        }

        book_out.write((char*)&book, sizeof(book));

        length = book_in.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }
    }

    if (count == 0) {
        cout << endl << "馆藏无此书！" << endl;
    }

    book_in.close();
    book_out.close();

    /////////////////////////////借书后拷贝回books.dat
    if (judge == 1) {
        books bookn;
        ifstream book_temp;
        ofstream book_new;
        length = 0;
        length_end = 0;

        ofstream out_n("books.dat");
        out_n.close();

        book_temp.open("books_temp.dat", ios::in | ios::binary);

        if (!book_temp) {
            cerr << "open books_temp.dat failed" << endl;
            exit(1);
        }

        book_new.open("books.dat", ios::out | ios::binary);

        if (!book_new) {
            cerr << "open books.dat failed" << endl;
            exit(1);
        }

        book_temp.seekg(0, ios::end); ///确定文件尾，避免多读取一个
        length_end = book_in.tellg(); ///
        book_temp.seekg(0, ios::beg); ///返回文件头

        while (!book_temp.eof())

        {
            book_temp.read((char*)&bookn, sizeof(bookn));



            length = book_temp.tellg();

            if (length_end == length) {
                break;    //到文件尾结束
            }

            book_new.write((char*)&bookn, sizeof(bookn));

        }

        book_temp.close();
        book_new.close();





    }//end_if


    student_home(xuehao);//返回学生界面

}
void students::return_book(int xuehao)
{


    string book_name;
    string writer;
    books book;
    ifstream book_in;
    ofstream book_out;
    int length = 0;
    int length_end = 0;
    int count = 0;
    int judge = 0; //判断是否结束成功 不成功则无需拷贝
    cout << "输入要归还的书籍 书名：";
    cin >> book_name;
    cout << "请输入该书籍的 作者名：";
    cin >> writer;
    cout << endl;

    ofstream out("books_temp.dat");
    out.close();

    book_in.open("books.dat", ios::in | ios::binary);

    if (!book_in) {
        cerr << "open books.dat failed" << endl;
        exit(1);
    }

    book_out.open("books_temp.dat", ios::out | ios::binary);

    if (!book_out) {
        cerr << "open books_temp.dat failed" << endl;
        exit(1);
    }

    book_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = book_in.tellg(); ///
    book_in.seekg(0, ios::beg); ///返回文件头
    int i = 0;

    while (!book_in.eof())

    {
        book_in.read((char*)&book, sizeof(book));

        if (book.get_book_name() == book_name && book.get_author() == writer) {
            ++count;

            for (i = 0; i < book.get_num(); i++) {
                if (book.rent_stu_number[i] == xuehao) {

                    book.set_rent_num(1);
                    book.rent_stu_number[i] = 1;
                    judge = 1;
                    cout << endl << "还书成功！" << endl;
                    break;
                }
            }

            if (i == book.get_num()) {
                cout << endl << "你未借此书，请仔细核对！" << endl;
            }
        }

        book_out.write((char*)&book, sizeof(book));
        length = book_in.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }

    }

    if (count == 0) {
        cout << endl << "馆藏无此书！" << endl;
    }

    book_in.close();
    book_out.close();

    /////////////////////////////借书后拷贝回books.dat
    if (judge == 1) {
        books bookn;
        ifstream book_temp;
        ofstream book_new;
        length = 0;
        length_end = 0;

        ofstream out_n("books.dat");
        out_n.close();

        book_temp.open("books_temp.dat", ios::in | ios::binary);

        if (!book_temp) {
            cerr << "open books_temp.dat failed" << endl;
            exit(1);
        }

        book_new.open("books.dat", ios::out | ios::binary);

        if (!book_new) {
            cerr << "open books.dat failed" << endl;
            exit(1);
        }

        book_temp.seekg(0, ios::end); ///确定文件尾，避免多读取一个
        length_end = book_in.tellg(); ///
        book_temp.seekg(0, ios::beg); ///返回文件头

        while (!book_temp.eof())

        {
            book_temp.read((char*)&bookn, sizeof(bookn));

            length = book_temp.tellg();

            if (length_end == length) {
                break;    //到文件尾结束
            }

            book_new.write((char*)&bookn, sizeof(bookn));

        }

        book_temp.close();
        book_new.close();





    }//end_if


    student_home(xuehao);//返回学生界面


}
void students::information(int xuehao)
{
    int length = 0;
    int length_end = 0;
    int count = 0;
    books book;
    ifstream books_in;
    int i = 0;

    books_in.open("books.dat", ios::in | ios::binary);
    books_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = books_in.tellg(); //
    books_in.seekg(0, ios::beg);

    while (!books_in.eof()) {
        books_in.read((char*)&book, sizeof(book));

        for (i = 0; i < book.get_num(); i++) {
            if (book.rent_stu_number[i] == xuehao) {
                if (count == 0) {
                    cout << "书名    作者    出版社       ISBN        年份   价格   总数   借出数量"
                         << endl;
                }

                cout << left << setw(6) << book.get_book_name() << "  ";
                cout << left << setw(6) << book.get_author() << "  ";
                cout << left << setw(7) << book.get_press() << "  ";
                cout << left << setw(6) << book.get_isbn() << "  ";
                cout << left << setw(6) << book.get_year() << "  ";
                cout << left << setw(5) << book.get_price() << "  ";
                cout << left << setw(5) << book.get_num() << "  ";
                cout << left << setw(5) << book.get_rent_num() << "  " << endl << endl;

                ++count;//找到一本就加1

            }
        }//end_for


        length = books_in.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }
    }//end_while

    cout << endl << "一共借入" << count << "本书！" << endl;


    student_home(xuehao);//back
}
void students::stu_search(int xuehao)
{
    search(xuehao);
}


char* students::get_student_name()
{
    return student_name;
}
int students::get_student_num()
{
    return student_num;
}
char* students::get_academy()
{
    return academy;
}

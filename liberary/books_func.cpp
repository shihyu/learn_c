#include"books_header.h"
#include<cstring>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
int main();
void admin_job();
void student_home(int xuehao);
books::books()
{
    book_name[30] = {0};
    author[20] = {0};
    press[30] = {0};
    isbn[15] = {0};
    year = 0;
    price = 0.0;
    num = 0;
    rent_num = 0;
    rent_stu_number[50] = {0};
    //rent_stu_number[rent_num]={0};

}
books::books(char b[30], char a[20], char p[30], char i[15], int y, double pr,
             int n, int r)
{

    strcpy(book_name, b);
    strcpy(author, a);
    strcpy(press, p);
    strcpy(isbn, i);
    year = y;
    price = pr;
    num = n;
    rent_num = r;
    rent_stu_number[50] = {0};

}
void books::display(int who)
{
    books temp;
    int length = 0;
    int length_end = 0;
    int i = 0;
    ifstream books_in;
    books_in.open("books.dat", ios::in | ios::binary);

    if (!books_in) {
        cerr << "open books.dat failed" << endl;
        exit(1);
    }

    cout << "书名    作者    出版社       ISBN        年份   价格   总数   借出数量"
         << endl;
    books_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = books_in.tellg(); ///
    books_in.seekg(0, ios::beg); ///

    while (!books_in.eof()) {
        books_in.read((char*)&temp, sizeof(temp));

        cout << left << setw(6) << temp.get_book_name() << "  ";
        cout << left << setw(6) << temp.get_author() << "  ";
        cout << left << setw(7) << temp.get_press() << "  ";
        cout << left << setw(6) << temp.get_isbn() << "  ";
        cout << left << setw(6) << temp.get_year() << "  ";
        cout << left << setw(5) << temp.get_price() << "  ";
        cout << left << setw(5) << temp.get_num() << "  ";
        cout << left << setw(5) << temp.get_rent_num() << "  " << endl << endl;

        /*for(i=0;i<temp.get_rent_num()&&temp.rent_stu_number[i]!=0&&temp.rent_stu_number[i]!=1;i++)
           {     if(i==0)
                            cout<<"     借此书学生 学号："<<endl;
                cout<<"               "<<temp.rent_stu_number[i]<<endl<<endl;
                   }*/
        length = books_in.tellg();

        if (length_end == length) {
            break;    //到文件尾结束
        }
    }

    books_in.close();

    if (who == 1) { //admin
        admin_job();
    } else if (who == 2) { //tourist
        main();
    } else {
        student_home(who);    //student
    }
}

void books::search(int who)
{
    int ch = 0;
    int length = 0;
    int length_end = 0;
    int count = 0;
    string search_items;
    books book;
    ifstream books_in;

    cout << "1.按作者名字查找" << endl << endl;
    cout << "2.按书籍名字查找" << endl;
    cin >> ch;

    books_in.open("books.dat", ios::in | ios::binary);
    books_in.seekg(0, ios::end); ///确定文件尾，避免多读取一个
    length_end = books_in.tellg(); //
    books_in.seekg(0, ios::beg);

    switch (ch) {
    case 1: { //author
            cout << "输入要查找书籍的 作者名:";
            cin >> search_items;

            while (!books_in.eof()) {
                books_in.read((char*)&book, sizeof(book));

                if (book.get_author() == search_items) {
                    if (count == 0) {
                        cout << "书名   作者   出版社   ISBN         年份   价格   总数   借出数量"
                             << endl;
                    }

                    cout << left << setw(5) << book.get_book_name() << "  ";
                    cout << left << setw(5) << book.get_author() << "  ";
                    cout << left << setw(7) << book.get_press() << "  ";
                    cout << left << setw(5) << book.get_isbn() << "  ";
                    cout << left << setw(5) << book.get_year() << "  ";
                    cout << left << setw(5) << book.get_price() << "  ";
                    cout << left << setw(5) << book.get_num() << "  ";
                    cout << left << setw(9) << book.get_rent_num() << " " << endl;

                    ++count;//找到一本就加1

                }

                length = books_in.tellg();

                if (length_end == length) {
                    break;    //到文件尾结束
                }
            }

            break;
        }//end_case1

    case 2: { //book_name

            cout << "输入要查找的 书籍名:";
            cin >> search_items;
            cout << endl;

            while (!books_in.eof()) {
                books_in.read((char*)&book, sizeof(book));

                if (book.get_book_name() == search_items) {
                    if (count == 0) {
                        cout << "书名   作者   出版社   ISBN   年份   价格   总数   借出数量"
                             << endl;
                    }

                    cout << left << setw(5) << book.get_book_name() << "  ";
                    cout << left << setw(5) << book.get_author() << "  ";
                    cout << left << setw(7) << book.get_press() << "  ";
                    cout << left << setw(5) << book.get_isbn() << "  ";
                    cout << left << setw(5) << book.get_year() << "  ";
                    cout << left << setw(5) << book.get_price() << "  ";
                    cout << left << setw(5) << book.get_num() << "  ";
                    cout << left << setw(9) << book.get_rent_num() << " " << endl;

                    ++count;

                }

                length = books_in.tellg();

                if (length_end == length) {
                    break;    //到文件尾结束
                }
            }

            break;

        }//end_case_2

    }//end_switch

    if (count == 0) {
        cout << endl << "未查找到相关书籍！" << endl;
    }

    books_in.close();
    cout << endl;

    if (who == 1) { //admin
        admin_job();
    } else if (who == 2) { //tourist
        main();
    } else {
        student_home(who);    //student
    }



}

int books::set_rent_num(int flag)
{
    if (flag == 0) { //借书
        if (rent_num < num) {
            ++rent_num;
            return 1;
        } else {
            return 0;
        }
    } else if (flag == 1) { //还书
        --rent_num;
        return 1;
    }



}
/*void books::set_rent_stu_number(int xuehao)
{
    //xuehao==1 还书
    rent_stu_number[--rent_num]=xuehao;



}*/
/////////////////////////////////////////return private members
char* books::get_book_name()
{
    return book_name;
}
char* books::get_author()
{
    return author;
}
char* books::get_press()
{
    return press;
}
char* books::get_isbn()
{
    return isbn;
}
int books::get_year()
{
    return year;
}
double books::get_price()
{
    return price;
}
int books::get_num()
{
    return num;
}
int books::get_rent_num()
{
    return rent_num;
}


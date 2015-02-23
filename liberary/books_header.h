#include<string>
#include<limits>//清除输入流 使用 （numeric_limits）
using namespace std;
class books
{
public:
    books();//default
    books(char b[30], char a[20], char p[30], char i[15], int y, double pr, int n,
          int r);
    void display(int who);
    void search(int who);
    int rent_stu_number[];//借书的学生学号
    /////////////////////////////////////get_private
    char* get_book_name();
    char* get_author();
    char* get_press();
    char* get_isbn();
    int get_year();
    double get_price();
    int get_num();
    int get_rent_num();
    int set_rent_num(int flag);
private:
    char book_name[30];//书名
    char author[20];//作者
    char press[30];//出版社
    char isbn[15];
    int year;//出版年份
    double price;//价格
    int num;//书的总数
    int rent_num;//借出去的数量


};


#include"books_header.h"
class students: public books
{
public:
    students();
    students(char sn[15], int s, char a[15]);
    void rent_book(int);//借书
    void return_book(int); //还书
    void stu_search(int xuehao);//查找书籍
    void information(int);//显示自己借了什么书

    //get private
    char* get_student_name();//返回学生姓名
    int get_student_num();//返回学号
    char* get_academy();//返回学院

private:
    char student_name[15];//名字
    int student_num;//学号
    char academy[15];//学院

};



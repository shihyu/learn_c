#include"students.h"
class admin: public students
{
public:
    admin();
    void add_books();
    void delete_books();
    void add_stu();
    void delete_stu();
    void show(admin& admin_user);//列出书籍信息
    void list_students();

private:



};



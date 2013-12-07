/***********************************
    檔名:ch13_09.cpp
    功能:預設建構函式的應用
 ***********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     int VarA;
     myclass(){};               //預設建構函式
     myclass(int,int);          //宣告建構函式
     void ShowVar();
  private:
     int VarB;
};
myclass::myclass(int a,int b)    //定義建構函式
{
    VarA=a;
    VarB=a+b;
}
void myclass::ShowVar()
{
    printf("VarA=%d\n",VarA);
    printf("VarB=%d\n",VarB);
}

void main(void)
{
   myclass X(3,10);
   myclass Y;
 
   printf("物件X\n");
   X.ShowVar();
 
   printf("物件Y\n");
   Y.ShowVar();
   /* system("pause"); */
}

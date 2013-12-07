/*******************************
    檔名:ch13_03.cpp
    功能:合併定義與宣告成員函式
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
    void InitVar()
    {
      Var=0;
    }
    void AddVar(int b)
    {
      Var=Var+b;
    }
    void ShowVar()
    {
       RealShow();  //執行private的函式
    }
  private:
    int Var;
    void RealShow()
    {
       printf("Var=%d\n",Var);
    }
};

void main(void)
{
   myclass X,Y;
 
   X.InitVar();      //在X物件上,執行InitVar成員函式
   Y.InitVar();      //在Y物件上,執行InitVar成員函式
 
   X.AddVar(10);     //在X物件上,執行AddVar成員函式
   printf("物件X\t");
   X.ShowVar();
 
   printf("物件Y\t");
   Y.AddVar(5);      //在Y物件上,執行AddVar成員函式
   Y.ShowVar();

   printf("物件Y\t");
   Y.AddVar(3);      //在Y物件上,執行AddVar成員函式
   Y.ShowVar();
   /* system("pause"); */
}

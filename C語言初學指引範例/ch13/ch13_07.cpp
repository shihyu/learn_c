/*******************************
    檔名:ch13_07.cpp
    功能:建構函式的引數初值應用
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     int VarA;
     myclass(int,int);          //宣告建構函式
     void ShowVar();
  private:
     int VarB;
};
myclass::myclass(int a=0,int b=0)    //定義建構函式
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
    int i;
    myclass X[3];
    myclass Y(5,40);
  
    printf("物件Y\n");
    Y.ShowVar();
  
    for (i=0;i<3;i++)
    {
       printf("物件X[%d]\n",i);
       X[i].ShowVar();
    }
   /* system("pause"); */
}

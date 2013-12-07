/*******************************
    檔名:ch13_04.cpp
    功能:手動設定成員變數初值
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     int VarA;
     void ShowVar();
  private:
     int VarB;
};
void myclass::ShowVar()
{
     printf("VarA=%d\n",VarA);
     printf("VarB=%d\n",VarB);
}

void main(void)
{
 int i;
 myclass X[3];
 
 printf("設定初值前\n");
 for(i=0;i<3;i++)
    X[i].ShowVar();
    
 for(i=0;i<3;i++)
 {
    X[i].VarA=0;
    //X[i].VarB=0;    //無法取用私用成員變數
 } 
 
 printf("設定初值後\n");
 for(i=0;i<3;i++)
    X[i].ShowVar();
 /* system("pause"); */
}

/****************************
    檔名:ch13_14.cpp
    功能:this指標
 ****************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     void SetVarA(int);
     void SetVarB(int);
     void ShowData();
  private:
     int VarA;
     int VarB;
};

void myclass::SetVarA(int value)
{
    this->VarA=value;
}
void myclass::SetVarB(int value)
{
    this->VarB=value;
}
void myclass::ShowData()
{
    printf("VarA=%d\n",this->VarA);
    printf("VarB=%d\n",this->VarB);
}

void main(void)
{
   myclass ObjX;

   ObjX.SetVarA(100);
   ObjX.SetVarB(200);
   ObjX.ShowData();
   /* system("pause"); */
}

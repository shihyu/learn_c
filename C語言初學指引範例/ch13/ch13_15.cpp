/****************************
    檔名:ch13_15.cpp
    功能:友誼函式
 ****************************/

#include <stdlib.h>
#include <stdio.h>

class BP
{
  public:
     BP();
     BP(int b,int p);
   
     int GetBaseNo();
     int GetPow();
     
     friend int CalPow(BP B); //宣告友誼函式
  
  private:
     int    BaseNo;
     int    Pow;
};

BP::BP()
{
}
BP::BP(int b,int p)
{
    BaseNo=b;
    Pow=p;
}

int BP::GetBaseNo()
{
    return BaseNo;
}
int BP::GetPow()
{
    return Pow;
}

int CalPow(BP Obj)     //友誼函式定義,不須指定類別
{
    int i;
    int result=1;
   
    for(i=1;i<=Obj.Pow;i++)            //計算BaseNo的B.Pow次方
      result=result*Obj.BaseNo;

    return result;
}

void main(void)
{
   int Ans;
   BP ObjA(10,3),ObjB(20,2);

   Ans=CalPow(ObjA);
   printf("底數=%d\t指數=%d\t答案=%d\n",ObjA.GetBaseNo(),ObjA.GetPow(),Ans);
   Ans=CalPow(ObjB);
   printf("底數=%d\t指數=%d\t答案=%d\n",ObjB.GetBaseNo(),ObjB.GetPow(),Ans);
   /* system("pause"); */
}

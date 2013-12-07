/*******************************
    郎:ch13_10.cpp
    :篶ㄧΑ滦更
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     double VarA;
     myclass();                 //礚ま计篶ㄧΑ
     myclass(int,int);          //ㄢ俱计ま计篶ㄧΑ
     myclass(double,double);      //ㄢ疊翴计ま计篶ㄧΑ
     void ShowVar();
  private:
     double VarB;
};
myclass::myclass()               //﹚竡礚ま计篶ㄧΑ
{
    VarA=10;
    VarB=10;
}
myclass::myclass(int a,int b)    //﹚竡ㄢ俱计ま计篶ㄧΑ
{
    VarA=a;
    VarB=a+b;
}
myclass::myclass(double a,double b)    //﹚竡ㄢ疊翴计ま计篶ㄧΑ
{
    VarA=a;
    VarB=a*b;
}
void myclass::ShowVar()
{
    printf("VarA=%.2f\n",VarA);
    printf("VarB=%.2f\n",VarB);
}

void main(void)
{
   int i;
   myclass X[3];
   myclass Y(5,40);
   myclass Z(20.3,30.6);
 
   for (i=0;i<3;i++)
   {
      printf("ンX[%d]\n",i);
      X[i].ShowVar();
   }
 
   printf("ンY\n");
   Y.ShowVar();
 
   printf("ンZ\n");
   Z.ShowVar();
   /* system("pause"); */
}

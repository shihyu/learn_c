/*******************************
    檔名:ch13_20.cpp
    功能:new及delete的應用
 *******************************/

#include <stdlib.h>
#include <iostream>
#include "./lotto.h"

using namespace std;

/**************main()**************/
int main(int argc,char *argv[])
{
 int i,special,ball_qty=6,temp;
 int *lotto;

 if(argc>1)
 {
    ball_qty=atoi(argv[1]);  /* atoi須引入stdlib.h */
    if (ball_qty==0)
    {
       cout << "參數錯誤,例如輸入球數非數字\n";
       return -1;
    }
    if (!((ball_qty>=1) && (ball_qty<=41)))
    {
       cout << "參數錯誤,例如輸入球數非1~41\n";
       return -1;
    }
 }
 lotto=new int[ball_qty];
 generate_lotto_sort(&special,lotto,ball_qty);

 cout << "樂透號碼如下.....\n";
 for (i=0;i<ball_qty;i++)
 {
   if ((i%6==0) && (i!=0))
       cout << "\n";
   cout << lotto[i] << "\t";
 }   
 if (ball_qty==1)
   delete lotto;
 else
   delete [] lotto;
 cout << "\n";
 cout << "特別號:" << special << endl;
 return 1;
}

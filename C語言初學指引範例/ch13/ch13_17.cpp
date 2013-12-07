/*******************************
    檔名:ch13_17.cpp
    功能:cout物件的練習
 *******************************/

#include <iostream>

using namespace std;

void main()
{
  int   a=1;
  float b=2.3;
  char *s="Hello C語言";
  int* p;               //同C語言的 int *p;
  
  p=&a;
  cout << "a=" << a << "\n";
  cout << "b=" << b << endl;
  cout << "s=" << s << endl;
  cout << "p=" << p << endl;
}

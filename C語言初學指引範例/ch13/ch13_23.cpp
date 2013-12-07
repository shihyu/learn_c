/*******************************************************
    檔名:ch13_23.cpp
    功能:複製檔案(使用ifstream.get()與ofstream.put() 
 *******************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main(void)
{
 ifstream readfile;
 ofstream writefile;
 string filename1,filename2;
 char c;
 
 cout << "請輸入來源檔名:";
 cin >> filename1;
 cout << "請輸入目的檔名:";
 cin >> filename2;
 
 readfile.open(filename1.c_str());
 writefile.open(filename2.c_str(),ios::out|ios::trunc);
 
 if(readfile.fail() || writefile.fail())   //開檔失敗
 {
  cout << "檔案發生錯誤" << endl;
  exit(1); //強迫結束程式
 }
 
 cout << "讀取並寫入中......" << endl;
 while(readfile.get(c))  //使用迴圈讀取來源檔內容
 {
   cout << c;
   writefile.put(c); //使用迴圈寫入目的檔內容
 }
 cout << "\n讀取並寫入完畢......" << endl;
 
 readfile.close();
 writefile.close();
}

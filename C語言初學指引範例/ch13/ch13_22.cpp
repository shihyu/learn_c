/*******************************
    檔名:ch13_22.cpp
    功能:開檔與關檔
 *******************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main(void)
{
 ifstream readfile;
 string filename;
 
 cout << "請輸入檔名(可含路徑):";
 cin >> filename;
 
 readfile.open(filename.c_str(),ios::nocreate);
 
 if(readfile.fail())   //開檔失敗
 {
  cout << "檔案" << filename << "開啟失敗" << endl;
  exit(1); //強迫結束程式
 }
 
 cout << "檔案" << filename << "開啟中..." << endl;
 readfile.close();
 cout << "檔案" << filename << "關閉" << endl;
}

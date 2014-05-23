//
//使用了函數範本版max的程式(C++)
//
#include <iostream>

#include "max.h"

using namespace std;

int main(void)
{
	int x, y;
	
	cout << "x的值為:"; cin >> x;
	cout << "y的值為:"; cin >> y;
	
	cout << "max(x, y) = " << max(x, y) << endl;
	
    system("PAUSE");
	return (0);
}



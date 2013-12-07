/*****************************
    檔名:pro1.c
    功能:巨集
 *****************************/

#define Sum(a,b) (a)+(b)
#define Mul(a,b) (a)*(b)

void main(void) {
    int a = 1, b = 2, c = 3, d = 4;
    int result1, result2;
    result1 = Sum(a * b, c * d);
    result2 = Mul(a + b, c + d);
}

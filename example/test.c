#include <stdio.h>

#define PI 3.14

int main(int argc, char* argv[]) {
    enum _Month {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    enum _Month  Month;

    Month = February;



    printf("%d月\n", January);
    printf("%d月\n", December); 
    printf("%d月\n", Month); 


    printf("PI=%f\n",PI);

    return 0;
}

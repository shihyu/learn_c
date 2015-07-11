#include <stdio.h>
int main(int argc, char *argv[])
{
    // C data types 分成整數(二補數), 浮點數(IEEE754)
    printf("char size=%ld\n",sizeof(char));
    printf("signed char size=%ld\n",sizeof(signed char));
    printf("unsigned char size=%ld\n",sizeof(unsigned char));
    printf("short size=%ld\n",sizeof(short));
    printf("short int size=%ld\n",sizeof(short int));
    printf("signed short size=%ld\n",sizeof(signed short));
    printf("signed short int size=%ld\n",sizeof(signed short int));
    printf("unsigned short size=%ld\n",sizeof(unsigned short));
    printf("unsigned short int size=%ld\n",sizeof(unsigned short int));
    printf("int size=%ld\n",sizeof(int));
    printf("signed int size=%ld\n",sizeof(signed int)); 
    printf("unsigned size=%ld\n",sizeof(unsigned));
    printf("unsigned int size=%ld\n",sizeof(unsigned int));
    printf("long size=%ld\n",sizeof(long));
    printf("long int size=%ld\n",sizeof(long int));
    printf("signed long size=%ld\n",sizeof(signed long));
    printf("signed long int size=%ld\n",sizeof(signed long int));
    printf("unsigned long size=%ld\n",sizeof(unsigned long));
    printf("unsigned long int size=%ld\n",sizeof(unsigned long int));
    printf("long long size=%ld\n",sizeof(long long));
    printf("long long int size=%ld\n",sizeof(long long int));
    printf("signed long long size=%ld\n",sizeof(signed long long));
    printf("signed long long int size=%ld\n",sizeof(signed long long int));
    printf("unsigned long long size=%ld\n",sizeof(unsigned long long));
    printf("unsigned long long int size=%ld\n",sizeof(unsigned long long int));
    printf("float size=%ld\n",sizeof(float));
    printf("double size=%ld\n",sizeof(double));
    printf("long double size=%ld\n",sizeof(long double));

    // 32bit CPU 指標佔4byte , 64bit CPU 佔 8byte 
    printf("\n\n\n\nchar* size=%ld\n",sizeof(char*));
    printf("signed char* size=%ld\n",sizeof(signed char*));
    printf("unsigned char* size=%ld\n",sizeof(unsigned char*));
    printf("short* size=%ld\n",sizeof(short*));
    printf("short int* size=%ld\n",sizeof(short int*));
    printf("signed short* size=%ld\n",sizeof(signed short*));
    printf("signed short int* size=%ld\n",sizeof(signed short int*));
    printf("unsigned short* size=%ld\n",sizeof(unsigned short*));
    printf("unsigned short int* size=%ld\n",sizeof(unsigned short int*));
    printf("int* size=%ld\n",sizeof(int*));
    printf("signed int* size=%ld\n",sizeof(signed int*)); 
    printf("unsigned* size=%ld\n",sizeof(unsigned*));
    printf("unsigned int* size=%ld\n",sizeof(unsigned int*));
    printf("long* size=%ld\n",sizeof(long*));
    printf("long int* size=%ld\n",sizeof(long int*));
    printf("signed long* size=%ld\n",sizeof(signed long*));
    printf("signed long int* size=%ld\n",sizeof(signed long int*));
    printf("unsigned long* size=%ld\n",sizeof(unsigned long*));
    printf("unsigned long int* size=%ld\n",sizeof(unsigned long int*));
    printf("long long* size=%ld\n",sizeof(long long*));
    printf("long long int* size=%ld\n",sizeof(long long int*));
    printf("signed long long* size=%ld\n",sizeof(signed long long*));
    printf("signed long long* int size=%ld\n",sizeof(signed long long int*));
    printf("unsigned long long* size=%ld\n",sizeof(unsigned long long*));
    printf("unsigned long long int* size=%ld\n",sizeof(unsigned long long int*));
    printf("float* size=%ld\n",sizeof(float*));
    printf("double* size=%ld\n",sizeof(double*));
    printf("long double* size=%ld\n",sizeof(long double*));
    printf("void* size=%ld\n",sizeof(void*));

    return 0;
}

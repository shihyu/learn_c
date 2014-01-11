/* myavg.c */

double myavg(int* p) {
    int i;
    double sum;
    sum = 0.0;

    for (i = 0; i < 5; i++) {
        sum += *(p + i);
    }

    return sum / 5;
}



/* mysum.c */

int mysum(int t[]) {
    int i, sum;
    sum = 0;

    for (i = 0; i < 5; i++) {
        sum += t[i];
    }

    return sum;
}

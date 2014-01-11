#include <stdlib.h>
float get_rand() {
    float rand_value;
    rand_value = ((float)rand() / (float)RAND_MAX);
    return rand_value;
}

int get_maxrand(int max) {
    int rand_value;
    rand_value = (int)((float)max * rand() / (RAND_MAX + 1.0));
    return rand_value;
}


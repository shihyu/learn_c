#include <stdlib.h>
#include <time.h>

void init_rand() {
    time_t seed;
    seed = time(NULL);
    srand(seed);
}


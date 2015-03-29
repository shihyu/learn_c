#include <stdio.h>
#include "calfeatures.h"
// g++ -ggdb  main.cpp calfeatures.cpp -o main `pkg-config --cflags --libs opencv`

int main(int argc, char *argv[]) {

    if (argc > 1) {
        printf("start similar compare\n");
    } else {
        printf("start train\n");
        tarin_feature_begin();
    }

    return 0;
}

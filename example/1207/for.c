#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int i = 0;

    // for ( ; ;)
    while (1) {
        printf("hello\n");
        // sleep(1);
        i++;

        if (i >= 5) {
            break;
        }
    }

    return 0;
}

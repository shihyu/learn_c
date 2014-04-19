/* strlen example */
#include <stdio.h>
#include <string.h>

int main() {
    int i, yyy;
    char xxx[4] = {'A', 'C', 'B', '\0'};

    yyy = strlen(xxx);
    printf("%d\n", yyy);

    for (i = 0; i < yyy; ++i) {
        printf("%c\n", xxx[i]);
        /* code */
    }

    return 0;
}

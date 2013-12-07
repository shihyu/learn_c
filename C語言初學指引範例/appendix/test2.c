#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i;
    printf("本程式共接受到命令列%d個參數\n", argc);

    for (i = 0; i <= argc - 1; i++) {
        printf("argv[%d]字串為%s\n", i, argv[i]);
    }

    system("pause");
    return 1;
}

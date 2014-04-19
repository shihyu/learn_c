/* fifo01.c */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    mode_t  mode = 0666;

    if (argc != 2) {
        puts("ㄏノよ猭: fifo01 <name>");
        exit(1);
    }

    unlink(argv[1]);

    if ((mkfifo(argv[1], mode)) < 0) {
        perror("mkfifo error");
        exit(1);
    }

    exit(0);
}

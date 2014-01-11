/* newmask.c */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    mode_t  new_mask, old_mask;
    new_mask = 0222;
    old_mask = umask(new_mask);
    printf("file1...\n");
    printf("old mask is %#o\n", old_mask);
    printf("new mask is %#o\n", new_mask);
    system("touch file1");
    new_mask = 0002;
    old_mask = umask(new_mask);
    printf("file2...\n");
    printf("old mask is %#o\n", old_mask);
    printf("new mask is %#o\n", new_mask);
    system("touch file2");
    new_mask = 0022;
    old_mask = umask(new_mask);
    printf("file3...\n");
    printf("old mask is %#o\n", old_mask);
    printf("new mask is %#o\n", new_mask);
    system("touch file3");
    exit(0);
}

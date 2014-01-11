/* execve1.c */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
    char* args[] = {"/bin/ls", NULL};
    execve("/bin/ls", args, NULL);
    return 0;
}

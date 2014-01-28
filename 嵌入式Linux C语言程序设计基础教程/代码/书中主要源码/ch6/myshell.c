#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define N 128

int main()
{
    pid_t pid;
    char buf[N];
    char *arg[N];
    int i = 0;

    printf(">");
    while (gets(buf, N) != NULL)
    {
            arg[i++] = strtok(buf, " ");
            do
            {
                arg[i++] = strtok(NULL, " ");
            }while (arg[i-1] != NULL);
            if (execvp(arg[0], arg) == -1)
            {
                perror("execvp");
                exit(-1);
            }
        }
        else
        {
            wait(NULL);
            printf(">");
        }
    }
}

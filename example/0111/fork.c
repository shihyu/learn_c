#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void print_hello(int time);
void register_sleep(int time, void (*ptr_fun)(int time));
int g_value = 100;

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    int value = 20;
    pid = fork();

    if (pid < 0) {
        printf("fork err/n");
        exit(-1);
    } else if (pid == 0) {
        /* in child process */
        printf("child pid = %d, pparent pid = %d\n", getpid(), getppid());
        printf("g_value address=%p\n", &g_value);
        printf("value address=%p\n", &value);
        printf("g_value=%d\n", g_value);
        printf("value=%d\n", value);
        g_value = 200;
        value = 50;
        printf("value=%d\n", value);
        register_sleep(10, print_hello);
    } else {
        sleep(1);
        /* in parent process */
        printf("parent pid = %d, pparent pid = %d\n", getpid(), getppid());
        printf("g_value address=%p\n", &g_value);
        printf("value address=%p\n", &value);
        printf("g_value=%d\n", g_value);
        printf("value=%d\n", value);
        // wait(NULL);
        waitpid(pid, &status, 0);
    }

    return 0;
}

void register_sleep(int time, void (*ptr_fun)(int time)) {
    sleep(time);
    ptr_fun(time);
}

void print_hello(int time) {
    printf("awake - sleep=%d", time);
}

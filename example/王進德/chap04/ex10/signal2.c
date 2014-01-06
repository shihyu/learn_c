/* signal2.c */
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int alarm_flag = 0;

typedef struct student {
  char name[20];
  int  score;
}student;

void show(student s);

void set_alarm(int sig)
{
  student s1;
  printf("輸入姓名: ");
  scanf("%s",&s1.name);
  printf("輸入成績: ");
  scanf("%d",&s1.score);

  show(s1);

  alarm_flag = 1;
}

int main()
{
  pid_t	pid;
  
  pid = fork();

  switch (pid) {
  case -1:
    perror("fork error");
    exit(1);
  case 0:
    /* child */
    sleep(5);
    kill(getppid(), SIGALRM);
    exit(0);
  }
  /* parent process */

  printf("等待 alarm 訊號....\n");
  (void) signal(SIGALRM, set_alarm);
  pause();

  if (alarm_flag) {
    printf("系統接收到 alarm 訊號\n");
  }

  exit(0);
}

void show(student s)
{
  printf("學生 %s 的成績為 %d\n",s.name,s.score);
}


/* waitpid1.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void disp0();
void disp1();
void disp2();
int  mymax(int,int);

int main(void)
{
  pid_t child;
  int	status,ans;
  void	(*fun[3])();
  int	(*pm)(int x, int y);
  int	num1,num2,num3,max_num;

  fun[0]=disp0;
  fun[1]=disp1;
  fun[2]=disp2;
  pm=mymax;

  printf("是否複製程序? (1:Yes, 2:No) ");
  scanf("%d",&ans);

  if (ans==1) {
    child = fork();
    if (child == -1) {
      perror("fork error");
      exit(1);
    }
  }
  
  if (child == 0) {
    puts("這是子程序...");
    printf("\t 子程序 pid = %d\n", getpid());
    printf("\t 子程序 ppid = %d\n", getppid());
    printf("要購買那一種產品?(0:電腦 1:電視 2:音響)  ");
    scanf("%d",&num3);

    if (num3 >=0 && num3 <= 2)
      (*fun[num3])();

    exit(0);
  }
  else {
    waitpid(child, &status, 0);
    puts("這是父程序...");
    printf("\t 父程序 pid= %d\n", getpid());
    printf("\t 父程序 ppid = %d\n", getppid());
    printf("\t 子程序離開的狀態: %d\n", WIFEXITED(status));
    printf("輸入第1個數值: ");
    scanf("%d",&num1);
    printf("輸入第2個數值: ");
    scanf("%d",&num2);
    max_num=(*pm)(num1, num2);
    printf("最大值為 %d\n",max_num);  

    exit(0);
  }
}
  
int mymax(int x, int y)
{
  if (x > y)
    return x;
  else
    return y;
}

void disp0()
{
  printf("您購買了電腦\n");
}

void disp1()
{
  printf("您購買了電視\n");
}

void disp2()
{
  printf("您購買了音響\n");
}


    

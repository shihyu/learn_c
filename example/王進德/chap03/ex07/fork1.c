/* fork1.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  pid_t child;
  int	ans;
  char  str0[240],str1[60],str2[60],str3[60],str4[60];

  printf("是否要執行複製程序? (1:Yes, 2:No) ");
  scanf("%d",&ans);

  if (ans==1) {
    child = fork();
    if (child == -1) {
  	perror("fork error");
    	exit(1);
    }
  }

  strcpy(str1,"What a beautiful view!\n");
  strcpy(str2,"These buildings are worth seeing.\n");
  strcpy(str3,"I'd like to look around the city.\n");
  strcpy(str4,"Would you recommend some famous places to see?\n");
  strcpy(str0,"");

  
  if (child == 0) {
    puts("這是子程序...");
    printf("\t 子程序 pid = %d\n", getpid());
    printf("\t 子程序 ppid = %d\n", getppid());
    strcat(str0,str1);
    strcat(str0,str2);
    printf("%s",str0);
    printf("字串的長度為 %d\n",strlen(str0));
    exit(0);
  }
  else {
    puts("這是父程序...");
    printf("\t 父程序 pid= %d\n", getpid());
    printf("\t 父程序 ppid = %d\n", getppid());
    strcat(str0,str3);
    strcat(str0,str4);
    printf("%s",str0);
    printf("字串的長度為 %d\n",strlen(str0));
    exit(0);
  }
}  
    

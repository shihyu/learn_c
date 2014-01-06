/* pipe01.c */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fd[2];

  if ( (pipe(fd)) < 0 )
  {
    perror("pipe");
    exit(1);
  }

  printf("fd[0] 用來作讀取用,檔案識別子為 %d\n", fd[0]);
  printf("fd[1] 用來作寫入用,檔案識別子為 %d\n", fd[1]);

  close(fd[0]);
  close(fd[1]);
  exit(0);
}

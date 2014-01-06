/* myarray.c */
#include <stdio.h>
#include "myarray.h"

int main()
{
  int score[5];
  int i;
  int ans1;
  double ans2;

  printf("請輸入五個人的成績:\n");
  for (i=0; i<5; i++) {
    scanf("%d",&score[i]);
  }

  ans1=mysum(score);
  printf("五個人的成績總和為: %d 分\n",ans1);

  ans2=myavg(score);
  printf("五個人的平均成績為 %.2lf 分\n",ans2);

  return 0;
}


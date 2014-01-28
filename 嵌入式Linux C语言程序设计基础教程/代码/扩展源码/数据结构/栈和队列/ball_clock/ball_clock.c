#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sqstack.h"
#include "linkqueue.h"

#define MAX_S1   4
#define MAX_S5   11
#define MAX_S60  11

void PopAll(sqstack *s, linkqueue *lq)
{
   while (! EmptySqstack(s))
   {
      EnQueue(lq, PopStack(s));
   }

   return;
}

int CheckQueue(linkqueue *lq)
{
   linklist p;

   p = lq->front->next;

   while (p->next != NULL)
   {
      if (p->data > p->next->data)
      {
         return 0;
      }
      p = p->next;
   }
   
   return 1;
}

int main()
{
   int i, no, sum = 0;
   sqstack *s1, *s5, *s60;
   linkqueue *lq;   

   s1 = CreateEmptySqstack();
   s5 = CreateEmptySqstack();
   s60 = CreateEmptySqstack();
   
   lq = CreateEmptyLinkqueue();
   
   for(i=1; i<=27; i++)
   {
      EnQueue(lq, i);
   }
   
   while ( 1 )
   {
      sum++;
      no = DeQueue(lq);
      if (s1->top != MAX_S1 - 1)
      {
         PushStack(s1, no);
		 continue;
      }
      
	  PopAll(s1, lq);
      if (s5->top != MAX_S5 - 1)
      {
         PushStack(s5, no);
		 continue;
      }
	  PopAll(s5, lq);
      if (s60->top != MAX_S60 - 1)
      {
         PushStack(s60, no);
		 continue;
      }
               
	  PopAll(s60, lq);
	  EnQueue(lq, no);
      if ( CheckQueue(lq) ) 
      {  
      	 break;	
      }
   }
   printf("%d\n",sum);

   return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define KEYN 3
struct ele{
	int key;
	struct ele *link;
};
void basesort(struct ele **h)
{
	int i,j,factor;
	struct ele *head[10],*tail[10],*p,*u;

	for(i=0,factor=1,p=*h;i<KEYN;factor*=10,i++)
	{

		for(j=0;j<10;j++)
			head[j]=NULL;
		while(p)
		{
			u=p->link;
			j=(p->key/factor)%10;
			if(head[j]==NULL)
				head[j]=p;
			else
				tail[j]->link=p;
			tail[j]=p;
			p->link=NULL;
			p=u;
		}

		p=NULL;
		for(j=0;j<10;j++)
		{
			if(head[j]==NULL)continue;
			if(p==NULL)p=head[j];
			else u->link=head[j];
			u=tail[j];
		}
	}
	*h=p;
}
int a[]={35,298,832,932,38,635,22,15,48};
#define N sizeof a/sizeof a[0]
void main()
{
	struct ele *h,*u;
	int i;
	h=NULL;
	for(i=0;i<N;i++)
	{
		u=(struct ele *)malloc(sizeof(struct ele));
		u->key=a[i];
		u->link=h;
		h=u;
	}
	basesort(&h);
	for(u=h;u;u=u->link)
		printf("%4d",u->key);
	printf("n");
} 
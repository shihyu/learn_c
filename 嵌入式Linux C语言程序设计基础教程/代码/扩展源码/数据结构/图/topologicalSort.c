//stack.h头文件

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define STACKSIZE 50
#define STACKINCREMENT 20
#define OVERFLOW -1 
#define OK 1 
#define ERROR -1

typedef struct
{
int *base;
int *top;
int stacksize;
}Stack;

int InitStack(Stack &s) //创建一个空栈
{
s.base=(int*)malloc(STACKSIZE*sizeof(int));
if(!s.base)
   return (OVERFLOW);
s.top=s.base;
s.stacksize=STACKSIZE;
return (OK);
}

int Push(Stack &s,int e)
{
if((s.top-s.base)>s.stacksize)
{
   s.base=(int*)realloc(s.base,(STACKSIZE+STACKINCREMENT)*sizeof(int));
   if(!s.base)
    return(OVERFLOW);
   s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREMENT;
}
*s.top++=e;
return (OK);
}

bool Empty(Stack s)
{
if(s.base==s.top)
   return true;
else
   return false;
}

int Pop(Stack &s)
{
int e;
e=*--s.top;
return e;
}

//graph.h文件


//有向无环图的拓扑排序

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 20
#define NULL 0

typedef struct ArcNode       //头节点
{
int adjvex;              //该边所指向的顶点的位置
struct ArcNode *nextarc; //指向下一条边
}ArcNode;

typedef struct VNode           //表节点
{
int data;    //顶点信息
int indegree;         //节点的入度
ArcNode *firstarc;       //指向第一条依附该节点的边的指针
}VNode,AdjList[MAX];

typedef struct 
{
AdjList vertices;     //表节点
int vexnum;           //节点的个数
int arcnum;           //边的条数
}Graph;


int LocateVex(Graph G,int v)    //返回节点v在图中的位置
{
int i;
for(i=0;i<G.vexnum;++i)
   if(G.vertices[i].data==v)
     break;
   else
    continue;
if(i<G.vexnum)
    return i;
else 
   return -1;
}

void CreateGraph(Graph &G)
{
int m,n;
printf("请输入图的节点数: ");
scanf("%d",&m);
while(m<0)
{
   printf("Error!\n顶点数不能小于1.\n");
   printf("请重新输入图的顶点数: ");
   scanf("%d",&m);
}
printf("请输入图的边数: ");
scanf("%d",&n);
while(n<0)
{
   printf("Error!\n图的边数不能小于0.\n");
   printf("请重新输入图的边数: ");
   scanf("%d",&n);
}
G.vexnum=m;            //顶点数目
G.arcnum=n;            //边的数目
int i,j,k;
for(i=0;i<G.vexnum;++i)       //初始化图的信息
{
   G.vertices[i].data=i+1;      //顶点信息
   G.vertices[i].firstarc=NULL;
   G.vertices[i].indegree=0;      //开始时入度都为0
}
    //顶点信息
printf("输出顶点信息:\n");
for(i=0;i<G.vexnum;++i)
   printf("v%d\n",G.vertices[i].data);

    int v1,v2,flag=0;
for(k=0;k<G.arcnum;++k)
{
   printf("请输入第%d边的起点和终点: ",k+1);
   scanf("%d%d",&v1,&v2);

   i=LocateVex(G,v1);       //顶点v1在图中的位置
   j=LocateVex(G,v2);       //顶点v2在图中的位置

   if(i >=0 && j>=0)
   {
    ++flag;
    (G.vertices[j].indegree)++;
    ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=j;
     p->nextarc=NULL;
     ArcNode *p1;
            if(! G.vertices[i].firstarc)
                 G.vertices[i].firstarc=p;
     else
    {
      for(p1=G.vertices[i].firstarc;p1->nextarc;p1=p1->nextarc); //求该顶点的最后一个邻接顶点
      p1->nextarc=p;                //将p插入到最后一个邻接顶点的后面
    }
   }
   else       //没有该弧，删除掉
   {
    printf("没有该边!\n");
    k=flag;
   }
     
}

//输出邻接表
printf("构造的邻接表为:\n");
printf("位置 顶点 弧\n");
for(i=0;i<G.vexnum;++i)
{
     printf(" %d     v%d",i,G.vertices[i].data);
   ArcNode *p=G.vertices[i].firstarc;
   if(p)
   {
    while(p->nextarc)
    {
        printf("->v%d",p->adjvex+1);
        p=p->nextarc;
    }
    printf("->v%d\n",p->adjvex+1);
   }
   else
    printf("\n");
}
printf("输出个顶的的入度:\n");
for(i=0;i<G.vexnum;++i)
{
   printf("%d顶点的入度为: %d\n",G.vertices[i].data,G.vertices[i].indegree);
}
}


int FirstAdjVex(Graph G,int v) //返回v的第一个邻接顶点
{
if(G.vertices[v].firstarc)
   return G.vertices[v].firstarc->adjvex;
else
   return -1;
}

int NextAdjVex(Graph G,int v,int w) //返回v中相对于w的下一个邻接顶点
{
int flag=0;
ArcNode *p;
p=G.vertices[v].firstarc;
while(p)
{
   if(p->adjvex==w)
   {
    flag=1;
    break;
   }
   p=p->nextarc;
}
if(flag && p->nextarc)
   return p->nextarc->adjvex;
else
   return -1;
}

bool Visited[MAX];

//深度优先遍历
void DFS(Graph G,int v)
{
Visited[v]=true;
    printf("v%d ",G.vertices[v].data);
int w;
for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
   if(!Visited[w])
    DFS(G,w);
}

void DFSTraverse(Graph G)
{
int v;
for(v=0;v<G.vexnum;++v)
   Visited[v]=false;
for(v=0;v<G.vexnum;++v)
   if(!Visited[v])
    DFS(G,v);       //递归
}

//main.cpp文件

#include "graph.h"
#include "stack.h"

void TopologicalSort(Graph G) //拓扑排序函数
{
int i,j,k;
int count=0;    //用来统计顶点的个数
Stack s; //定义一个栈，用来保存入度为0的顶点
InitStack(s); //初始化栈
for(i=0;i<G.vexnum;++i)
   if(G.vertices[i].indegree==0)    //若第i个顶点的入度为0 ，i表示顶点在图中的位置
    Push(s,i);                  //将第i个顶点入栈
while(!Empty(s))
{
   j=Pop(s);       // 将为入度0的顶点位置出栈，并保存到j中
   count++;        //统计顶点的个数
   printf("v%d ",G.vertices[j].data); //输出入度为0的顶点
        ArcNode *p;
   for(p=G.vertices[j].firstarc; p ;p=p->nextarc)   //找与第j个顶点的邻接顶点，并将其入度减1
   {
    k=p->adjvex;
    --(G.vertices[k].indegree);
    if(G.vertices[k].indegree==0)    //如果入度为0,就入栈
     Push(s,k);
   }
}
if(count<G.vexnum)   //count小于顶点的个数时候，说明有环，不符合拓扑排序的要求
{
   printf("Error!\n图中有环!不是有向无环图!\n");
   exit(0);               //退出
}
}
  
//主函数的实现
void main()
{
Graph G;
CreateGraph(G);
printf("\n深度优先遍历输出为:\n");
DFSTraverse(G);
printf("\n拓扑排序为: \n");
TopologicalSort(G);
printf("\n");
}

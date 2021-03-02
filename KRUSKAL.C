#include<stdio.h>
#include<stdlib.h>
struct node
{ struct setObject *top;
int data;
struct node *next; };

struct setObject
{ struct node *head;
struct node *tail; };

struct edge
{ int start;
int weight;
int end; };

struct node * nodelist[20];
int n;
struct setObject * find(int x)
{ int i,flag=0;
for(i=1;i<=n;i++)
{ if (nodelist[i]->data==x)
{ flag=1; 
  break; }
}
if (flag==1)
return nodelist[i]->top;
else
return NULL;
}

void unions(int x,int y)
{ struct node *ptr;
struct setObject *ptrx,*ptry;
int i;
ptrx=find(x);
ptry=find(y);
if (ptrx!=ptry)
{ ptrx->tail->next=ptry->head;
ptrx->tail=ptry->tail;
ptr=ptry->head;
while(ptr!=NULL)
{ ptr->top=ptrx;
ptr=ptr->next;}
free(ptry); }
}

void main()
{ int i,opt,x,s,e,k,c,count,en,w,u,v,sum=0;
struct node *ne;
struct edge *A,*adj;
struct setObject *p;
clrscr();
printf("\nEnter no of vertices:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
ne=(struct node *)malloc(sizeof(struct node));
ne->data=i;
ne->next=NULL;
nodelist[i]=ne;
p=(struct setObject*)malloc(sizeof(struct setObject));
p->head=ne;
p->tail=ne;
ne->top=p;
}
printf("\nEnter the no of edjes:\n");
scanf("%d",&e);
adj=(struct edge*)malloc(e*sizeof(struct edge));
A=(struct edge*)malloc(e*sizeof(struct edge));
printf("\nEnter the edjes\n");
printf("start end weight\n");
c=-1;
for(i=1;i<=e;i++)
{ scanf("%d%d%d",&s,&en,&w);
for(k=c;k>=0;k--)
{ if (adj[k].weight>w)
 adj[k+1]=adj[k];
else
 break;}
adj[k+1].start=s;
adj[k+1].end=en;
adj[k+1].weight=w;
c++; }
count=0;
for(i=0;i<c;i++)
{ u=adj[i].start;
v=adj[i].end;
if (find(u)!=find(v))
{ A[count].start=u;
A[count].end=v;
A[count].weight=adj[i].weight;
unions(u,v);
count++; }
}
printf("\nSpanning Tree edges\n");
sum=0;
for(i=0;i<count;i++)
{ printf("(%d->%d)w:%d\n",A[i].start,A[i].end,A[i].weight);
sum=sum+A[i].weight; }
printf("\nTotal Cost=%d",sum);
getch();
}
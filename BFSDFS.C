#include<stdlib.h>
#include<stdio.h>
struct node
{ int vertex;
struct node *next;
};
int v,e;
struct node **adj;
int *que,*visited,*top;
int f=-1,r=-1,t=0;
void dfs();
void dfsvisit();
void enq(int x)
{ if (f==-1 && r==-1)
f=0;
r=(r+1)%v;
que[r]=x;
}
int dequ()
{ int data;
data=que[f];
if (f==r)
f=r=-1;
else
f=(f+1)%v;
return data;
}

void bfs()
{ struct node *ptr;
int ver,i,w;
visited=(int *)malloc((v+1)*sizeof(int));
que=(int *)malloc((v+1)*sizeof(int));
for(i=0;i<=v;i++)
visited[i]=0;
enq(1);
visited[1]=1;
printf("%d",1);
while(!(f==-1))
{ ver=dequ();
ptr=adj[ver];
while(ptr!=NULL)
{ w=ptr->vertex;
if (visited[w]==0)

{ enq(w);
printf("%d",w);
visited[w]=1;
}
ptr=ptr->next;
}
}
}

void main()
{ int s,i,en;
struct node *ne;
clrscr();
printf("Enter no of vertices\n");
scanf("%d",&v);
adj= (struct node **)malloc((v+1)*sizeof(struct node *));
for(i=0;i<=v;i++)
adj[i]=NULL;
printf("enter no of Edges\n");
scanf("%d",&e);
printf("Enter the edges\n");
printf("start End\n");
for(i=0;i<e;i++)
{ scanf("%d%d",&s,&en);
ne=(struct node*)malloc(sizeof(struct node));
ne->vertex=en;
ne->next=adj[s];
adj[s]= ne;
}
printf("\nbfs\n");
bfs();
dfs();
printf("\nTopological sort order is \n");
for(i=t-1;i>=0;i--)
printf("%d",top[i]);
getch();
}

void dfs()
{ int i;
visited=(int*)malloc((v+1)*sizeof(int));
top=(int*)malloc(v*sizeof(int));
for(i=0;i<=v;i++)
visited[i]=0;
printf("\ndfs\n");
for(i=1;i<=v;i++)
if (visited[i]==0)
dfsvisit(i);
}
void dfsvisit(int u)
{ int w;
struct node *ptr;
visited[u]=1;
printf("%d",u);
ptr=adj[u];
while(ptr!=NULL)
{ w=ptr->vertex;
if(visited[w]==0)
dfsvisit(w);
ptr=ptr->next;}
top[t++]=u;
}
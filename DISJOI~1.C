#include <stdio.h>
#include<stdlib.h>

struct node
{
struct setObject *top;
int data;
struct node *next;
};
struct setObject
{
struct node *head;
struct node *tail;
};
struct node * nodelist[20];
int n;
void display()
{ int i,j,count=0,flag=0;
struct node *p1;
struct setObject *ptr,*p[20];
for(i=0;i<n;i++)
{ ptr=nodelist[i]->top;
flag=0;
for(j=0;j<count;j++)

{ if (p[j]==ptr)
{ flag=1;
break;
}
}
if (flag==0)
{
printf("{");
p1=ptr->head;
while(p1!=NULL)
{ printf("%d",p1->data);
p1=p1->next;
}
printf("}\n");
p[count++]=ptr;
}
}
}
struct setObject * find(int x)
{
int i,flag=0;
for(i=0;i<n;i++)
{ if (nodelist[i]->data==x)
{flag=1; break; }
}

if (flag==1)
return nodelist[i]->top;
else
return NULL;
}

void unions()
{ struct node *ptr;
struct setObject *ptrx,*ptry;
int x,y,i;
printf("Enter the elements to join\n");
scanf("%d%d",&x,&y);
ptrx=find(x);
ptry=find(y);
if (ptrx!=ptry)
{ ptrx->tail->next=ptry->head;
ptrx->tail=ptry->tail;
ptr=ptry->head;
while(ptr!=NULL)
{ ptr->top=ptrx;
ptr=ptr->next;
}
free(ptry);
}
}

void main()
{ int i,opt,x;
struct node *ne;
struct setObject *p;
clrscr();
printf("Enter no. of elements\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{ ne=(struct node *)malloc(sizeof(struct node));
scanf("%d",&ne->data);
ne->next=NULL;
nodelist[i]=ne;
p=(struct setObject*)malloc(sizeof(struct setObject));
p->head=ne;
p->tail=ne;
ne->top=p;
}
while(opt!=4)
{ printf("1.Union\n2.Find\n3.Display\n4.Exit\n");
printf("enter your choice\n");
scanf("%d",&opt);
switch(opt)
{ case 1:unions();
break;

case 2:printf("Enter element to find\n");
scanf("%d",&x);
p=find(x);
if (p!=NULL)
printf("\nThe representative of the set is %d",p->head->data);
else
printf("Element not present\n");
break;

case 3:display();
break; } 
}
return;
}
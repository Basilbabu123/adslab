#include<stdio.h>
#include<conio.h>
void insert(int *);
void search(int *);
void deleete(int *);
void display(int *);
int i,f,x,n=5;
int front=-1;
int rear=-1;
void main()
{int q[20],opt;
clrscr();
while(1)
{printf("Menu\n");
printf("1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.EXIT\nEnter ur option");
scanf("%d",&opt);
switch(opt)
{ case 1:insert(q);
	 break;
 case 2:deleete(q);
	 break;
case 3:search(q);
	 break;
case 4:display(q);
	 break;
case 5:printf("gud bye");
exit();
}
}
}
void insert(int *q)
{printf("entr lment");
scanf("%d",&x);
if(front==(rear+1)%n)
{
printf("the Queue is full\n");
return;}

 if(front==-1)
 front=0;
 rear=(rear+1)%n;
 q[rear]=x;


}
 void deleete(int *q)
 {if(front==-1)
 {printf("queue is empty");
    return;
 }
 printf("deleted element%d",q[front]);
if(front==rear)
front=rear=-1;
else
front=(front+1)%n;
}
void search(int *q)
{ int f,pos;
printf("enter lment searched\n");
scanf("%d",&x);
if(front==-1)
{printf("queue is empty\n");
return;
}
f=front;
pos=1;
while(1)
{
  if(q[f]==x)
  {
printf("\nlment found at location %d",pos);
break;
  }
if(f==rear)
{
printf("\nlment not founded");
return;
}
f=((f+1)%n);
pos=pos+1;
}
   }
void display(int *q)
{
if(front==-1)
{
printf("qeue is empty\n");
return;
}
f=front;
while(1)
{
printf("elements are%d\t",q[f]);
if(f==rear)
break;
f=(f+1)%n;
}
}
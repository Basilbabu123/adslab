#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{int data;
struct node *link;

};
struct node *top=NULL;
void push()
{ struct node *ne;
ne=(struct node*)malloc(sizeof(struct node));
if(ne==NULL)
{
printf("stk full");
return;
}
printf("enter element to push\n");
scanf("%d",&ne->data);
ne->link=top;
top=ne;

}

void pop()
{struct node *ptr;
if(top==NULL)
{printf("stack is empty\n");
return;
}
printf("popped element is %d",top->data);
ptr=top;
top=top->link;
free(ptr);
}
void search()
{struct node *ptr;
int x,pos=1;
if(top==NULL)
{printf("stackempty\n");
return;
}
ptr=top;
printf("enter element to search\n");
scanf("%d",&x);
while(ptr!=NULL)
{if(ptr->data==x)
{printf("element found at %d pos from top\n",pos);
break;
}ptr=ptr->link;
pos++;
}if(ptr==NULL)
printf("element not found");
 }
void display()
{ struct node *ptr=top;
if(top==NULL)
{printf("stack empty\n");
return;
}
ptr=top;
printf("elements are \n");
while(ptr!=NULL)
{printf("%d",ptr->data);
ptr=ptr->link;

}
}
void main()
{
int ch=0;
clrscr();
while(ch!=5)
{
printf("\n 1.push 2.pop 3.search 4.display 5.Exit\n ");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
	break;
case 2:pop();
	break;
case 3:search();
	break;
case 4:display();
	break;
case 5:printf("goodbye");
getch();
}
}
}
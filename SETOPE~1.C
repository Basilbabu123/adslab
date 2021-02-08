#include<stdio.h>
#include<conio.h>
#include<math.h>
void assign(char *set1,int *p) 
{ int i,x,j;
for(i=strlen(set1)-1,j=0;i>=0;i--,j++) 
{ if (set1[i]=='1')
x=1;
else
x=0;
*p=*p+x*((int)pow(2,j));
 }
}
void display(int s3,int l)
{ int i;
for(i=l-1;i>=0;i--)
{ printf("%d",(s3&(int)pow(2,i))>>i);
}
}

void main()
{ int s1,s2,s3;
char set1[20],set2[20];
int i,l;
clrscr();

s1=s2=s3=0;
printf("Enter set1\n");
scanf("%s",set1);
printf("Enter set2\n");
scanf("%s",set2);
l=strlen(set1);
if (l!=strlen(set2))
{ printf("not possible to perform the operations\n");}
else
{
assign(set1,&s1);
assign(set2,&s2);
printf("Set1:");
display(s1,l);
printf("\nSet2:");
display(s2,l);
s3=s1&s2;
printf("\nINTERSECTION:\n");
display(s3,l);
s3=s1|s2;
printf("\nUNION:\n") ;
display(s3,l);
s2=~s2;
s3=s1&s2;
printf("\nDIFFERENCE:\n");
display(s3,l); }
getch(); }
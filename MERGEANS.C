#include<stdio.h>
#include<conio.h>
void read(int [],int);
int merge(int [],int,int [],int,int []);
void main()
{  int a[10],b[10],i,c[10],m,n,k,j;
  clrscr();
  printf("enter size of first array\n");
  scanf("%d",&m);
  printf("enter first array in sorted order\n");
  read(a,m);
   printf("enter size of second array\n");
  scanf("%d",&n);
  printf("enter second array in sorted order\n");
  read(b,n);
  k=merge(a,m,b,n,c);
  printf("the merged array is\n");
  for(i=0;i<k;++i)
  {
  printf("%d\t",c[i]);
  }
  getch();
  }
  void read(int *p,int n)
  { int i;
  for(i=0;i<n;++i)
  scanf("%d",&p[i]);
  for(i=0;i<n;++i)
  printf("%d\t",*(p+i));
  }

  int merge(int a[],int m,int b[],int n,int c[])
  {
  int k=0,i=0,j=0;
  while((i<m)&&(j<n))
  {
    if(a[i]<b[j])
    { c[k]=a[i];
      ++i;
      }
      else if(a[i]>b[j])
      {
       c[k]=b[j];
	++j;
	}
	 else{
	 c[k]=b[j];
	   ++j;
	   ++i;}
	k++;
	}
    while(i<m)
    {
    c[k]=a[i];
    ++i;
    ++k;
    }
    while(j<n)
    {c[k]=b[j];
    ++k;
    ++j;
    }
     return(k);
     }


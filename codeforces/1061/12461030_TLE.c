#include<stdio.h>

int main()
{
  long x,y,m,n,l;
  long i,j;
  scanf("%ld %ld %ld %ld %ld",&x,&y,&m,&n,&l);
  if(m>0&&n>0)
  for(i=0;i<=100000000;i++)
    {
     if(((n-m)*i+(y-x))%l==0)break;
  }
  printf("%d\n",i);
  return 0;
}

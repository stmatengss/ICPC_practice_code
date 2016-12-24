#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const double eps=1e-6;
int n,k;
struct node2
{
    double res;
    int num;
}value[100005];
struct node1
{
    int v, w, num;
}j[100005];
bool qrt(node2 f,node2 s)
{
    return (f.res)>(s.res);
}
int main()
{
   while(scanf("%d%d",&n,&k)!=EOF)
   {
       for(int i=0;i<n;i++)
       {
            scanf("%d%d",&j[i].v,&j[i].w);
            j[i].num=i;
       }
           double ub=1<<29,lb=0;
           while(ub-lb>eps)
           {
               double mid=(ub+lb)/2;
               for(int i=0;i<n;i++)
               {
                   value[i].res=j[i].v-mid*j[i].w;
        value[i].num=i;
               }
               sort(value,value+n,qrt);
               double sum=0;
               for(int i=0;i<k;i++)
                sum+=value[i].res;
                if(sum>=0)
                lb=mid;
                else ub=mid;
           }
           for(int i=0;i<k;i++)
            printf("%d%c",value[i].num+1,(i==k-1)?'\n':' ');
   }
    return 0;
}

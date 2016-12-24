////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-03 14:26:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4082
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:764KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<cstring>
#define eps 0.00000001
using namespace std;

typedef struct point{
       double x;
       double y;
       };
       
typedef struct triangle{
       double l1;
       double l2;
       double l3;
       };

point po[20];
triangle tr[20000];
int i,j,k;
int n;
int N;
int temp1,temp2;
double tempa[3];
int st[300][300];
int flag[15000];
    int NN;
int sum;
int Max;

bool equal(double a,double b)
{
     if(fabs(a-b)<eps)return true;
     return false;
}

double dis(point a,point b)
{
       return sqrt((a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x));
}

int main()
{
    while(1)
    {
       cin>>n;
       if(n==0)break;
       
       memset(st,0,sizeof(st));
       memset(flag,0,sizeof(flag));
       N=1;
       NN=1;
       Max=0;
       
       for(i=1;i<=n;i++)
       {
          cin>>temp1>>temp2;
          if(st[temp1+150][temp2+150]==1)continue;
          st[temp1+150][temp2+150]=1;
          po[N].x=temp1;
          po[N].y=temp2;
          N++;
       }
       N--;
       for(i=1;i<=N;i++)
          for(j=i+1;j<=N;j++)
             for(k=j+1;k<=N;k++)
             {
       //if(qual((p[j].y-p[i].y)*(p[k].x-p[i].x),(p[k].y-p[i].y)*(p[j].x-p[i].x)))
                if(equal( (po[i].y-po[j].y)*(po[i].x-po[k].x) , (po[i].y-po[k].y)*(po[i].x-po[j].x) ))continue;
                tempa[0]=dis(po[i],po[j]);
                tempa[1]=dis(po[j],po[k]);
                tempa[2]=dis(po[i],po[k]);
                {
                      sort(tempa,tempa+3);
                      tr[NN].l1=tempa[0];
                      tr[NN].l2=tempa[1];
                      tr[NN].l3=tempa[2]; 
                }
                //cout<<tempa[0]<<' '<<tempa[1]<<' '<<tempa[2]<<endl;
                NN++;
             }
             NN--;
       for(i=1;i<=NN;i++)
       {
          sum=1;
          if(flag[i]==0)
          for(j=i+1;j<=NN;j++)
          {
//if(qual(l[0]*tb.l[2],tb.l[0]*l[2])&&qual(l[0]*tb.l[1],tb.l[0]*l[1]))
              if(flag[j]==0)
              {
                 if(equal(tr[i].l1*tr[j].l2,tr[j].l1*tr[i].l2)&&equal(tr[i].l1*tr[j].l3,tr[j].l1*tr[i].l3))
                 {
                    sum++;
                    flag[j]=1;
                 }
              }
          }
          if(sum>Max)Max=sum;
       }
       cout<<Max<<endl;
    }
    return 0;
}


/*
6
-1 -1
1 1
1 2
2 2
4 4
4 2
5
0 0
1 0
0 1
2 0
0 2
6
1 1
2 2
3 1
1 3
3 3
4 2
5
1 1
1 3
3 1
3 3
2 2
6
1 1
1 1
1 3
3 1
3 3
2 2
5
0 0
3 0
100 0
0 3
0 100
*/

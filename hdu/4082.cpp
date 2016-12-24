////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-03 14:15:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4082
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:500KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
const double eps=0.00000001;
using namespace std;
struct po//点类
{
    double x;
    double y;
} p[30];
double dis(po a,po b)//计算两点之间距离
{
    double x=b.x-a.x;
    double y=b.y-a.y;
    return sqrt(x*x+y*y);
}
bool qual(double a,double b)//判断两个浮点数是否相等
{
    if(fabs(a-b)<eps)
        return true;
    else
        return false;
}
class tra//三角形类
{
public:
    double l[3];//三条边
    tra(po a,po b,po c)//用三个点构造一个三角形
    {
        l[0]=dis(a,b);
        l[1]=dis(a,c);
        l[2]=dis(b,c);
        sort(l,l+3);//升序
    }
    bool same(tra &tb)//判断相似
    {
        if(qual(l[0]*tb.l[2],tb.l[0]*l[2])&&qual(l[0]*tb.l[1],tb.l[0]*l[1]))
            return true;
        else
            return false;
    }
    tra() {}
} tran[100000];
int n,cnt,ptr,ans;
bool vis[100000];
bool use[300][300];
int main()
{
    int i,j,k,sum,a,b;

    while(scanf("%d",&n),n)
    {
        memset(vis,0,sizeof vis);
        memset(use,0,sizeof use);
        ptr=cnt=ans=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            if(use[a+100][b+100])//注意判重点！！！
                continue;
            use[a+100][b+100]=true;
            p[ptr].x=a;
            p[ptr++].y=b;
        }
        for(i=0; i<ptr; i++)
            for(j=i+1; j<ptr; j++)
                for(k=j+1; k<ptr; k++)
                {
                    if(qual((p[j].y-p[i].y)*(p[k].x-p[i].x),(p[k].y-p[i].y)*(p[j].x-p[i].x)))
                        continue;//判断三点共线
                    tran[cnt++]=tra(p[i],p[j],p[k]);
                }
        for(i=0; i<cnt; i++)//统计相似三角形
        {
            sum=1;
            for(j=i+1; j<cnt; j++)
            {
        //if(qual(l[0]*tb.l[2],tb.l[0]*l[2])&&qual(l[0]*tb.l[1],tb.l[0]*l[1]))
                if(tran[i].same(tran[j])&&!vis[j])
                {
                    sum++;
                    vis[j]=true;
                }
            }
            if(sum>ans)
                ans=sum;
        }
        printf("%d\n",ans);
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

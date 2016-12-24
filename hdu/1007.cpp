////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-08 00:27:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:811MS
////Run memory:4724KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

const double eps = 1e-6;
const int MAXN = 100010;
const double INF = 1e20;
struct Point
{
double x,y;
};
double dist(Point a,Point b)
{
return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
Point p[MAXN];
Point tmpt[MAXN];
bool cmpxy(Point a,Point b)
{
if(a.x != b.x)return a.x < b.x;
else return a.y < b.y;
}
bool cmpy(Point a,Point b)
{
return a.y < b.y;
}
double Closest_Pair(int left,int right)
{
double d = INF;
if(left == right)return d;
if(left + 1 == right)
return dist(p[left],p[right]);
int mid = (left+right)/2;
double d1 = Closest_Pair(left,mid);
double d2 = Closest_Pair(mid+1,right);
d = min(d1,d2);
int k = 0;
for(int i = left;i <= right;i++)
{
if(fabs(p[mid].x - p[i].x) <= d)
tmpt[k++] = p[i];
}
sort(tmpt,tmpt+k,cmpy);
for(int i = 0;i <k;i++)
{
for(int j = i+1;j < k && tmpt[j].y - tmpt[i].y < d;j++)
{
d = min(d,dist(tmpt[i],tmpt[j]));
}
}
return d;
}
int main()
{
int n;
while(scanf("%d",&n)==1 && n)
{
for(int i = 0;i < n;i++)
scanf("%lf%lf",&p[i].x,&p[i].y);
sort(p,p+n,cmpxy);
printf("%.2lf\n",Closest_Pair(0,n-1)/2);
}
return 0;
}
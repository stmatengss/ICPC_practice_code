////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-20 16:03:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3172
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:5136KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int father[200004],rk[200004],num[200004];
int n;
map<string,int>mp;

void init()
{
    int i;
    mp.clear();
    for(i=1;i<=2*n;i++)
    {
        father[i]=i;
        rk[i]=0;
        num[i]=1;
    }
}

int find(int x)
{
    if(x==father[x])return x;
    return father[x]=find(father[x]);
}

void unin(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        printf("%d\n",num[x]);
    }
    else
    {
        printf("%d\n",num[x]+num[y]);
        if(rk[x]<rk[y])
        {
            father[x]=y;
            num[y]+=num[x];
        }
        else
        {
            if(rk[x]==rk[y])rk[x]++;
            father[y]=x;
            num[x]+=num[y];
        }
    }
}


int main()
{
    int t;
    int i,j;
    string x,y;
    char xx[30],yy[30];
    int counter;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            counter=1;
            scanf("%d",&n);
            init();
            for(i=0;i<n;i++)
            {
                scanf("%s %s",xx,yy);
                x=xx,y=yy;
                if(mp.find(x)==mp.end())mp[x]=counter++;
                if(mp.find(y)==mp.end())mp[y]=counter++;
                unin(mp[x],mp[y]);
            }
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}
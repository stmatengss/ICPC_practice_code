////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-05 15:32:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3172
////Problem Title: 
////Run result: Accept
////Run time:998MS
////Run memory:3568KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

map<string,int>mp;
int father[100007];
int num[100007];
int rk[100007];
char tmp1[24],tmp2[24];
string s;
int ans;

int find(int x)
{
    if(father[x]==x)return x;
    return father[x]=find(father[x]);
}

void unin(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
//        cout<<"0"<<endl;
        cout<<num[x]<<endl;
        return ;
    }
    if(rk[x]<rk[y])
    {
        father[x]=y;
        num[y]+=num[x];
        cout<<num[y]<<endl;
    }
    else
    {
        if(rk[x]==rk[y])rk[x]++;
        father[y]=x;
        num[x]+=num[y];
        cout<<num[x]<<endl;
    }
}

void init()
{
    int i;
    for(i=1;i<=100004;i++)
        father[i]=i,rk[i]=0,num[i]=1;
}

int main()
{
    int t;
    int n;
    int i,j;
    int x,y;
    while(cin>>t)
    {
        while(t--)
        {
            mp.clear();
            init();
            ans=1;
            cin>>n;
            for(i=0;i<n;i++)
            {
                 scanf("%s %s",tmp1,tmp2);
                 s=tmp1;
//                 cout<<s<<endl;
                 if(mp.find(s)==mp.end())
                 {
                    mp[s]=ans++;
                 }
                 x=mp[s];
                 s=tmp2;
//                 cout<<s<<endl;
                 if(mp.find(s)==mp.end())
                 {
                    mp[s]=ans++;
                 }
                 y=mp[s];
//                 cout<<x<<" "<<y<<endl;
                 unin(x,y);
            }
        }
    }
    return 0;
}
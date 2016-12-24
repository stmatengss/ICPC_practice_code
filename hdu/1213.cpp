////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 14:06:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

int father[1004];
int ra[1004];
int n,m;

void init()
{
    int i;
    for(i=1;i<=n;i++)
    {
        father[i]=i;
        ra[i]=0;
    }
}

int find(int x)
{
    if(x==father[x])
        return x;
    return father[x]=find(father[x]);
}

bool unin(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return false;
    }
    else
    {
        if(ra[x]>ra[y])
        {
            father[y]=x;
        }
        else
        {
            if(ra[x]==ra[y])
                ra[x]++;
            father[x]=y;
        }
        return true;
    }
}

int main()
{
    int i,j;
    int x,y;
    int t;
    int counter=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init();
        counter=0;
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(unin(x,y))counter++;
        }
        cout<<(n-counter)<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

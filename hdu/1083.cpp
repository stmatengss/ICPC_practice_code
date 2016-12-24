////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 17:21:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:1388MS
////Run memory:2116KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int  g[304][304];
bool used[304];
int  from[304];
int n,m;

bool match(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(g[x][i]==1&&used[i]==false)
        {
            used[i]=true;
            if(from[i]==0||match(from[i]))
            {
                from[i]=x;
                return true;
            }
        }
    }
    return false;
}

void hungry()
{
    int counter=0;
    memset(from,0,sizeof(from));
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if(match(i))counter++;
    }
    if(counter==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int t;
    int s,num;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=s;j++)
            {
                cin>>num;
                g[i][num]=1;
            }
        }
        hungry();
    }
//    cout << "Hello world!" << endl;
    return 0;
}

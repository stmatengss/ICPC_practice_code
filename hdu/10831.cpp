////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 17:22:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:1960KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int>g[304];
bool used[304];
int from[304];
int n,m;

bool match(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(used[g[x][i]]==false)
        {
            used[g[x][i]]=true;
            if(from[g[x][i]]==0||match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                return true;
            }
        }
    }
    return false;
}

void hungry()
{
    int counter=0;
    fill(from,from+m+1,0);
    for(int i=1;i<=n;i++)
    {
        fill(used,used+m+1,false);
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
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            cin>>s;
            for(int j=1;j<=s;j++)
            {
                cin>>num;
                g[i].push_back(num);
            }
        }
        hungry();
    }
//    cout << "Hello world!" << endl;
    return 0;
}

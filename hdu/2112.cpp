////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-20 14:51:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:3260MS
////Run memory:2488KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include<cstring>

using namespace std;

const int maxn=300;
const int INF=1<<29;
struct edge{int to,cost;edge(){};edge(int to,int cost):to(to),cost(cost){}};
typedef pair<int,int>P;
int V;
vector<edge>G[maxn];
int d[maxn];
map<string,int>mp;
int dist[300][300];


void dijkstra(int s,int en)
{
    priority_queue<P, vector<P>,greater<P> >que;
    for(int i=0;i<maxn;i++)
    {
        d[i]=INF;
    }
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if(d[en]==INF)
        cout<<"-1"<<endl;
    else
        cout<<d[en]<<endl;
}

int main()
{
    int n;
    string begin,end,x,y;
    int value,i,t;
    while(cin>>n)
    {
        if(n==-1)
        break;
        
        t=0;
        cin>>begin>>end;
        memset(dist,0x7f,sizeof(dist));
        mp.clear();
        for(i=0;i<=300;i++)G[i].clear();
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>value;
            if(mp.find(x)==mp.end())
                mp[x]=t++;
            if(mp.find(y)==mp.end())
                mp[y]=t++;
//            if(dist[mp[x]][mp[y]]<=value)
//            {
//                continue;
//            }
//            dist[mp[x]][mp[y]]=value;
            G[mp[x]].push_back(edge(mp[y],value));
            G[mp[y]].push_back(edge(mp[x],value));
        }
        V=t+2;
        if(begin==end)
            cout<<"0"<<endl;
        else if(mp.find(begin)==mp.end()||mp.find(end)==mp.end())
            cout<<"-1"<<endl;
        else
            dijkstra(mp[begin],mp[end]);
    }
//    cout << "Hello world!" << endl;
    return 0;
}
/*
6
xiasha westlake
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
6
xiasha xiasha
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
*/

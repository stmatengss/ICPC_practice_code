////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 19:29:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1195
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int beginnum,endnum;
int used[10004];
typedef pair<int,int> po;
int tab[6]={1,10,100,1000,10000};

int cal(int bit[4])
{
    int res=0;
    for(int i=3;i>=0;i--)
    {
        res+=bit[3-i]*tab[i];
    }
    return res;
}

void bfs()
{
    int i,j;
    int num,rk;
    int res[4];
    int tmp[4];
    queue<po>q;
    q.push(po(beginnum,0));
    used[beginnum]=1;
    while(!q.empty())
    {
        num=q.front().first,rk=q.front().second;
        q.pop();
//        cout<<num<<endl;
        if(num==endnum)
        {
            cout<<rk<<endl;
            return;
        }
        for(i=4;i>=1;i--)
            res[4-i]=num%tab[i]/tab[i-1];
        for(i=0;i<=3;i++)
        {
            copy(res,res+4,tmp);
            tmp[i]=res[i]==9?1:res[i]+1;
            num=cal(tmp);
            if(used[num]==0)q.push(po(num,rk+1)),used[num]=1;
            copy(res,res+4,tmp);
            tmp[i]=res[i]==1?9:res[i]-1;
            num=cal(tmp);
            if(used[num]==0)q.push(po(num,rk+1)),used[num]=1;
        }
        for(i=0;i<=2;i++)
        {
            copy(res,res+4,tmp);
            swap(tmp[i],tmp[i+1]);
            num=cal(tmp);
            if(used[num]==0)q.push(po(num,rk+1)),used[num]=1;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(used,0,sizeof(used));
        cin>>beginnum>>endnum;
        bfs();
    }
//    cout << "Hello world!" << endl;
    return 0;
}
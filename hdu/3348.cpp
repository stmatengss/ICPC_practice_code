////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-22 20:02:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3348
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1576KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int v[6]={1,5,10,50,100};

int c[6];
int a;

bool solve()
{
    int A=a;
    int ans=0;
    for(int i=4;i>=0;i--)
    {
        int t=min(A/v[i],c[i]);
        A-=t*v[i];
        ans+=t;
    }
    if(A==0)
    {
        cout<<ans<<" ";
        return true;
    }
    else
    {
        cout<<"-1"<<" ";
        return false;
    }

}

void solve1()
{
    int sum=0;
    int sumnum=0;
    for(int i=0;i<=4;i++)
        sum+=v[i]*c[i],sumnum+=c[i];
    int A=sum-a;
    int ans=0;
    for(int i=4;i>=0;i--)
    {
        int t=min(A/v[i],c[i]);
        A-=t*v[i];
        ans+=t;
    }
    cout<<(sumnum-ans)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>c[0]>>c[1]>>c[2]>>c[3]>>c[4];
        if(solve())
            solve1();
        else
            cout<<"-1"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

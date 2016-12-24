////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-18 20:50:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3555
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll dp[24][3];

void table()
{
    int i;
    dp[0][0]=1;
    for(i=1;i<=21;i++)
    {
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
    }
}

int main()
{
    ll n;
    int i,j,k;
    int t;
    table();
    cin>>t;
    while(t--)
    {
        cin>>n;
        n++;
        ll res=0;
        bool st;
        vector<int>num;
        while(n)
        {
            num.push_back(n%10);
            n/=10;
        }
        st=false;
        for(i=num.size()-1;i>=0;i--)
        {
            res+=dp[i][2]*num[i];
            if(st)
            {
                res+=dp[i][0]*num[i];
            }
            else
            {
                if(num[i]>4)
                {
                    res+=dp[i][1];
                }
                if(i!=num.size()-1&&num[i+1]==4&&num[i]>9)
                {
                    res+=dp[i][0];
                }
                if(i!=num.size()-1&&num[i+1]==4&&num[i]==9)
                {
                    st=true;
                }
            }
        }
        cout<<res<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
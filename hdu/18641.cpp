////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 21:59:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:16124KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

double up,sum,num,suma[40];
int upint;
int n,m;
char op;
vector<int>w;
bool st,can;
int dp[3700004];
double res;

int main()
{
    int i,j;
    while(cin>>up>>n)
    {
        if(n==0)
            break;
//        cin>>m;
        w.clear();

        upint=int(up*100);
        for(i=1;i<=n;i++)
        {
            cin>>m;
            st=true;
            sum=0;
            suma[0]=suma[1]=suma[2]=0;
//            can=true;
            for(j=1;j<=m;j++)
            {
                getchar();
                op=getchar();
                getchar();
                cin>>num;
                if(!(op=='A'||op=='B'||op=='C'))
                {
                    st=false;
                }
                if(st)suma[op-'A']+=num;
                sum+=num;
            }
//            cout<<suma[0]<<endl;
//            cout<<suma[1]<<endl;
//            cout<<suma[2]<<endl;
            if(sum<=1000&&st&&suma[0]<=600&&suma[1]<=600&&suma[2]<=600)
            {
                w.push_back((int)(sum*100));
            }
        }
        res=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<w.size();i++)
        {
//            cout<<w[i]<<endl;
            for(j=upint;j>=w[i];j--)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
            }
        }
        double res=0;
        for(j=upint;j>0;j--)
        {
            res=max((double)dp[j]/100.0,res);
        }
        printf("%.2lf\n",res);
    }
//    cout << "Hello world!" << endl;
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 19:59:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:16140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <string.h>
#include <cmath>

using namespace std;

const int MAXN=37;
const int MAXM=100007;
const double EPS=1e-8;

int i,j,k,n,m,x,y;
int w[MAXN],dp[MAXM*MAXN];
double MAX_TOT_V=1000;
double MAX_TYPE_V=600;
double q,v,totv,typv[7],ans;
bool isOK;
bool f[MAXN];
string s;

bool cmp(const int &a, const int &b)
{
    return a>b;
}

int main()
{
    while (cin>>q>>n)
    {
        if (n==0)
        {
            break;
        }
        memset(w,0,sizeof(w));
        for (i=0;i<n;i++)
        {
            cin>>k;
            totv=0;
            typv[0]=0;
            typv[1]=0;
            typv[2]=0;
            isOK=true;
            for (j=0;j<k;j++)
            {
                cin>>s;
                if (s[0]>'C')
                {
                    isOK=false;
                }
                if (isOK)
                {
                    istringstream sin(s.substr(2));
                    sin>>v;
//                    if (ceil(v*100)-(v*100)>EPS)
//                    {
//                        while (1){;}
//                    }
                    totv+=v;
                    typv[s[0]-'A']+=v;
                    if (typv[s[0]-'A']>MAX_TYPE_V || totv>MAX_TOT_V)
                    {
                        isOK=false;
                    }
                }
            }
            if (isOK)
            {
                w[i]=totv*100;
            }
        }
        sort(w,w+n,cmp);
        for (i=0;i<n;i++)
        {
            if (w[i]==0)
            {
                n=i;
                break;
            }
        }
        /*
        for (i=0;i<n;i++)
        {
            cout<<i<<" "<<w[i]<<endl;
        }
        cout<<endl;
        //*/
        memset(dp,0,sizeof(dp));
        ans=0;
        m=q*100;
        for (i=0;i<n;i++)
        {
            for (j=m;j>=w[i];j--)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
            }
        }
        for (j=m;j>0;j--)
        {
            if (dp[j]>0)
            {
                ans=(double)dp[j]/100;
                break;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

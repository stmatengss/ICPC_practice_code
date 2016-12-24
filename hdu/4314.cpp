////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-26 11:13:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4314
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:17312KB
//////////////////System Comment End//////////////////
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct po{
    int a,b;
    po(){}
    po(int a,int b):a(a),b(b){}
    int operator< (const po & x)const
    {
        return (a+b)>(x.a+x.b);
    }
};

int dp[2004][2004];
int sum[2004];
int n,h;
po p[2004];
const int inf=0xfffffff;

int main(int argc, char** argv) {
    int i,j;
    while(cin>>n){
        for(i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b;
        }
        cin>>h;
        sort(p+1,p+n+1);
        sum[0]=0;
        for(i=1;i<=n;i++){
            sum[i]=sum[i-1]+p[i].a;
        }
        for(i=0;i<=n;i++){
            for(j=i+1;j<=n;j++){
                dp[i][j]=inf;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                dp[i][j]=min(dp[i-1][j]-p[i].a,max(dp[i-1][j-1],h-sum[i]-p[i].b));
            }
        }
        for(i=n;i>=0;i--){
            if(dp[n][i]<=0){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

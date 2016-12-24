////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 14:51:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3853
////Problem Title: 
////Run result: Accept
////Run time:2449MS
////Run memory:33328KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const double eps=1e-7;
int r,c;
double dp[1004][1004];
double p[1004][1004][3];

double dfs(int x,int y)
{
    if(x==r&&y==c)
        return 0;
    if(x>r||y>c)
        return 0;
    if(dp[x][y]==-1)return 0;
    if(dp[x][y]>0)return dp[x][y];
    if(1-p[x][y][0]<eps)
    {
        dp[x][y]=-1;
        return 0;
    }
    return dp[x][y]=(2+dfs(x+1,y)*p[x][y][2]+dfs(x,y+1)*p[x][y][1])/(1-p[x][y][0]);
}

int main()
{
//    cout << "Hello world!" << endl;
    int i,j;
    while(cin>>r>>c)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                  scanf("%lf%lf%lf",&p[i][j][0],&p[i][j][1],&p[i][j][2]);
//                cin>>p[i][j][0]>>p[i][j][1]>>p[i][j][2];
            }
        }
        printf("%.3lf\n",dfs(1,1));
    }
    return 0;
}
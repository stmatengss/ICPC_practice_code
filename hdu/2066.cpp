////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-09 23:17:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:4224KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 1010
#define MAX 9999999
using namespace std;
int g[N][N], n, flag1[N], flag2[N];
void init()
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(i == j)g[i][j] = 0;
            else g[i][j] = MAX;
        }
}
void getd(int t, int a, int b)
{
    int s, i, j, temp;
    while(t--)
    {
        scanf("%d %d %d", &i, &j, &temp);
        if(g[i][j] > temp)g[i][j] = g[j][i] = temp;
        if(i > n)n = i;
        if(j > n)n = j;
    }
    memset(flag1, 0, sizeof(flag1));
    memset(flag2, 0, sizeof(flag2));
    while(a--)
    {
        scanf("%d", &s);
        flag1[s] = 1;
    }
    while(b--)
    {
        scanf("%d", &s);
        flag2[s] = 1;
    }
}
void floyd()
{
    int i, j, k, temp = MAX;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            if(g[i][k] != MAX)
                for(j = 1; j <= n; j++)
                {
                    if(g[i][j] > g[i][k] + g[k][j])
                        g[i][j] = g[i][k] + g[k][j];
                    if(flag1[i] && flag2[j] && g[i][j] < temp)
                        temp = g[i][j];
                }
        }
    }
    printf("%d\n", temp);
}
int main()
{
    int t, a, b, s, i, j, temp;
    while(scanf("%d %d %d", &t, &a, &b) != EOF)
    {
        init();
        getd(t, a, b);
        floyd();
    }
    return 0;
}
/*
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
4 2 1
1 2 3
2 3 4
1 4 2
2 4 1
1 2
3
*/
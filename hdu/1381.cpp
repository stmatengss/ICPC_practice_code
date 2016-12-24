////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 21:23:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1381
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:16044KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000000];
int ascii[125];
bool hash[16000000];          //这里使用bool型定义，因为bool型数据在内存中占一个字节，而int型占两个
int main()
{
    int t, n, m, j;
    //freopen("data.in", "r", stdin);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", str);
        int len = strlen(str);
        int k = 0, num = 0, i = 0;
        memset(hash, 0, sizeof(hash));
        memset(ascii, 0, sizeof(ascii));
        while(k != m)
        {
            if(!ascii[str[i]-'A'])    ascii[str[i]-'A'] = k++;
            i++;
        }
        for(i = 0; i <= len-n; i++)
        {
            int sum = 0;
            for(j = 0; j < n; j++)
            {
                sum = sum*m + ascii[str[j+i]-'A'];
            }
            if(!hash[sum])
            {
                hash[sum] = true;    num++;  
            }
        }
        printf("%d\n", num);
        if(t)    printf("\n");
    }
    return 0;
}
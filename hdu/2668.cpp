////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-04 16:01:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2668
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:11340KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char a[10000004];
int used[300];

int main()
{
    int i,j,k;
    int begin,end;
    int res;
    char tmp;
    while(~scanf("%d",&n))
    {
        scanf("%s",a);
        j=0;
        res=0;
        memset(used,0,sizeof(used));
        for(i=0;i<n;i++)
        {
            if(used[a[i]]>0)
            {
                while(j<i)
                {
                    used[a[j]]--;
                    j++;
//                    cout<<a[j]<<" "<<j<<" "<<i<<endl;
                    if(a[j-1]==a[i])
                    {
                        break;
                    }
                }
            }
            used[a[i]]++;
            if(i-j+1>res)
            {
                res=i-j+1;
                begin=j;
                end=i;
            }
        }
        printf("%d %d %d\n",res,begin,end);
//        cout<<res<<" "<<begin<<" "<<end<<endl;
    }

//    cout << "Hello world!" << endl;
    return 0;
}

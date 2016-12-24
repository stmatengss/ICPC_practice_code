////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 14:50:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4336
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1636KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double p[22];
int n,counter;
double res,sum;

int main()
{
    int i,j;
    while(cin>>n)
    {
        res=0;
        for(i=0;i<n;i++)
            cin>>p[i];
        for(i=1;i<(1<<n);i++)
        {
            counter=0;
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sum+=p[j];
                    counter++;
                }
            }
//            cout<<sum<<endl;
            res+=((counter&1)?1:-1)*1.0/sum;
        }
        printf("%lf\n",res);
    }

//    cout << "Hello world!" << endl;
    return 0;
}
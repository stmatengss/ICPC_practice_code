////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 19:36:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:9424KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int a,b,c,d;
int zero=1000004;
int ha[2000008];
map<int,int>mp;
int counter;

int main()
{
    int i,j;
    while(cin>>a>>b>>c>>d)
    {
        if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0)
        {
            cout<<"0"<<endl;
            continue;
        }
        counter=0;
        memset(ha,0,sizeof(ha));
//        mp.clear();
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                ha[zero+a*i*i+b*j*j]++;
            }
        }
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                if(ha[zero-(c*i*i+d*j*j)])
                    counter+=ha[zero-(c*i*i+d*j*j)];
            }
        }
        cout<<16*counter<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

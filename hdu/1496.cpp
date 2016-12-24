////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 19:32:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:2676KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>

using namespace std;

int a,b,c,d;
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
        mp.clear();
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                mp[a*i*i+b*j*j]++;
            }
        }
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                if(mp[-(c*i*i+d*j*j)])
                    counter+=mp[-(c*i*i+d*j*j)];
            }
        }
        cout<<16*counter<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

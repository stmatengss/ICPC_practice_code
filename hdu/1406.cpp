////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 16:31:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1636KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int tab[10004];

int fatorsum(int num)
{
    int i;
    int res=1;
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            res+=i;
            if(i*i!=num)res+=num/i;
        }
    }
    if(res==num)return true;
    else return false;
}

void table()
{
    tab[0]=0;
    for(int i=1;i<=10000;i++)
    {
        if(fatorsum(i))tab[i]=tab[i-1]+1;
        else tab[i]=tab[i-1];
    }
}

int main()
{
    int x,y;
    int t;
    table();
    while(cin>>t)
    {
        while(t--)
        {
            cin>>x>>y;
            if(x>y)swap(x,y);
            cout<<(tab[y]-tab[x-1])<<endl;
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

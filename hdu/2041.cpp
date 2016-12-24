////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 15:10:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1788KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;
ll tab[45];

int main()
{
    int i;
    int t;
    int n;
    tab[0]=0;
    tab[1]=1;
    for(i=2;i<=40;i++)
    {
        tab[i]=tab[i-1]+tab[i-2];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<tab[n]<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

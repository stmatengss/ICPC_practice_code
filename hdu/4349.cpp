////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 16:42:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4349
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

//int c[104][104];
long long A001316(int n)
{
    if(n<=1)return (n+1);
    return A001316(n/2)<<(n%2);
}

int main()
{
    int i,j;
    int n;
    while(cin>>n)
    {
        cout<<A001316(n)<<endl;
    }
//    c[0][0]=1;
//    for(i=1;i<=30;i++)
//    {
//        int counter=1;
//        c[0][i]=1;
//        for(j=1;j<=i;j++)
//        {
//            c[j][i]=c[j-1][i-1]+c[j][i-1];
//            if(c[j][i]&1)counter++;
//        }
//        cout<<counter<<endl;
//    }
//    cout << "Hello world!" << endl;
    return 0;
}

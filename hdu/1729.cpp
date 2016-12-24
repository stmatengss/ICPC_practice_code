////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 19:55:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1729
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>

using namespace std;

int change(int s,int c)
{
    int tmp=sqrt(s);
    while(tmp*tmp+tmp>=s)tmp--;
//    int  tmp=(sqrt(1+4*s)-1)/2;
//    while(tmp*tmp+tmp<s)tmp++;
    if(c>tmp)return s-c;
    else return change(tmp,c);
}

int main()
{
    int i,j;
    int res;
    int n;
    int s,c;
    int tcase=0;
    while(cin>>n)
    {
    if(n==0)
        break;
        res=0;
        tcase++;
        for(i=1;i<=n;i++)
        {
            cin>>s>>c;
            res^=change(s,c);
        }
        cout<<"Case "<<tcase<<":"<<endl;
        if(res>0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

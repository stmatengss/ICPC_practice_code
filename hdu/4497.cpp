////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 12:37:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4497
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

//int pow_mod(int a,int i,int n)
//{
//    if(i==0)return 1%n;
//    int temp=pow_mod(a,i>>1,n);
//        temp=temp*temp%n;
//    if(i&1)temp=(ll)temp*a%n;
//    return temp;
//}
//
//bool test(int n,int a,int d)
//{
//    if(n==2)return true;
//    if(n==a)return true;
//    if((n&1)==0)return false;
//    while(!(d&1))d=d>>1;
//    int t=pow_mod(a,d,n);
//    while((d!=n-1)&&(t!=1)&&(t!=n-1))
//    {
//        t=(ll)t*t*n;
//        d=d<<1;
//    }
//    return (t==n-1||(d&1)==1);
//}
//
//bool isprime(int n)
//{
//    if(n<2)return false;
//    int a[]={2,3,61};
//    for(int i=0;i<=2;i++)
//        if(!test(n,a[i],n-1))return false;
//    return true;
//}


int isprime(int x)  //ÅÐ¶¨ÊÇËØÊý
{
    if(x==1)return 0;
    int flag=1,i;
    for(i=2;i<=sqrt(x+0.5);i++)
        if(x%i==0)
        {
            flag=0;
            break;
        }
    return flag;
}


ll g,l;
ll n;
ll res,counter;

int main()
{
    int i;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>g>>l;
        if(l%g!=0)cout<<"0"<<endl;
        else
        {
            n=l/g;
            res=1;
            if(isprime(n))
            {
                cout<<"6"<<endl;
            }
            else
            {
                for(i=2;i<=sqrt(l/g+0.5);i++)
                {
                    if(n%i==0&&isprime(i))
                    {
                        counter=0;
                        while(n%i==0)
                        {
                            n=n/i;
                            counter++;
                        }
                        res=counter*6*res;
                    }
                }
                if(n>1)res*=6;
                cout<<res<<endl;
            }
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

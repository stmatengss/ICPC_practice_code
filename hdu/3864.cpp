////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 19:50:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3864
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1804KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
//****************************************************************
// Miller_Rabin 算法进行素数测试
//速度快，而且可以判断 <2^63的数
//****************************************************************
const int S=20;//随机算法判定次数，S越大，判错概率越小


//计算 (a*b)%c.   a,b都是ll的数，直接相乘可能溢出的
//  a,b,c <2^63
ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//计算  x^n %c
ll pow_mod(ll x,ll n,ll mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}





//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;

bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}


//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
ll factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

ll gcd(ll a,ll b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll Pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(ll n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

int main()
{
    //srand(time(NULL));//需要time.h头文件//POJ上G++不能加这句话
    ll n;
    while(cin>>n)
    {
        if(n==1)
        {
            cout<<"is not a D_num"<<endl;continue;
        }
        tol=0;
        findfac(n);
        if(tol!=3&&tol!=2){cout<<"is not a D_num"<<endl;continue;}
        sort(factor,factor+tol);
//        factor[tol++]=n;
        if(tol==2)
        {
            if(factor[0]!=factor[1])
                cout<<factor[0]<<" "<<factor[1]<<" "<<n<<endl;
            else
                cout<<"is not a D_num"<<endl;
        }
        else
        {
            if(factor[0]==factor[1]&&factor[1]==factor[2])
                cout<<factor[0]<<" "<<factor[0]*factor[0]<<" "<<factor[0]*factor[0]*factor[0]<<endl;
            else
                cout<<"is not a D_num"<<endl;
        }
//        if(factor[0]!=factor[1]&&factor[1]!=factor[2]&&tol==3||factor[0]!=factor[1]&&tol==2)
//            for(int i=0;i<tol;i++)
//                cout<<factor[i]<<(i==tol-1?"\n":" ");
//        else
//            cout<<"is not a D_num"<<endl;
//        for(int i=0;i<tol;i++)printf("%I64d ",factor[i]);
//        printf("\n");
//        if(Miller_Rabin(n))printf("Yes\n");
//        else printf("No\n");
    }
    return 0;
}

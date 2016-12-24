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
// Miller_Rabin �㷨������������
//�ٶȿ죬���ҿ����ж� <2^63����
//****************************************************************
const int S=20;//����㷨�ж�������SԽ���д����ԽС


//���� (a*b)%c.   a,b����ll������ֱ����˿��������
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



//����  x^n %c
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





//��aΪ��,n-1=x*2^t      a^(n-1)=1(mod n)  ��֤n�ǲ��Ǻ���
//һ���Ǻ�������true,��һ������false
bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//����
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()�㷨�����ж�
//����������true.(������α�����������ʼ�С)
//��������false;

bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//ż��
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;//rand()��Ҫstdlib.hͷ�ļ�
        if(check(a,n,x,t))
            return false;//����
    }
    return true;
}


//************************************************
//pollard_rho �㷨�����������ֽ�
//************************************************
ll factor[100];//�������ֽ������շ���ʱ������ģ�
int tol;//�������ĸ���������С���0��ʼ

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
//��n���������ӷֽ�
void findfac(ll n)
{
    if(Miller_Rabin(n))//����
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
    //srand(time(NULL));//��Ҫtime.hͷ�ļ�//POJ��G++���ܼ���仰
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

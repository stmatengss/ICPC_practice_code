////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-05 16:55:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4549
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1796KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;
const ll mod1=1000000007;
const ll mod2=1000000006;
ll a,b,n;

struct mat{
    ll s[3][3];
    //int operator[][](const int &a,const int &b){return s[a][b];}
    mat operator *(const mat &b)const{
        int i,j,k;
        ll tmp;
        mat ret;
        for(i=1;i<=2;++i){
            for(j=1;j<=2;++j){
                tmp=0;
                for(k=1;k<=2;++k){
                    tmp=(tmp+(s[i][k]*b.s[k][j])%mod2)%mod2;
                }
                //printf("             %d %d\n",tmp,m);
                ret.s[i][j]=tmp;
            }
        }
        return ret;
    }
    mat operator +(const mat &b)const{
        int i,j;
        mat ret;
        for(i=1;i<=2;++i){
            for(j=1;j<=2;++j){
                ret.s[i][j]=(s[i][j]+b.s[i][j])%mod2;
            }
        }
        return ret;
    }
    void inite(){
        int i,j;
        for(i=1;i<=2;++i)
            for(j=1;j<=2;++j){
                if (i==j) s[i][j]=1;else s[i][j]=0;
            }
    }
//    void print(){
//        int i,j;
//        for(i=1;i<=2;++i){
//            for(j=1;j<=2;++j){
//                printf("%d",s[i][j]);
//                if (j!=n) printf(" ");
//            }
//            printf("\n");
//        }
//    }

}ans;

mat quickpow(mat b,ll t){
    mat ret;
    ret.inite();
    while(t){
        if (t&1){
            ret=ret*b;
        }
        b=b*b;
        t>>=1;
    }
    return ret;
}

ll quickpow(ll b,ll t)
{
    ll ret=1;
    while(t){
        if(t&1)ret=ret*b%mod1;
        b=b*b%mod1;
        t>>=1;
    }
    return ret;
}

int main()
{
    while(cin>>a>>b>>n)
    {
        ans.s[1][1]=1,ans.s[1][2]=1;
        ans.s[2][1]=1,ans.s[2][2]=0;
        if(n==0)cout<<a<<endl;
        else ans=quickpow(ans,n-1),cout<<(quickpow(a,ans.s[1][2])*quickpow(b,ans.s[1][1])%mod1)<<endl;
    }
    return 0;
}

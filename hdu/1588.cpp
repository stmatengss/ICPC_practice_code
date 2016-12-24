////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 10:54:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1588
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Max_n=3;
typedef long long ll;
const int n=2;
ll K,B,N,m;

struct mat{
    ll s[Max_n][Max_n];
    //int operator[][](const int &a,const int &b){return s[a][b];}
    mat operator *(const mat &b)const{
        int i,j,k;
        ll tmp;
        mat ret;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                tmp=0;
                for(k=1;k<=n;++k){
                    tmp=(tmp+(s[i][k]*b.s[k][j])%m)%m;
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
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                ret.s[i][j]=(s[i][j]+b.s[i][j])%m;
            }
        }
        return ret;
    }
    void inite(){
        int i,j;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j){
                if (i==j) s[i][j]=1;else s[i][j]=0;
            }
    }
    void print(){
        int i,j;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                printf("%d",s[i][j]);
                if (j!=n) printf(" ");
            }
            printf("\n");
        }
    }

}a,ans,E;

mat smul(mat b,ll t){
    mat ret;
    ret.inite();
    while(t){
        if (t&1){
            ret=ret*b;
            t=t^1;
        }
        else {
            b=b*b;
            t>>=1;
        }
    }
    return ret;
}

mat cal(mat b,ll t)
{
    if(t==0)return E;
    if(t==1)return b;
    if(t&1)
        return cal(b,t-1)+smul(b,t);
    else
        return cal(b,t/2)*(smul(b,t/2)+E);
}

int main()
{
    E.inite();
    while(cin>>K>>B>>N>>m)
    {
        a.s[1][1]=1,a.s[1][2]=1;
        a.s[2][1]=1,a.s[2][2]=0;
        ans=(cal(smul(a,K),N-1)+E)*smul(a,B);
        cout<<ans.s[1][2]<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

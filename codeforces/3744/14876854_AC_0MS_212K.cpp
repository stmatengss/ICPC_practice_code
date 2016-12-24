#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
double p;
int pos[14],pro;

struct mat{
    double s[3][3];
    //int operator[][](const int &a,const int &b){return s[a][b];}
    mat operator *(const mat &b)const{
        int i,j,k;
        double tmp;
        mat ret;
        for(i=1;i<=2;++i){
            for(j=1;j<=2;++j){
                tmp=0;
                for(k=1;k<=2;++k){
                    tmp=(tmp+s[i][k]*b.s[k][j]);
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
                ret.s[i][j]=(s[i][j]+b.s[i][j]);
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
//        for(i=1;i<=n;++i){
//            for(j=1;j<=n;++j){
//                printf("%d",s[i][j]);
//                if (j!=n) printf(" ");
//            }
//            printf("\n");
//        }
//    }

}a,ans,E;

mat smul(mat b,ll t){
    mat ret;
    ret.inite();
    while(t){
        if (t&1){
            ret=ret*b;
        }
        b=b*b;
        t=t>>1;
    }
    return ret;
}

double cal(int n)
{
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n==3)return p;
    ans=smul(a,n-3);
    return ans.s[1][1]*p+ans.s[1][2];
}

int main()
{
    double res;
    int n;
    int i,j,k;
    E.inite();
    while(cin>>n>>p)
    {
        a.s[1][1]=p,a.s[1][2]=1-p;
        a.s[2][1]=1,a.s[2][2]=0;
        res=1.0;
        pro=0;
        for(i=1;i<=n;i++)
            cin>>pos[i];
        sort(pos,pos+n+1);
        for(i=1;i<=n;i++)
        {
            res*=(cal(pos[i]-pos[i-1]));
            res*=(1-p);
        }
        printf("%.7f\n",res);
    }
//    cout << "Hello world!" << endl;
    return 0;
}

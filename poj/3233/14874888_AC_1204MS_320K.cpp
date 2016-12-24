#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
mat E(34,vec(34));

int mod;

mat mul(mat A,mat B)
{
    mat C(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            for(int k=0;k<A.size();k++)
            {
                C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    return C;
}

mat add(mat A,mat B)
{
    mat C(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            C[i][j]=(A[i][j]+B[i][j])%mod;
        }
    }
    return C;
}

mat pow(mat &A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        B[i][i]=1;
    }
    while(n)
    {
        if(n&1)B=mul(B,A);
        A=mul(A,A);
        n=n>>1;
    }
    return B;
}

mat cal(mat &a,ll n)
{
    if(n==0)return E;
    if(n==1)return a;
    if(n&1)
        return add(cal(a,n-1),pow(a,n));
    else
        return mul(cal(a,n/2),add(pow(a,n/2),E));
}

void solve(mat A,int n,int k){
    mat B(n*2,vec(n*2));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            B[i][j]=A[i][j];
        }
        B[n+i][i]=B[n+i][n+i]=1;
    }
    B=pow(B,k+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a=B[n+i][j]%mod;
            if(i==j)a=(a+mod-1)%mod;
            cout<<a<<(j==(n-1)?"\n":" ");
        }
    }
}

int main()
{
    int i,j;
    int n,m;
    ll k;
    int tmp;
    for(i=0;i<34;i++)
    {
        for(j=0;j<34;j++)
        {
            if(i==j)E[i][j]=1;
            else E[i][j]=0;
        }
    }
    while(cin>>n>>k>>mod)
    {
        mat res(n,vec(n));
        mat A(n,vec(n));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>tmp;
                A[i][j]=tmp%mod;
            }
        }
        solve(A,n,k);
//        res=cal(A,k);
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<n;j++)
//            {
//                cout<<res[i][j]<<(j==(n-1)?"\n":" ");
//            }
//        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}
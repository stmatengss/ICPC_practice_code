#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int sg[10007];
bool hash[10007];
int s[104];
void sg_solve(int t)   //N求解范围 S[]数组是可以每次取的值，t是s的长度。
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=10004;i++)
    {
        memset(hash,0,sizeof(hash));
        for(j=0;j<t;j++)
            if(i - s[j] >= 0)
                hash[sg[i-s[j]]] = 1;
        for(j=0;j<=10004;j++)
            if(!hash[j])
                break;
        sg[i] = j;
    }
}

int main()
{
    int i,j,tmp;
    int n,m,t;
    int res;
    string out;
    while(cin>>n,n)
    {
        for(i=0;i<n;i++)scanf("%d",&s[i]);
        sg_solve(n);
        out="";
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
            res=0;
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&tmp);
                res^=sg[tmp];
            }
            out+=res?'W':'L';
        }
        cout<<out<<endl;
    }
    return 0;
}

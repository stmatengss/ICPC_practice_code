#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include<string>

using namespace std;

const int CHARSET=52,MAX_NODE=100004;
map<string,int>mp;
string suit[4]={"C","D","H","S"};
string val[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

struct Trie
{
    int tot,root;
    int child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    void init()
    {
        memset(child[1],0,sizeof(child[1]));
//        memset(flag,false,sizeof(flag));
        flag[1]=false;
        root=tot=1;
    }
    void insert(const int *str,int n)
    {
        int i,j;
        int *cur=&root;
        for(i=0;i<n;i++)
        {
            cur=&child[*cur][str[i]];
            if(*cur==0)
            {
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=false;
            }
        }
        flag[*cur]=true;
    }
    bool query(const char *str,int n)
    {
        int i;
        int *cur=&root;
        for(i=0;i<n;i++)
            cur=&child[*cur][str[i]];
        return (*cur&&flag[*cur]);
    }
    void debug()
    {
        int i,j;
        for(i=0;i<tot;i++)
        {
//            printf("id=%3d,fail")`
        }
    }
};

Trie tr;
int tmp[3000];
char in[4];
string s;

void tab()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<13;j++)
            mp[val[j]+suit[i]]=13*i+j;
    }
}

int main()
{
    int t,n;
    int i;
    tab();
    while(cin>>t,t)
    {
        tr.init();
        while(t--)
        {
            cin>>n;
            for(i=0;i<n;i++)
            {
               scanf("%s",in);
               s=in;
               tmp[n-1-i]=mp[s]; //cout<<"out:"<<s<<":"<<mp[s]<<endl;
            }
            tr.insert(tmp,n);
        }
        cout<<(tr.tot-1)<<endl;
    }
    return 0;
}

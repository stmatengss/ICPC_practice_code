////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-20 14:54:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1495
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:6000KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int a[3];
int b[3];
int c[3],ran;
int st[104][104][104];
struct node{
    int a[3];
    int ran;
    node(){}
    node(int b[3],int ran):ran(ran){
    a[0]=b[0],a[1]=b[1],a[2]=b[2];
    }
    bool operator ==(const node& b)const
    {
        if(a[0]==b.a[0]&&a[1]==b.a[1]&&a[2]==b.a[2])return true;
        return false;
    }
};
node init;

void bfs()
{
    int i,j;
    b[0]=a[0],b[1]=0,b[2]=0;
    init=node(b,0);
    queue<node>q;
    q.push(init);
    while(!q.empty())
    {
        init=q.front();
        q.pop();
        copy(init.a,init.a+3,b);
        ran=init.ran;
        if(init.a[0]==a[0]/2&&init.a[1]==a[0]/2)
        {
            cout<<init.ran<<endl;
            return;
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i!=j&&b[i]!=0&&b[j]!=a[j])
                {
                      copy(b,b+3,c);
                      if(b[i]>a[j]-b[j])
                      {
                           c[i]=b[i]-(a[j]-b[j]);
                           c[j]=a[j];
                      }
                      else
                      {
                           c[i]=0;
                           c[j]=b[j]+b[i];
                      }
                      if(st[c[0]][c[1]][c[2]]==0)
                      {
                           st[c[0]][c[1]][c[2]]=1;
                           q.push(node(c,ran+1));
                      }

                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    while(cin>>a[0]>>a[1]>>a[2]&&a[0]!=0)
    {
        if(a[2]>a[1])swap(a[1],a[2]);
        if(a[0]%2)
            cout<<"NO"<<endl;
        else
        {
            memset(st,0,sizeof(st));
            bfs();
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-22 20:48:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1240
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct po{
    int x,y,z,rk;
    po(){}
    po(int x,int y,int z,int rk):x(x),y(y),z(z),rk(rk){}
};
char mp[14][14][14];
po bone,eone;
string tmp;
int n;
int dx[7]={ 1,-1, 0, 0, 0, 0};
int dy[7]={ 0, 0, 1,-1, 0, 0};
int dz[7]={ 0, 0, 0, 0, 1,-1};

bool illegal(int x,int y,int z)
{
    if(x<=n&&x>=1&&y<=n&&y>=1&&z<=n&&z>=1&&mp[x][y][z]=='O')return true;
    return false;
}

void bfs()
{
    bone.rk=0;
    int i,x,y,z,xx,yy,zz,rk;
    queue<po>q;
    q.push(bone);
    mp[bone.x][bone.y][bone.z]='X';
    while(!q.empty())
    {
        x=q.front().x,y=q.front().y,z=q.front().z,rk=q.front().rk;
        q.pop();
        if(x==eone.x&&y==eone.y&&z==eone.z)
        {
            cout<<n<<" "<<rk<<endl;
            return;
        }
        for(i=0;i<=5;i++)
        {
            xx=x+dx[i],yy=y+dy[i],zz=z+dz[i];
            if(illegal(xx,yy,zz))
            {
                mp[xx][yy][zz]='X';
                q.push(po(xx,yy,zz,rk+1));
            }
        }
    }
    cout<<"NO ROUTE"<<endl;
}

int main()
{
    int i,j,k;
    while(cin>>tmp>>n)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    cin>>mp[j][k][i];
        scanf("%d%d%d%d%d%d",&bone.x,&bone.y,&bone.z,&eone.x,&eone.y,&eone.z);
        bone.x++,bone.y++,bone.z++,eone.x++,eone.y++,eone.z++;
        cin>>tmp;
        bfs();
    }
//    cout << "Hello world!" << endl;
    return 0;
}

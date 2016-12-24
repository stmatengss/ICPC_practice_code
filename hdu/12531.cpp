////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 15:03:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:1497MS
////Run memory:2796KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct state{
    int t;
    int x,y,z;
    state(int x,int y,int z,int t):x(x),y(y),z(z),t(t){}
    state(){}
};
int dx[7]={ 1, 0, 0,-1, 0, 0};
int dy[7]={ 0, 1, 0, 0,-1, 0};
int dz[7]={ 0, 0, 1, 0, 0,-1};
int mp[104][104][104];
int xlen,ylen,zlen,res;

bool islegal(int x,int y,int z)
{
    if(x<=xlen&&x>=1&&y<=ylen&&y>=1&&z<=zlen&&z>=1&&mp[x][y][z]==0)
        return true;
    return false;
}

int main()
{
    int i,j,k;
    int tcase;
    int x,y,z,xx,yy,zz,t;
    state tmp;
    int time;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d%d%d",&xlen,&ylen,&zlen,&time);
        for(i=1;i<=xlen;i++)
        {
            for(j=1;j<=ylen;j++)
            {
                for(k=1;k<=zlen;k++)
                {
                    scanf("%d",&mp[i][j][k]);
                }
            }
        }
        queue<state>q;
        q.push(state(1,1,1,0));
        mp[1][1][1]=1;
        res=-1;
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            x=tmp.x;
            y=tmp.y;
            z=tmp.z;
            t=tmp.t;
            if(t>time)
            {
                res=-1;
                break;
            }
            if(x==xlen&&y==ylen&&z==zlen)
            {
                res=t;
                break;
            }
            for(i=0;i<6;i++)
            {
                xx=x+dx[i],yy=y+dy[i],zz=z+dz[i];

                if(islegal(xx,yy,zz))
                {
                    if(xlen-xx+ylen-yy+zlen-zz+t+1>time)
                        continue;
                    q.push(state(xx,yy,zz,t+1));
                    mp[xx][yy][zz]=1;
                }
            }
        }
        cout<<res<<endl;
    }

//    cout << "Hello world!" << endl;
    return 0;
}

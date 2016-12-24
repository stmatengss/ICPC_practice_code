#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct squence{
	int x;
	int y;
	int num;
	int tank;
	squence(int c,int d,int a,int b):x(c),y(d),num(a),tank(b){
	}
	squence(){
	}
};
int hash[1000000]={0};
int map[5][5];
queue<squence>q;
int x,y,num,tank;
int sum=0;
int power[7]={1,10,100,1000,10000,100000,1000000};
squence temp;//=squence(0,0,0,0);

void bfs(int x,int y)
{
	while(!q.empty())
	{
	temp=q.front();
	x=temp.x;
	y=temp.y;
	tank=temp.tank;
	num=temp.num;
	q.pop();
	if(tank==6)
	{
		hash[num]=1;
	}
	else
	{
	if(x>0)q.push(squence(x-1,y,num+map[x-1][y]*power[5-(tank+1)],tank+1));
	if(y>0)q.push(squence(x,y-1,num+map[x][y-1]*power[5-(tank+1)],tank+1));
	if(x<4)q.push(squence(x+1,y,num+map[x+1][y]*power[5-(tank+1)],tank+1));
	if(y<4)q.push(squence(x,y+1,num+map[x][y+1]*power[5-(tank+1)],tank+1));
	}
	
	}

}

void cal()
{
	int i;
	for(i=0;i<=999999;i++)if(hash[i])sum++;
}

int main()
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		cin>>map[i][j];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			while(!q.empty())q.pop();
			q.push(squence(i,j,map[i][j]*power[5],0));
			bfs(i,j);
		}
	cal();
	cout<<sum<<endl;
	return 0;
}
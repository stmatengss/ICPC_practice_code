#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 104;
int m,n;
char map[N][N];

void bfs(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='W')
	{
		map[x][y]='.';		
	bfs(x-1,y-1); bfs(x,y-1); bfs(x+1,y-1);
	bfs(x-1,y);				  bfs(x+1,y);
	bfs(x-1,y+1); bfs(x,y+1); bfs(x+1,y+1);
	}
}

int main()
{
	int i,j;
	int count=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
		gets(map[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(map[i][j]=='W')
			{
				bfs(i,j);
				count++;
			}
		}
	cout<<count<<endl;
	return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 104;
char map[N][N];
int n,m;
int sum;

void dfs(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='.'||map[x][y]=='@')
	{
		sum++;
		map[x][y]='#';		
                  dfs(x,y-1); 
	dfs(x-1,y);				  dfs(x+1,y);
				  dfs(x,y+1); 
	}
}
/*
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
int main()
{
	int i,j;
	while(1)
	{
		cin>>m>>n;
			if(n==0)break;
		sum=0;
		memset(map,'\0',sizeof(map));
		for(i=0;i<n;i++)cin>>map[i];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(map[i][j]=='@')
				{
					dfs(i,j);
					break;
				}
			}
		cout<<sum<<endl;
	}
	
	return 0;
}
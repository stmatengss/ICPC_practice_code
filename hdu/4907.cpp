////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:06:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4907
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:5300KB
//////////////////System Comment End//////////////////
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 300007;

int free_after[MAXN];
int t[MAXN];

int schedule(int loc)
{
	int new_loc;
	if (t[loc])
	{
		new_loc = schedule(loc + 1);
		free_after[loc] = new_loc;
		return new_loc;
	}
	free_after[loc] = loc;
	return loc;
}
int main(int argc, char **argv)
{
	int n_case;
	cin >> n_case;
	int n_scheduled, n_target;
	int tmp;
	for (int i = 0; i < n_case; i++)
	{
		cin >> n_scheduled >> n_target;
		memset(t, 0, sizeof(t));
		memset(free_after, -1, sizeof(free_after));
		int max_time = 0;
		for (int i = 0; i < n_scheduled; i++)
		{
			scanf("%d", &tmp);
			t[tmp] = 1;
			max_time = max(max_time, tmp);
		}
		for (int i = 0; i < max_time + 1; i++)
		{
			i = schedule(i);
		}
		for (int i = 0; i < n_target; i++)
		{
			scanf("%d", &tmp);
			if(free_after[tmp]!=-1)
			{
				printf("%d\n", free_after[tmp]);
			}
			else
			{
				printf("%d\n", tmp);
			}
		}
	}
}
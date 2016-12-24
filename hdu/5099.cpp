////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:12:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1728KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<vector>
#include <string>
#define RELEASE
using namespace std;




int cmp_version(string & a, string& b)
{
	if (a[0] < b[0])
	{
		return 1;

	}
	if (a[0] > b[0])
	{
		return -1;
	}

	return 0;
}
int cmp_date(string & a, string& b)
{
	if (a[2] < b[2])
	{
		return 1;

	}
	if (a[2] > b[2])
	{
		return -1;
	}
	if (a[3] < b[3])
	{
		return 1;
	}
	if (a[3] > b[3])
	{
		return -1;
	}
	if (a[4] < b[4])
	{
		return 1;
	}
	if (a[4] > b[4])
	{
		return -1;
	}
	if (a[1] == b[1])
	{
		if (a[5] < b[5])
		{
			return 1;
		}
		if (a[5] > b[5])
		{
			return -1;
		}
	}
	return 0;
}
int main()
{
	int n_case;
	scanf("%d", &n_case);
	char buff[1000];
	string a, b;
	for (int i = 0; i < n_case; i++)
	{
		printf("Case %d: ",i+1);

		scanf("%s", buff);
		a = buff;
		scanf("%s", buff);
		b = buff;
		int res;
		res = cmp_version(a, b);
		if (res == 1)
		{
			printf("< ");
		}
		if (res == 0)
		{
			printf("= ");
		}
		if (res == -1)
		{
			printf("> ");
		}
		res = cmp_date(a, b);
		if (res == 1)
		{
			printf("<\n");
		}
		if (res == 0)
		{
			printf("=\n");
		}
		if (res == -1)
		{
			printf(">\n");
		}
	}
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:13:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3711
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1724KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int get_distance(int a, int b)
{
	int c = a ^ b;
	int sum = 0;
	for (int i = 1; i <= c; i <<= 1)
	{
		if (c & i)
		{
			sum++;
		}
	}
	return sum;
}

int set_a[106];
int set_b[106];
const int INF=1<<29;

int main()
{
	int n_case;
	int n_in_set_a;
	int n_in_set_b;
	int min=INF;
	int current;
	int min_num;
	scanf("%d", &n_case);
	for (int i = 0; i < n_case; i++)
	{
		scanf("%d%d", &n_in_set_a, &n_in_set_b);
		for (int i = 0; i < n_in_set_a; i++)
		{
			scanf("%d", set_a + i);
		}
		for (int i = 0; i < n_in_set_b; i++)
		{
			scanf("%d", set_b + i);
		}
		sort(set_a,set_a+n_in_set_a);

		for(int i=0;i<n_in_set_b;i++)
		{
			min=INF;
			for(int j=0;j<n_in_set_a;j++)
			{
				current=get_distance(set_a[j],set_b[i]);
				if(min>current)
				{
					min=current;
					min_num=set_a[j];
				}
			}
			printf("%d\n",min_num);
		}

	}
}
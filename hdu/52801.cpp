////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:05:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5280
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:15676KB
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

long long sum[1008][1008];
long long delta[1008][1008];
long long array[1008];
int main()
{
	long long n_case;
	cin >> n_case;
	for (long long i = 0; i < n_case; i++)
	{
		long long array_len, target;
		cin >> array_len >> target;
		for (long long i = 0; i < array_len; i++)
		{
			scanf("%I64d", array + i);
		}
		for (long long i = 0; i < array_len; i++)
		{
			sum[i][i] = array[i];
			delta[i][i] = array[i];
			for (long long j = i + 1; j < array_len; j++)
			{
				sum[i][j] = sum[i][j - 1] + array[j];
				delta[i][j] = min(delta[i][j - 1], array[j]);
			}
		}
		for (long long i = 0; i < array_len; i++)
		{
			for (long long j = i; j < array_len; j++)
			{
				delta[i][j] -= target;
			}
		}
		long long bar=1LL<<50;
		bar=-bar;
		for (long long i = 0; i < array_len; i++)
		{
			for (long long j = i; j < array_len; j++)
			{
				if(bar<sum[i][j]-delta[i][j])
					bar=sum[i][j]-delta[i][j];
			}
		}
		for (long long i = 0; i < array_len; i++)
		{
			for (long long j = i; j < array_len; j++)
			{
				if(i==0&&j==array_len-1)
				{
					continue;
				}
				if(bar<sum[i][j])
					bar=sum[i][j];
			}
		}
		cout<<bar<<endl;

	}
}
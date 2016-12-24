#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long sum[40005]; //sum是到i的数的总位数

int judge(int x) //判断数的位数
{
	int count = 1;
	while(x / 10)
	{
		count++;
		x /= 10;
	}
	return count;
}

int fun(int x) //10的x幂
{
	int sum = 1;
	for(int i = 1; i <= x; ++i)
		sum *= 10;
	return sum;
}

void solve() //打表
{
	int sumn = 0;
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i < 40005; ++i)
	{
		sumn += judge(i);
		sum[i] = sum[i - 1] + sumn;
	}
}

void answer(int x)
{
	int ans, i, j, summ;
	i = 1;
	while(sum[i] < x) //询问的位数在sum[i]中的位置
		i++;
	ans = x - sum[i - 1];
	summ = 0;
	for(j = 1; j <= i; ++j) //询问位数在1到j的哪个具体的数字中
	{
		summ += judge(j);
		if(summ >= ans)
			break;
	}
	if(summ == ans) //相等，输入j对10取余，即最后一位
		printf("%d\n", j % 10);
	if(summ > ans) //不相等，则输出结果需要的位数
		printf("%d\n", (j / fun(summ - ans)) % 10);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	solve();
	while(ncase--)
	{
		int pos;
		scanf("%d", &pos);
		answer(pos);
	}
	return 0;
}

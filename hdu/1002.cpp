////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-15 21:22:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:416KB
//////////////////System Comment End//////////////////
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<math.h>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
using namespace std;

const int numberLength = 200;
const int N = 9;
const int MOD = 1000000000;

struct bigNumber
{
	string s;
	long long num[numberLength];
};

void input(bigNumber &a)
{
	int len, l;
	long long x;
	memset(a.num, 0, sizeof(a.num));
	len = a.s.length();
	x = 0;
	l = 0;
	int t = 1;
	for (int i = 1; i <= len; i++)
	{
		x += (a.s[len - i] - '0') * t;
		t *= 10;
		if (i % N == 0)
		{
			l++;
			a.num[l] = x;
			x = 0;
			t = 1;
		}
	}
	if (x != 0)
	{
		l++;
		a.num[l] = x;
	}
	if (l == 0)
	{
		l = 1;
	}
	a.num[0] = l;
	a.s = "";
}

void output(bigNumber &a)
{
	string temps;
	int len;
	ostringstream oss;
	len = a.num[0];
	if (len == 0)
	{
		return;
	}
	oss << a.num[len];
	len--;
	temps = oss.str();
	a.s += temps;
	oss.clear();
	oss.str("");
	while (len > 0)
	{
		oss << a.num[len];
		len--;
		temps = oss.str();
		while (temps.length() < N)
		{
			temps = "0" + temps;
		}
		a.s += temps;
		oss.clear();
		oss.str("");
	}
}

void bigAdd(bigNumber a, bigNumber b, bigNumber &c)
{
	int len;
	long long tempx;
	len = 0;
	if (a.s.length() > 0)
	{
		input(a);
	}
	if (b.s.length() > 0)
	{
		input(b);
	}
	c.s = "";
	memset(c.num, 0, sizeof(c.num));
	if (a.num[0] > b.num[0])
	{
		len = a.num[0];
	}
	else
	{
		len = b.num[0];
	}
	tempx = 0;
	for (int i = 1; i < len + 1; i++)
	{
		c.num[i] = a.num[i] + b.num[i] + tempx;
		tempx = c.num[i] / MOD;
		c.num[i] %= MOD;
	}
	if (tempx > 0)
	{
		len++;
		c.num[len] = tempx;
	}
	while (c.num[len] == 0 && len > 1)
	{
		len--;
	}
	c.num[0] = len;
}

bigNumber a,b,c;

int main()
{
	//freopen("src/s.in", "r", stdin);
	//freopen("src/s.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i < t + 1; i++)
	{
		if (i > 1)
		{
			cout << endl;
		}
		cout << "Case " << i << ":" << endl;
		c.s = "";
		cin >> a.s >> b.s;
		bigAdd(a,b,c);
		
		cout << a.s << " + " << b.s << " = ";
		//bigDivB(a, b, c, d);
		output(c);
		cout << c.s << endl;
		//output(d);
		//cout << d.s << endl;
	}
	return 0;
}

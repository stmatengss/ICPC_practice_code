////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5095
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>

using namespace std;

string tab[11] =
{ "p", "q", "r", "u", "v", "w", "x", "y", "z", "", };
int num;
int st;

int main()
{
	int t, i, j;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		st = 1;
		for (j = 0; j < 10; j++)
		{

			cin >> num;
			if (num != 0 && st == 1)
			{
				if (j==9)
				{
						cout<<num;
				}
				else
				{
					if (num == 1)
						cout << tab[j];
					else if (num == -1)
						cout << "-" << tab[j];
					else
						cout << num << tab[j];

				}
				st = 0;
			}
			else if (num != 0 && st == 0)
			{
				if (j == 9)
				{
					if (num > 0)
						cout << "+" << num;
					else
						cout << num;
				}
				else
				{
					if (num > 0)
					{
						if (num == 1)
						{
							cout << "+" << tab[j];
						}
						else
							cout << "+" << num << tab[j];
					}
					else
					{
						if (num == -1)
						{
							cout << "-" << tab[j];
						}
						else
						{
							cout << num << tab[j];
						}
					}
				}

			}
		}
		if (st == 1)
		{
			cout << "0" << endl;
		}
		else
			cout << endl;
	}
	return 0;
}
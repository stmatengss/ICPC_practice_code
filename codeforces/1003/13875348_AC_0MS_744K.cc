#include<iostream>
#include<cstdio>
using namespace std;

bool st[521];
double sum;
double num;
int n;

int main()
{
	while(cin>>num)
	{
		if(num==0.00)break;
		sum=0;
		n=1;
		while(num>=sum)
		{
			n++;
			sum+=1.0/n;
		}
		cout<<(n-1)<<" card(s)"<<endl;
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include <iomanip> 
using namespace std;

int main()
{
	double sum=0;
	double num;
	int counter=0;
	while(cin>>num)
	{
		sum+=num;
		counter++;
	}
	cout<<setiosflags(ios::fixed);
	cout<<"$"<<setprecision(2)<<(sum/counter)<<endl;
	return 0;
}
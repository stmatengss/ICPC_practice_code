#include<iostream>
#include<cmath>

using namespace std;

double pi;
double x,y,now;

int main()
{
	int t;
	int tcase=0;
	cin>>t;
	pi=acos(-1.0);
	while(t--)
	{
		tcase++;
		cin>>x>>y;
		cout<<"Property : This property will begin eroding in year "<<tcase<<""<<(int((x*x+y*y)*pi/2.0/50.0)+1)<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
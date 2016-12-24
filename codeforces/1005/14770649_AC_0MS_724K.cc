#include<iostream>
#include<cmath>

using namespace std;

double pi;
double x,y,now;

int main()
{
	int t;
	pi=acos(-1.0);
	int tcase=0;
	while(cin>>t)
	{
		tcase=0;
		while(t--)
		{
			tcase++;
			cin>>x>>y;
			cout<<"Property "<<tcase<<": This property will begin eroding in year "<<(int((x*x+y*y)*pi/2.0/50.0)+1)<<"."<<endl;
		}
		cout<<"END OF OUTPUT."<<endl;
	}
	
	return 0;
}
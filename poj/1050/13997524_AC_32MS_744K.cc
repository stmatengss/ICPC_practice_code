#include<iostream>
#include<cstring>
using namespace std;

int sum[104][104]={0};

int main()
{
	int i,j,k,n,temp;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>temp;
			sum[i][j]=sum[i][j-1]+temp;
		}
	int max=-100000000;
	int res=0;
	for(i=0;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			res=0;
			for(k=1;k<=n;k++)
			{
				res+=sum[k][j]-sum[k][i];
				if(res<0)res=0;
				if(res>max)max=res;
			}
		}
	cout<<max<<endl;
	return 0;
}
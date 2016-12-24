#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int isprimer[250004];
long long numprimer[250004];
int countprimer[1000004]={0};
int sumprimer[1000004]={0};

void primer()
{
	int counter=0,i,j;
	for(i=5;i<=200001;i=i+4)
		if(isprimer[i]==0)
		for(j=5*i;j<=200001;j=j+4*i)
		{
			isprimer[j]=1;
		}
	for(i=5;i<=200001;i=i+4)
	{
		if(isprimer[i]==0)
		{
			numprimer[counter]=i;
			counter++;
		}
	}
	for(i=0;i<counter;i++)
		for(j=i;j<counter;j++)
		{
			if((numprimer[i])*numprimer[j]<=1000001)countprimer[numprimer[i]*numprimer[j]]=1;
		}
	for(i=5;i<=1000001;i=i+4)
	{
		if(countprimer[i])sumprimer[i]=sumprimer[i-4]+1;
		else sumprimer[i]=sumprimer[i-4];
	}
	;
}

int main()
{
	int n;
	int counter;
	int i,j;
	primer();
	while(cin>>n)
	{
		counter=0;
		i=0;
		if(n==0)break;
//		while(numprimer[i]<=int(sqrt(n)))
//		{
//			if(n%numprimer[i]==0&&isprimer[n/numprimer[i]]==0&&(n/numprimer[i])%4==1)counter++;
//			i++;
//		}
		cout<<n<<' '<<sumprimer[n]<<endl;
	}
	return 0;
}
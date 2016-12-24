#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int M=1000;
const int N=1<<20+4;
int num;
int factor[M];
int isprimer[M]={0};
int numprimer[M/4];
int counter;
int numfactor;
int sumfactor;
long long Asum;
long long A[22];

void prim_find()
{
	int i,j;
	counter=0;
	for(i=2;i<M;i++)
	{
		if(isprimer[i]==0)
		for(j=2*i;j<M;j=j+i)
			isprimer[j]=1;
	}
	for(i=2;i<M;i++)
	{
		if(isprimer[i]==0)numprimer[counter++]=i;
	}
}

void Ann()
{
	int i;
	A[0]=1;
	for(i=1;i<=20;i++)
		A[i]=A[i-1]*i;
}

int main()
{
	int i;
	prim_find();
	Ann();
	while(cin>>num)
	{
		memset(factor,0,sizeof(factor));
		counter=0;
		numfactor=0;
		sumfactor=0;
		Asum=1;
		while(num>1)
		{
			while(num%numprimer[numfactor]==0)
			{
				factor[numfactor]++;
				num/=numprimer[numfactor];
			}
			numfactor++;
		}
		for(i=0;i<numfactor;i++)
		{
			sumfactor+=factor[i];
			Asum*=A[factor[i]];
		}			
		cout<<sumfactor<<' '<<(A[sumfactor]/Asum)<<endl;
	}
	
	return 0;
}
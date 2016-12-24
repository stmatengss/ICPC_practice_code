#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int pos[50004];
int l,n,m;

bool pending(int d)
{
	int i,j,counter=0;
	i=0;
	while(i<=n+1)
	{
		j=i+1;
		while(pos[j]-pos[i]<d&&j<=n+1)
		{
			if(j==n+1)return false;
			j++;
			counter++;
		}
		i=j;
	}
	if(counter>m)return false;
	return true;
}

int main()
{
	int i,j;
	int db,ub,mid;
	cin>>l>>n>>m;
	pos[0]=0;
	for(i=1;i<=n;i++)
		cin>>pos[i];
	sort(pos,pos+n+1);
	pos[n+1]=l;
	db=0,ub=l+1;
	while(ub-db>1)
	{
		mid=(ub+db)/2;
		if(pending(mid))db=mid;
		else ub=mid;
	}
	cout<<db<<endl;
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int res[14];
void printtab()
{
	int i,j,k,n,m,f;
	bool ST;
	for(i=1;i<14;i++)
	{
		n=i*2;
		for(j=1;;j++)
		{
			f=0;
			ST=true;
			for(k=1;k<=i;k++)
			{
				f=(f+j-1)%(n-k+1);
				if(f<i)
				{
					ST=false;
					break;
				}
			}
			if(ST){
				res[i]=j;break;
			}
		}
	}
}

int main()
{
	int num;
	printtab();
	while(cin>>num&&num!=0)
	{
		cout<<res[num]<<endl;
	}	
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct stick{
	int len;
	int w;
};
stick s[5004];
int n;
int state[5004];

int cmp(stick a,stick b)
{
	if(a.len==b.len)return a.w<b.w;
	return a.len<b.len;
}

int main()
{
	int t;
	cin>>t;
	int i,j,counter,temp;
	while(t--)
	{
		cin>>n;
		counter=0;
		for(i=0;i<n;i++)
		{
			cin>>s[i].len>>s[i].w;
			state[i]=0;	
		}			
		sort(s,s+n,cmp);
		;
		for(i=0;i<n;i++)
		{
			if(state[i]==0)
			{
				temp=s[i].w;
				for(j=i+1;j<n;j++)
				{
					if(state[j]==0&&temp<=s[j].w)
					{
						temp=s[j].w;
						state[j]=1;
					}
				}
				counter++;
			}
		}
		cout<<counter<<endl;
	}
	return 0;
}
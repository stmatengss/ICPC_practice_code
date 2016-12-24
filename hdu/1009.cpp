////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-22 20:22:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:408KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;

int j[1004],f[1004],hash[1004];
int m,n;
int sum;
float k[1004],ans;
int i,no;

int cmp(int i,int j)
{
	return k[i]>k[j];
}

int main()
{
	while(cin>>sum>>m)
	{
		if(sum==-1)break;
		
		ans=0;
		for(i=0;i<m;i++)hash[i]=i;
		
		for(i=0;i<m;i++)
		{
			cin>>j[i]>>f[i];
			k[i]=(float)j[i]/f[i];
		}
		
		sort(hash,hash+m,cmp);
		
		for(i=0;i<m;i++)
		{
		    no=hash[i];
			if(sum>=f[no])
			{
				sum-=f[no];
				ans+=j[no];
			}
			else
			{
				ans+=(float)sum/f[no]*j[no];
				break;
			}	
		}
		
		printf("%.3f\n",ans);
		
	}
	return 0;
}
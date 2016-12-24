////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-22 18:53:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:508KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int u[6000],v[6000],w[6000],hash[6000],p[104];
int sum,counter,ans,rest,position;
int U,V,W,sure,x,y;

int cmp(int i,int j)
{
	return w[i]<w[j];
}

int find(int x)
{
	return x==p[x]?x:find(p[x]);
}

int main()
{
	int i;
	while(cin>>n)
	{
		if(n==0)break;
		counter=0;
		sum=0;
		m=(n-1)*n/2;
		for(i=1;i<=n;i++)p[i]=i;
		for(i=0;i<m;i++)
		{
		//cin>>U>>V>>W>>sure;
		scanf("%d%d%d%d",&U,&V,&W,&sure);
			if(sure==0)
			{
				u[counter]=U;
				v[counter]=V;
				w[counter]=W;
				hash[counter]=counter;
				counter++;
			}
			else
			{	
				p[U]=V;
			}
	    }
	    rest=counter;
	    
	    sort(hash,hash+rest,cmp);
	    
	    for(i=0;i<rest;i++)
	    {
	    	position=hash[i];
	    	if((x=find(u[position]))!=(y=find(v[position])))
	    	{
	    		sum+=w[position];
	    		p[x]=y;
	    	}
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
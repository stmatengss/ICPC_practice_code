#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct edge{
	int from,to,value;
};
edge e[10004];
int dis[104][104];
int father[104];
int cmp(const edge a,const edge b)
{
	return a.value<b.value;
}

int find(int x)
{
	if(father[x]==x)return x;
	else return find(father[x]);
}

int main()
{
	int n,i,j,temp,E=0;
	while(cin>>n)
	{
	E=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
	    {
	    	cin>>temp;
	    	if(j<i&&temp!=0)
	    	{
	    		E++;
	    		e[E].from=i;
	    		e[E].to=j;
	    		e[E].value=temp;
	    	}
	    }
	for(i=1;i<=n;i++)
	{
		father[i]=i;
	}
	sort(e+1,e+E+1,cmp);
	long long res=0;	
	for(i=1;i<=E;i++)
	{
		if(find(e[i].from)!=find(e[i].to))
		{
			father[e[i].from]=father[e[i].to];
			res+=e[i].value;
		}
	}
	cout<<res<<endl;
	}
	return 0; 
}
/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
*/

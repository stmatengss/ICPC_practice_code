#include<iostream>
#include<cstring>

using namespace std;
int n,m,w;
struct edge{
	int from,to,value;
};
edge e[10000];
int E,V;
int v[500];

void pending()
{
	int i,j;
	fill(v,v+V,0);
	bool ST;
	edge temp;
	for(i=0;i<V;i++)
	{
		ST=true;
		for(j=0;j<E;j++)
		{
			temp=e[j];
			if(v[temp.to]>v[temp.from]+temp.value)
			{
				v[temp.to]=v[temp.from]+temp.value;
				if(i==V-1)
				{
					cout<<"YES"<<endl;
					return;
				}
				ST=false;
			}	
		}
		if(ST)break;
	}
	cout<<"NO"<<endl;
}

int main()
{
	int t,i;
	int from,to,value;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>w;
		for(i=0;i<2*m;i+=2)
		{
			cin>>from>>to>>value;
			e[i].from=from,e[i].to=to,e[i].value=value;
			e[i+1].to=from,e[i+1].from=to,e[i+1].value=value;
		}
		for(i=2*m;i<2*m+w;i++)
		{
			cin>>from>>to>>value;
			e[i].from=from,e[i].to=to,e[i].value=-value;
		}
		V=n;
		E=2*m+w;
		pending();
	}
	return 0;
}

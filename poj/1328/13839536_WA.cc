#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ABS(x) (x>0?x:-x)

using namespace std;

struct point{
	int x;
	int y;
	double pos;
};
point p[1004];
int D;
double pos;
int counter;
int hash[1004];
int ST;

int cmp(point a,point b)
{
	return a.pos<b.pos;
}

int main()
{
	int n,d,m;
	int i,j;
	int x,y;
	int t=1;
	while(true)
	{ 
		cin>>n>>d;
		if(n==0&&d==0)break;
		D=d*d;
		m=0;
		counter=0;
		ST=0;
		memset(hash,0,sizeof(hash));
		memset(p,0,sizeof(p));	
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			if(y<0)ST=1;
			if(ABS(y)<=d)
			{
				p[m].pos=(double)x+sqrt(double(D-y*y));
				p[m].x=x;
				p[m].y=y;
				m++;	
			}
			
		}
		sort(p,p+m,cmp);
		for(i=0;i<=m;i++)
		{
			if(hash[i]==0)
			{
				pos=p[i].pos;
				hash[i]=1;
				counter++;	
			}	
			for(j=i+1;j<=m;j++)
			{
				if((p[j].x-pos)*(p[j].x-pos)+p[j].y*p[j].y<=D)hash[j]=1;
			}
		}	
		if(m!=n||d<0||ST)cout<<"Case "<<t<<": "<<"-1"<<endl;
		else cout<<"Case "<<t<<": "<<counter<<endl;
		t++;
	}
	
	return 0;
}
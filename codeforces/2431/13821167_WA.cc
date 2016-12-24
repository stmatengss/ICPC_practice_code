/*
	Name: POJ2431 
	Copyright: 
	Author: 
	Date: 26/01/15 20:57
	Description: use priority_queue to solve.
*/

#include<iostream>
#include<queue>
#include<algorithm>

using  namespace std;

const int N=10004; 
struct point{
	int a;
	int b;
}; 
point c[N];
int a[N],b[N];
int l,p;
priority_queue<int > q;
int n;

bool cmp(const point &a,const point &b)
{
	return a.a>b.a;
}

int main()
{
	int dis=0;
	int count=0;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)cin>>c[i].a>>c[i].b;
	cin>>l>>p;
	sort(c,c+n,cmp);
	//dis=l;
/*
2
5 10
10 20
30 5
*/	
	for(i=0;i<n;i++)
	{
		//if(dis+p<=c[i].a)
		{
			while(dis+p<l-c[i].a)
			{
				if(q.empty())
				{
					cout<<"-1"<<endl;
					return 0;
				}
				p+=q.top();
				q.pop();
				count++;
			}
			q.push(c[i].b);
			p-=((l-c[i].a)-dis);
			dis=l-c[i].a;
		}
			
	}
	if(dis+p>=l)
	cout<<count<<endl;
	else
	cout<<"-1"<<endl;
	return 0;
}
/*
4
4 4
5 2
11 5
15 10
25 10
*/
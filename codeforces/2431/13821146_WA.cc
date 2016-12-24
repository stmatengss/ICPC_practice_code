/*
	Name: POJ2431 
	Copyright: 
	Author: 
	Date: 26/01/15 20:57
	Description: use priority_queue to solve.
*/

#include<iostream>
#include<queue>

using  namespace std;

const int N=10004;
int a[N],b[N];
int l,p;
priority_queue<int > q;
int n;

int main()
{
	int dis=0;
	int count=0;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	cin>>l>>p;
	//dis=l;
/*
2
5 10
10 20
30 5
*/	
	for(i=n;i>=1;i--)
	{
		//if(dis+p<=a[i])
		{
			while(dis+p<l-a[i])
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
			q.push(b[i]);
			p-=((l-a[i])-dis);
			dis=l-a[i];
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
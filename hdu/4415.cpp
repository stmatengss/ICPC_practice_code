////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:01:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4415
////Problem Title: 
////Run result: Accept
////Run time:1450MS
////Run memory:4312KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
struct sword{
	int a;
	int b;
	bool used;
	sword(int a,int b):a(a),b(b){
		used=false;
	}
};
vector<sword>v;
typedef long long ll;

int cmp(sword x,sword y)
{
	return x.a<y.a;
}

int main()
{
	int t;
	int i,j,k;
	int a,b;
	ll res1=0,res2=0,sum=0;
	ll counter1=0,counter2=0,counter=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		v.clear();
		sum=0;
		res1=m,res2=m;
		counter1=0,counter2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			v.push_back(sword(a,b));
		}
		sort(v.begin(),v.end(),cmp);
		for(i=0;i<n;i++)
				sum+=v[i].b;
		for(i=0;i<n;i++)
		{
			if(!v[i].b&&res1>=v[i].a)
			{
					counter1++;
					res1-=v[i].a;
			}
		}
		i=0;
		while(v[i].b==0&&i<n)i++;
		if(i<n&&v[i].a<=m)
		{
			if(sum>=n-1)
			{
				res2-=v[i].a;
				counter2=n;
			}
			else
			{
				v[i].used=true;
				counter2=sum+1;
				res2-=v[i].a;
				for(i=n-1;i>=0&&sum;i--)
				{
					if(!v[i].used)
					{
						v[i].used=true;
						sum--;
					}
				}
				for(i=0;i<n&&res2>=v[i].a;i++)
				{
					if(!v[i].used)
					{
						counter2++;
						res2-=v[i].a;
					}
				}
			}
		}
		counter++;
		cout<<"Case "<<counter<<": ";
		if(counter1>counter2)
		{
			cout<<counter1<<' '<<(m-res1)<<endl;
		}
		else if(counter1==counter2&&res1>res2)
		{
			cout<<counter1<<' '<<(m-res1)<<endl;
		}
		else
		{
			cout<<counter2<<' '<<(m-res2)<<endl;
		}
	}
	return 0;
}
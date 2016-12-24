////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:02:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4417
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:4688KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=100004;

struct area{
	int left;
	int right;
	int h;
	int no;
	area(int l,int r,int h,int no):left(l),right(r),h(h),no(no){
	}
	int operator<(const area &a)const{
		return h<a.h;
	}
};

struct num{
	int h;
	int no;
	num(int h,int no):h(h),no(no){
	}
	int operator<(const num &a)const{
		return h<a.h;
	}
};

int n,m;
vector<area>query;
vector<num>point;
int arr[maxn];
int res[maxn];

inline int lowbit(int x)
{
	return (-x)&x;
}

void add(int x,int num)
{
	int i;
	for(i=x;i<=n;i+=lowbit(i))
	{
		arr[i]+=num;
	}
}

int find(int x)
{
	int i;
	int sum=0;
	for(i=x;i>=1;i-=lowbit(i))
	{
		sum+=arr[i];
	}
	return sum;
}

int main()
{
	int i,j,k;
	int t,counter=0;
	int left,right,h,now;
	cin>>t;
	while(t--)
	{
		counter++;
		point.clear();
		query.clear();
		memset(arr,0,sizeof(arr));
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
//			cin>>h;
			scanf("%d",&h);
			point.push_back(num(h,i));
		}
		for(i=1;i<=m;i++)
		{
//			cin>>left>>right>>h;
			scanf("%d%d%d",&left,&right,&h);
			query.push_back(area(left,right,h,i));
		}
		sort(point.begin(),point.end());
		sort(query.begin(),query.end());
		j=0;
		for(i=0;i<m;i++)
		{
			for(;j<n&&point[j].h<=query[i].h;j++)
			{
				add(point[j].no,1);
			}
			res[query[i].no]=find(query[i].right+1)-find(query[i].left);
		}
//		cout<<"Case "<<counter<<":"<<endl;
		printf("Case %d:\n",counter);
		for(i=1;i<=m;i++)
		{
			printf("%d\n",res[i]);
//			cout<<res[i]<<endl;
		}
	}
	return 0;
}
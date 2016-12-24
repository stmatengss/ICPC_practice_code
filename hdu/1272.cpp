////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-16 21:17:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:812MS
////Run memory:2676KB
//////////////////System Comment End//////////////////
#include<iostream>

using namespace std;

int father[100004];
int v[100004]={0};
int ST;
int counter;

int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}

int unit(int x,int y)
{
	x=find(x);
	y=find(y);
	v[x]=1;
	v[y]=1;
	if(x==y)return 1;
    father[x]=y;
    return 0;
}

void init()
{
	int i;
	for(i=1;i<=100004;i++)
       father[i]=i;
	for(i=1;i<=100004;i++)
       v[i]=0;  	      
}

int main()
{
	int x,y;
	int i;
	while(cin>>x>>y)
	{
	  if(x==0&&y==0)
	  {
	    cout<<"Yes"<<endl;
	  }
	  if(x==-1&&y==-1)break;
	  else
	  {
	  	init();
	  	ST=1;
	  	counter=0;
	  	unit(x,y);
	  	while(cin>>x>>y)
   	    {
   	    	if(x==0&&y==0)break;
         	if(unit(x,y))
			{
				//cout<<"No"<<endl;
				ST=0;
				//break;
         	}
			 	
	    }
	    for(i=1;i<=100000;i++)
           if(v[i]&&father[i]==i)counter++;
        if(counter>=2)ST=0;
	    if(ST)cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	  }	 
    }
	return 0;
}
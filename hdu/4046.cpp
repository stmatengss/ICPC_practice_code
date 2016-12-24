////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-08-28 22:09:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4046
////Problem Title: 
////Run result: Accept
////Run time:1734MS
////Run memory:524KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>

using namespace std;

char a[50005];
int b[50005]={0};
//b --> 0     101 --> LOVE
int main()
{
    int t;
    int n,m;
    int i,j;
    cin>>t;
    int counter=1;
    while(t--)
    {
              cin>>n>>m;
              cout<<"Case "<<counter<<":"<<endl;
              char temp;
              int temp1;
              int start,end;
              int sum=0;
           /* for(i=0;i<n;i++)
              {
                  cin>>a[i];
              }
              */
              cin>>a;
              for(i=0;i<n-2;i++)
              {
                  if(a[i]=='w'&&a[i+1]=='b'&&a[i+2]=='w')b[i]=1;
                  else b[i]=0;
              }
              for(i=0;i<m;i++)
              {
                  cin>>temp1;
                  if(temp1==0)
                  {
                      cin>>start>>end;
                      for(j=start;j<=end-2;j++)
                      {
                          sum+=b[j];
                      }
                      cout<<sum<<endl;
                      sum=0;
                  }
                  else
                  {
                      cin>>temp1>>temp;
                      a[temp1]=temp;
                      if(a[temp1-2]=='w'&&a[temp1-1]=='b'&&a[temp1]=='w'&&temp1-2>=0&&temp1<n)b[temp1-2]=1;
                      else b[temp1-2]=0;
                      if(a[temp1-1]=='w'&&a[temp1]=='b'&&a[temp1+1]=='w'&&temp1-1>=0&&temp1+1<n)b[temp1-1]=1;
                      else b[temp1-1]=0;
                      if(a[temp1]=='w'&&a[temp1+1]=='b'&&a[temp1+2]=='w'&&temp1>=0&&temp1+2<n)b[temp1]=1;
                      else b[temp1]=0;
                  }
              }
              counter++;
    }
    //while(1){}
    return 0;
}

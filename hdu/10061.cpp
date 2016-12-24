////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-08 00:13:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1006
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1872KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
using namespace std;


const double hm=11.0/120,hs=719.0/120,sm=59.0/10;	//相对角速度
const double T_hm=43200.0/11,T_hs=43200.0/719,T_sm=3600.0/59;   //相对周期

inline double min(double a,double b,double c)
{
  double temp=(a>b)?b:a;

  return (c>temp)?temp:c;
}

inline double max(double a,double b,double c)
{
  double temp=(a>b)?a:b;

  return (c>temp)?c:temp;
}

int main()
{
  double degree;
  double x[3],y[3];
  double m[3],n[3];
  double end,begin,sum;

  while(cin>>degree , degree!=-1)
  {
    x[0]=degree/hm;
    x[1]=degree/hs;
    x[2]=degree/sm;

    y[0]=(360-degree)/hm;
    y[1]=(360-degree)/hs;
    y[2]=(360-degree)/sm;

    sum=0.0;
    for(m[0]=x[0],n[0]=y[0];n[0]<=43200.000001;m[0]+=T_hm,n[0]+=T_hm)
    {
      for(m[1]=x[1],n[1]=y[1];n[1]<=43200.000001;m[1]+=T_hs,n[1]+=T_hs)
      {
        if(n[0]<m[1])
          break;
        if(m[0]>n[1])
          continue;

        for(m[2]=x[2],n[2]=y[2];n[2]<=43200.000001;m[2]+=T_sm,n[2]+=T_sm)
        {
          if(n[0]<m[2] || n[1]<m[2])
            break;
          if(m[0]>n[2] || m[1]>n[2])
            continue;

          begin=max(m[0],m[1],m[2]);
          end=min(n[0],n[1],n[2]);
          
          if(end>begin)
             sum+=end-begin;
        }
      }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum*100.0/43200<<endl;
  }

  return 0;
}
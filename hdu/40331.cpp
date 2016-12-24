////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-08-30 14:55:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#define pi 3.14159265359
#define inf (1e-9)

using namespace std;

double ang[104];
double v[104];
double r;
int n;

double solve_angle(double a,double b,double c)
{
       return acos((-a*a+b*b+c*c)/(2.0*b*c));
}


int solve(double temp)
{
    double sum=0;
    int i;
    for(i=1;i<n;i++)
    {            
         if(v[i]+v[i+1]<=temp)return 0;
         if(v[i]-v[i+1]>=temp&&v[i+1]-v[i]>=temp)return 2;           
         sum+=solve_angle(temp,v[i],v[(i+1)]);            
    }
    {
         if(v[n]+v[1]<=temp)return 0;
         if(v[n]-v[1]>=temp&&v[1]-v[n]>=temp)return 2;              
         sum+=solve_angle(temp,v[n],v[1]); 
    }
    if((sum-2*pi)<0.000001&&(2*pi-sum)<=0.000001)return 1;
    if((sum-2*pi)>0)return 0;
    else return 2;
}



int main()
{
    int t;
    int i,j;
    cin>>t;
    int counter=1;
    while(t--)
    {
          cin>>n;
          for(i=1;i<=n;i++)cin>>v[i];
          cout<<"Case "<<counter<<": ";
          double le=0.0,ri=20000.0,mid;
          int flag=1;
          while(ri-le>0.000001)
          {
                mid=(le+ri)/2;
                int st=solve(mid);
                if(st==1)
                {
                     printf("%.3f\n",mid);
                     flag=0;
                     break;      
                }
                else if(st==2)
                {
                     le=mid;
                }
                else ri=mid;
                          
          }
          if(flag)cout<<"impossible"<<endl;
          counter++;    
    }
    //while(1){}    
    return 0;
}

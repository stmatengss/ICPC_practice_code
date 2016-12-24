#include<stdio.h>
#define N 200
#include<math.h>

long long num[N],a[N];


int fun1(int c)
{
    int count=0;
    while(c){c/=10;count++;}
    return count;
}

void solve()
{
    long long  b,temp,temp1,sum;
    a[0]=0;
    int i,n=0;
    int n1=0;
    int n2=0; 
    scanf("%lld",&b);
    while(b>num[n])n++;
    temp=b-num[n-1];
    //printf("%lld\n",temp);
    while(temp>a[n1])n1++;//printf("%d\n",n1);
    temp1=a[n1]-temp;
    
    //for(i=0;i<=temp1+1;i++)
        { n1/=pow(10,temp1); n2=n1%10;  }
    printf("%d\n",n2);   
}

int main()
{
    
    int i,t;
    a[0]=0;
    num[0]=0;
    for(i=1;i<=N;i++)
    {
       a[i]=a[i-1]+fun1(i);//printf("%lld\t",a[i]);
       num[i]=num[i-1]+a[i];//printf("%lld\t",num[i]);
    }
    scanf("%d",&t);
    while(t)
    {
            solve();
            t--;
    }
    return 0;
}

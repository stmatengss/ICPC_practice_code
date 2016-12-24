#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int num[5004];
int tab[5004];
int tmp;

inline int Abs(int a)
{
    if(a>0)
        return a;
    return -a;
}

int main()
{
    int n;
    int st;
    int i;
    while(cin>>n)
    {
        st=0;
        cin>>num[1];
        memset(tab,0,sizeof(tab));
        for(i=2;i<=n;i++)
        {
            cin>>num[i];
            tmp=Abs(num[i]-num[i-1]);
            if(tab[tmp]==1||tmp==0||tmp>n-1)
            {
                st=1;
            }
            tab[tmp]++;
        }
        if(st)
        {
            cout<<"Not jolly"<<endl;
        }
        else
            cout<<"Jolly"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

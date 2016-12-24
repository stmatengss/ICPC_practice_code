#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char a[1004],b[1004];
int cal[28];
//string res;

int main()
{
    int i,j;
    while(gets(a))
    {
        memset(cal,0,sizeof(cal));
        gets(b);
        for(i=0;i<strlen(a);i++)
        {
            cal[a[i]-'a']=1;
        }
        for(i=0;i<strlen(b);i++)
        {
            if(cal[b[i]-'a']==1)
                cal[b[i]-'a']=2;
        }
        for(i=0;i<=25;i++)
        {
            if(cal[i]==2)
                cout<<char('a'+i);
        }
        cout<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

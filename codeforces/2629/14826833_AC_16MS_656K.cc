#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char a[1004],b[1004];
int cal[2][28];
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
            cal[0][a[i]-'a']++;
        }
        for(i=0;i<strlen(b);i++)
        {
//            if(cal[b[i]-'a']==1)
            cal[1][b[i]-'a']++;
        }
        for(i=0;i<=25;i++)
        {
            for(j=0;j<min(cal[0][i],cal[1][i]);j++)
                cout<<char('a'+i);
        }
        cout<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

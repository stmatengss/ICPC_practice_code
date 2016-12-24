#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1000004];
int num[1000004];

int main()
{
    int len;
    int flag;
    int i,j,k;
    int counter=1;
    while(true)
    {
        scanf("%s",s);
        len=strlen(s);
        if(s[0]=='0'&&len==1)
            break;
        for(i=0;i<len;i++)
        {
            num[i]=s[i]-'0';
        }
        flag=0;
        for(i=len-2;i>=0;i--)
        {
            if(flag)num[i]--;
            if(num[i]<num[i+1])
            {
                flag=1;
                num[i]=10+num[i]-num[i+1];
            }
            else
            {
                flag=0;
                num[i]=num[i]-num[i+1];
            }
        }
        printf("%d. ",counter++);
        if(num[0])
        {
            for(i=0;i<len;i++)putchar('0'+num[i]);
            putchar('\n');
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 16:42:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1532KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

//string s;
char s[1004];

int main()
{
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]<='Z'&&s[i]>='A')putchar(s[i]-('A'-'a'));
            else putchar(s[i]);
        }
        putchar('\n');
//        transform(s.begin(), s.end(), s.begin(), toupper);
//        cout<<s<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

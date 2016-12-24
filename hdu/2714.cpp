////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 19:54:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2714
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i,j,k;
    string s;
    int sum;
    int res;
    int st;
    int state;
    while(cin>>s)
    {
        sum=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                 st=i;
            }
            else
            {
                if(i==9&&s[i]=='X')
                    sum+=10;
                else
                    sum+=(s[i]-'0')*(10-i);
            }
        }
        if(st==9)
        {
            state=1;
            for(i=0;i<=10;i++)
            {
                if((sum+i)%11==0)
                {
                    state=0;
                    if(i==10)
                        cout<<"X"<<endl;
                    else
                        cout<<i<<endl;
                    break;
                }
            }
            if(state)
                cout<<"-1"<<endl;
        }
        else
        {
            state=1;
            for(i=0;i<10;i++)
            {
                if((sum+(10-st)*i)%11==0)
                {
                    state=0;
                    cout<<i<<endl;
                    break;
                }
            }
            if(state)
                cout<<"-1"<<endl;
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

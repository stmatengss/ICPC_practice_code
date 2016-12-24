////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 20:17:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1238
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s[10004];

int main()
{
    int i,j,k;
    int t;
    int flag,maxone;
    int success,pending;
    string now[2];
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxone=-1;
        success=0;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            if(s[i].length()>maxone)
            {
                maxone=s[i].length();
                flag=i;
            }
        }
        for(i=s[flag].length();i>=1;i--)
        {
            for(j=0;j<=s[flag].length()-i;j++)
            {
                success=1;
                now[0]=s[flag].substr(j,i);
                now[1]=s[flag].substr(j,i);
                reverse(now[1].begin(),now[1].end());
                for(k=0;k<n;k++)
                {
                    if(s[k].find(now[0])==string::npos&&s[k].find(now[1])==string::npos)
                    {
                        success=0;
                        break;
                    }
                }
                if(success==1)
                {
                    goto en;
                }
            }
        }
        en:
        if(success)cout<<i<<endl;
        else cout<<"0"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-25 19:48:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4550
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1652KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string s,res[3];

int main()
{
    int i,j;
    int t;
    char minone;
    int pos;
    bool st;
    cin>>t;
    while(t--)
    {
        pos=-1;
        minone='9'+1;
        cin>>s;
        res[0]="",res[1]="";
        for(i=0;i<s.size();i++)
        {
            if(s[i]!='0'&&s[i]<=minone)
            {
                pos=i;
                minone=s[i];
            }
        }
        for(i=0;i<pos;i++)
        {
            j=0;
            while(j<res[0].size()&&res[0][j]==s[i])j++;
            if(j==pos||s[i]>res[0][j])
            {
                res[0]=res[0]+s[i];
            }
            else
            {
                res[0]=s[i]+res[0];
            }
        }
        if(pos+1<s.size())res[1]=s.substr(pos+1,s.size()-pos-1);
        res[2]=s[pos]+res[0]+res[1];
        cout<<res[2]<<endl;
    }
    return 0;
}

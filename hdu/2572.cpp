////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-15 21:11:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2572
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string s[4];
vector<int>pos[3];
int len1,len2;
string res;

int main()
{
    int i,j;
    int t;
    cin>>t;
    while(t--)
    {
        for(j=0;j<3;j++)
            cin>>s[j];
        pos[1].clear();
        pos[2].clear();
        for(i=0;i<s[0].length();i++)
        {
            if(i+s[1].length()<=s[0].length()&&s[0].substr(i,s[1].length())==s[1])
                    pos[1].push_back(i);
            if(i+s[2].length()<=s[0].length()&&s[0].substr(i,s[2].length())==s[2])
                    pos[2].push_back(i);
        }
        int st=1;
        res="";
        for(i=0;i<pos[1].size();i++)
        {
            for(j=0;j<pos[2].size();j++)
            {
                    if(st)
                    {
                        res=s[0].substr(min(pos[1][i],pos[2][j]),
                        max(pos[1][i]+s[1].length(),pos[2][j]+s[2].length())-min(pos[1][i],pos[2][j]));
                        st=0;
                    }
                    else
                    {
                        if(max(pos[1][i]+s[1].length(),pos[2][j]+s[2].length())-min(pos[1][i],pos[2][j])<res.size())
                        {
                            res=s[0].substr(min(pos[1][i],pos[2][j]),
                            max(pos[1][i]+s[1].length(),pos[2][j]+s[2].length())-min(pos[1][i],pos[2][j]));
                        }
                        else if(max(pos[1][i]+s[1].length(),pos[2][j]+s[2].length())-min(pos[1][i],pos[2][j])==res.size())
                        {
                            res=min(res,
                            s[0].substr(min(pos[1][i],pos[2][j]),
                            max(pos[1][i]+s[1].length(),pos[2][j]+s[2].length())-min(pos[1][i],pos[2][j])
                            ));
                        }
                    }

            }
        }
        if(st)
        {
            cout<<"No"<<endl;
        }
        else
            cout<<res<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
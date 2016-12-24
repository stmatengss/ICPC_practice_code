////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 15:35:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1708
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int rec[55][27];
int k;
string s[2];

int main()
{
    int i,j;
    int t;
    cin>>t;
    while(t--)
    {
        memset(rec,0,sizeof(rec));
        s[0]="",s[1]="";
        cin>>s[0]>>s[1]>>k;
        for(i=0;i<=1;i++)
        {
            for(j=0;j<s[i].length();j++)
            {
                rec[i][s[i][j]-'a']++;
            }
        }
        for(i=2;i<=k;i++)
        {
            for(j=0;j<26;j++)
            {
                rec[i][j]=rec[i-1][j]+rec[i-2][j];
            }
        }
        for(i=0;i<26;i++)
            cout<<char(i+'a')<<':'<<rec[k][i]<<endl;
        cout<<endl;
    }
    return 0;
}
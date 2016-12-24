////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 09:58:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4291
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>

using namespace std;

long long MOD = 1000000007LL;

struct matrix
{
    long long m[2][2];
}ans, base;

matrix multi(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 2; ++k)
                tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
        }
    }
    return tmp;
}
long long fast_mod(int n)  // &#199;車&#190;&#216;&#213;車 base 米&#196;  n ∩&#206;&#195;Y
{
    base.m[0][0] = 3;
	base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    ans.m[0][0] = ans.m[1][1] = 1;  // ans 3&#245;那&#188;&#187;‘&#206;a米ㄓ&#206;&#187;&#190;&#216;&#213;車
    ans.m[0][1] = ans.m[1][0] = 0;
    while(n)
    {
        if(n & 1)  //那米&#207;&#214; ans *= t; &#198;&#228;&#214;D辰a&#207;豕～&#209; ans&#184;3&#214;米&#184;&#248; tmp㏒&#172;豕&#187;o車車&#195; ans = tmp * t
        {
            ans = multi(ans, base);
        }
        base = multi(base, base);
        n >>= 1;
    }
    return ans.m[0][1];
}

int main()
{
    long long n;
//    table();
    while(cin>>n)
    {
    	MOD=183120LL;
    	long long res=fast_mod(n%MOD);
    	MOD=222222224LL;
    	res=fast_mod(res%MOD);
    	MOD=1000000007LL;
    	res=fast_mod(res%MOD)%1000000007LL;
    	cout<<res<<endl;
    }
    return 0;
}
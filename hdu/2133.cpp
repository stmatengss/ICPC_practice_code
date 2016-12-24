////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-18 19:14:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int year,month,day;
string res[8]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int whatday(int d,int m,int y)
{
    int ans;
    if(m==1||m==2)
        m+=12,y--;
//    if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
//        ans=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
//    else
        ans=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return ans;
}

int main()
{
    while(cin>>year>>month>>day)
    {
        if(month!=0&&day!=0)
        {
            if((year%4==0&&year%100!=0)||(year%400==0))
            {
                if(day<=days[1][month])
                {
                    cout<<res[whatday(day,month,year)]<<endl;
                }
                else
                {
                    cout<<"illegal"<<endl;
                }
            }
            else
            {
                if(day<=days[0][month])
                {
                    cout<<res[whatday(day,month,year)]<<endl;
                }
                else
                {
                    cout<<"illegal"<<endl;
                }
            }
        }
        else
        {
            cout<<"illegal"<<endl;
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}
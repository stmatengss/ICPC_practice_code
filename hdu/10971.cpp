////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 23:20:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:308KB
//////////////////System Comment End//////////////////
/*
1 1 1 1 1 1 1 1 
2 4 8 6 2 4 8 6 
3 9 7 1 3 9 7 1  
4 6 4 6 4 6 4 6 
5 5 5 5 5 5 5 5 
6 6 6 6 6 6 6 6  
7 9 3 1 7 9 3 1 
8 4 2 6 8 4 2 6 
9 1 9 1 9 1 9 1  
0 0 0 0 0 0 0 0 

0 0 0 0 0 0 0 0 
1 1 1 1 1 1 1 1 
6 2 4 8 6 2 4 8  
1 3 9 7 1 3 9 7   
6 4 6 4 6 4 6 4  
5 5 5 5 5 5 5 5  
6 6 6 6 6 6 6 6  
1 7 9 3 1 7 9 3  
6 8 4 2 6 8 4 2  
1 9 1 9 1 9 1 9   

*/
#include<stdio.h>
#include<iostream>
using namespace std;
int a[10][8]={
{0, 0, 0, 0, 0, 0, 0, 0}, 
{1, 1, 1, 1, 1, 1, 1, 1}, 
{6, 2, 4, 8, 6, 2, 4, 8},  
{1, 3, 9, 7, 1, 3, 9, 7},   
{6, 4, 6, 4, 6, 4, 6, 4},  
{5, 5, 5, 5, 5, 5, 5, 5},  
{6, 6, 6, 6, 6, 6, 6, 6},  
{1, 7, 9, 3, 1, 7, 9, 3}, 
{6, 8, 4, 2, 6, 8, 4, 2},  
{1, 9, 1, 9, 1, 9, 1, 9}, 
};

int main()
{
    long long i,j;
    while(cin>>i>>j)
    {
       cout<<a[i%10][j%8]<<endl;
    }
    return 0;
}

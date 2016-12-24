////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:16:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3687
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1780KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
const int R_SIZE = 60;
vector<int > grid[R_SIZE];
int main()
{
    int colomn_size;
    int row_size;
    int row,col;
    while(1)
    {
    scanf("%d%d",&row_size,&colomn_size);
    if(!row_size)
    {
        return 0;
    }
    for(int i=0;i<R_SIZE;i++)
    {
        grid[i].clear();

    }
    int n_student;
    n_student=row_size*row_size;
    for(int i=0;i<n_student;i++)
    {
        scanf("%d%d",&row,&col);
        row--;
        col--;
        grid[row].push_back(col);
    }
    for(int i=0;i<row_size;i++)
    {
        sort(grid[i].begin(),grid[i].end());
    }
    int min_sum=1<<29;


    for(int i=0;i<=colomn_size-row_size;i++)
    {
        int sum=0;
        for(int j=0;j<row_size;j++)
        {
            for(int k=0;k<row_size;k++)
            {
                sum+=abs(grid[j][k]-(k+i));
            }
        }
            if(min_sum>sum)
            {
                min_sum=sum;
            }

    }
    printf("%d\n",min_sum);
    }
}
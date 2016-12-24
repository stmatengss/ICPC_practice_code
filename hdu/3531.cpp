////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-04 16:10:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3531
////Problem Title: 
////Run result: Accept
////Run time:920MS
////Run memory:15532KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>

#define MAXNUM 1005

int num1[MAXNUM][MAXNUM]; // ��¼nά����
int num2[MAXNUM][MAXNUM]; // ��¼mά����
int sum1[MAXNUM][MAXNUM]; // ��¼nά����ĺ�
int sum2[MAXNUM][MAXNUM]; // ��¼mά����ĺ�

int main(void)
{
  int n,m;
  memset(sum1,0,sizeof(sum1));
  memset(sum2,0,sizeof(sum2));

  while (~scanf("%d%d",&n,&m))
  {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
      {
        scanf("%d",&num1[i][j]);
        sum1[i][j] = num1[i][j] + sum1[i][j-1] + sum1[i-1][j] - sum1[i-1][j-1]; // ���
      }
    for(int i=1; i<=m; i++)
      for(int j=1; j<=m; j++)
      {
        scanf("%d",&num2[i][j]);
        sum2[i][j] = num2[i][j] + sum2[i][j-1] + sum2[i-1][j] - sum2[i-1][j-1]; // ���
      }

    bool flag = false;

    for(int i=m; i<=n; i++)
    {
      for(int j=m; j<=n; j++)
      {
        // �ж��Ƿ�m*m�ľ�������е�֮���Ƿ����
        if (sum2[m][m] == sum1[i][j] - sum1[i][j-m] - sum1[i-m][j] + sum1[i-m][j-m])
        {
          int k;
          // �Ƚ϶Խ����ϵ�sum[i][j]
          for(k=1; k<=m; k++)
            if (sum2[k][k] != (sum1[i-m+k][j-m+k] - sum1[i-m][j-m+k] - sum1[i-m+k][j-m] + sum1[i-m][j-m]))
            {
              break;
            }
          if (k > m)
          {
            // �Ƚ����еĵ�
            for(k=1; k<=m; k++)
            {
              int l;
              for(l=1; l<=m; l++)
              {
                if (num2[k][l] != num1[i-m+k][j-m+l])
                {
                  break;
                }
              }
              if (l <= m)
                break;
            }
            if (k > m)
              flag = true;
          }
        }
        if (flag)
          break;
      }
    }

    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
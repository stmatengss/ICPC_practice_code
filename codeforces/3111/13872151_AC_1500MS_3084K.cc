#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
const double esp=1e-8;
int N,K;
struct Je
{
    int v,w,id;
    double y;
}je[100005];
int cmp(Je je1,Je je2)
{
    return je1.y>je2.y;
}
int main()
{
//    freopen("test.txt","r",stdin);
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&je[i].v,&je[i].w);
        je[i].y=0;je[i].id=i+1;
    }
    double ps=1,s=0;
    while(fabs(s-ps)>esp)
    {
        for(int i=0;i<N;i++)
            je[i].y=je[i].v-s*je[i].w;
        sort(je,je+N,cmp);
        double sv=0,sw=0;
        for(int i=0;i<K;i++)
        {
            sv+=je[i].v;sw+=je[i].w;
        }
        ps=s;s=sv/sw;
    }
    for(int i=0;i<K;i++)
        printf("%d ",je[i].id);
    printf("\n");
    return 0;
}








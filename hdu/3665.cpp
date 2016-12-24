////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:14:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3665
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1768KB
//////////////////System Comment End//////////////////
//============================================================================
// Name        : cat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
#include <stdio.h>
using namespace std;

const int N_CITY = 100;
const int INF = 1 << 29;

vector<int> graph[N_CITY];
vector<int> cost[N_CITY];
int dist[N_CITY];
int is_in_queue[N_CITY];
int n_city;
/*
 void spfa(int start)
 {
 int now_point;
 int next_point;
 int now_dist;
 for(int i=0;i<N_CITY;i++)
 {
 dist[i]=INF;
 is_in_queue[i]=0;
 }
 dist[start]=0;
 queue<int > q;
 is_in_queue[start]=1;
 q.push(start);
 while(!q.empty())
 {
 now_point=q.front();
 q.pop();
 is_in_queue[now_point]=0;
 for(int i=0;i<graph[now_point].size();i++)
 {
 next_point=graph[now_point][i];
 now_dist=cost[now_point][i];
 if(dist[next_point]>now_dist=)
 {

 }
 }

 }
 }*/

int matrix[N_CITY][N_CITY];
void init() {
	for (int i = 0; i < N_CITY; i++) {
		for (int j = 0; j < N_CITY; j++) {
			matrix[i][j] = INF;
		}
		matrix[i][i] = 0;
	}
}
int is_sea[N_CITY];

int main() {
	int n_towns;
	int n_edges;
	int target;
	int cost;
	int min_val = INF;
	while (scanf("%d", &n_towns) != -1) {
		init();
		min_val=INF;
		for (int i = 0; i < n_towns; i++) {
			scanf("%d", &n_edges);
			scanf("%d", is_sea + i);
			for (int j = 0; j < n_edges; j++) {
				scanf("%d%d", &target, &cost);
				matrix[i][target] = min(matrix[i][target], cost);
			}
		}
		for (int k = 0; k < n_towns; k++) {
			for (int i = 0; i < n_towns; i++) {
				for (int j = 0; j < n_towns; j++) {
					if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
						matrix[i][j] = matrix[i][k] + matrix[k][j];
					}
				}
			}
		}
		for (int i = 0; i < n_towns; i++) {
			if (is_sea[i]) {
				if (matrix[0][i] < min_val) {
					min_val = matrix[0][i];
				}
			}
		}
		printf("%d\n",min_val);
	}

}
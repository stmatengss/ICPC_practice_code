////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:15:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3668
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1796KB
//////////////////System Comment End//////////////////
//============================================================================
// Name        : 12_I.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double pi=3.141592653589;

int main() {
	double r,h,up;;
	double s;
	while(cin>>r>>h){
	if(2.0*r<=h)s=pi*r*r*h*2-16.0/3*r*r*r;
	else
	{
        up=sqrt(r*r-h*h/4.0);
        s=2*pi*r*r*h
        -8.0*r*r*(r-up)
        +8.0/3*(r*r*r-up*up*up)
        -2*h*h*up;
	}
	printf("%.4lf\n",s);
	}

	return 0;
}
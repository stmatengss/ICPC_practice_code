  #include<iostream>
  #include<cstdio>
  #include<algorithm>
  #include<cstring>
  using namespace std;
  
  int bit[1004][1004];
  int n,t,counter;
  
  void update(int x,int y)
  {
  		int i,j;
  		for(i=x;i>0;i-=i&-i)
  			for(j=y;j>0;j-=j&-j)
  			bit[i][j]++;
  }
  
  int get(int x,int y)
  {
  		int i,j;
  		int sum=0;
  		for(i=x;i<=n;i+=i&-i)
  			for(j=y;j<=n;j+=j&-j)
  			sum+=bit[i][j];
  		return sum;
  }
  
  int main()
  {
  	 char op;
  	 int x1,x2,y1,y2,x,y;
  	 cin>>counter;
  	 while(counter--)
  	 {
  	 	memset(bit,0,sizeof(bit));
  	 	cin>>n>>t;
  	 	while(t--)
  	 	{
  	 		cin>>op;
  	 		if(op=='C')
  	 		{
  	 			cin>>x1>>y1>>x2>>y2;
  	 			update(x2,y2);
  	 			update(x1-1,y2);
  	 			update(x2,y1-1);
  	 			update(x1-1,y1-1);
  	 		}
  	 		else
  	 		{
  	 			cin>>x>>y;
  	 			cout<<(get(x,y)%2)<<endl;
  	 		}
  	 	}
  	 }
  	 return 0;
  }

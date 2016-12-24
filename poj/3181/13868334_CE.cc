import java.io.*;
//import java.lang.reflect.Array;
import java.math.*;
import java.util.Arrays;
import java.util.Scanner;
//import java.util.Scanner;

public class test {
	public static void main(String[] args)
	{
		BigDecimal[] dp1 = new BigDecimal[1008];
		BigDecimal[] dp0 = new BigDecimal[1008];
		int n=0;
		int K=0;
		int i,j,k;
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNext()){
			n=cin.nextInt();
			K=cin.nextInt();
			Arrays.fill(dp1,BigDecimal.ONE);
			Arrays.fill(dp0,BigDecimal.ZERO);
			for(i=2;i<=K;i++)
			{
				for(j=0;j<=n;j++)
				{
					for(k=0;k<=n;k=k+i)
						if(j-k>=0)
						{
							if(i%2==0){
								dp0[j]=dp0[j].add(dp1[j-k]);
							}
							else {
								dp1[j]=dp1[j].add(dp0[j-k]);
							}
						}
						//dp[i%2][j]+=dp[(i-1)%2][j-k];
				}
				if(i%2==0)
				Arrays.fill(dp1,BigDecimal.ZERO);
				else {
					Arrays.fill(dp0,BigDecimal.ZERO);
				}
				//memset(dp[(i-1)%2],0,sizeof(dp[(i-1)%2]));
			}	
			if(K%2==0)
				System.out.println(dp0[n]);
				else {
					System.out.println(dp1[n]);
			}

		}
	}

}

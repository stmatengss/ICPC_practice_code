////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-16 17:12:25
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1502
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:15456KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger[][][] tab = new BigInteger[62][62][62];
		int i, j, k;
		tab[0][0][0]=BigInteger.ONE;
		for (i = 1; i <= 60; i++) {
			for (j = 0; j <= 60; j++) {
				for (k = 0; k <= 60; k++) {
					tab[i][j][k] = BigInteger.ZERO;
					if (i >= j && j >= k) {
						if(i-1>=j)tab[i][j][k]=tab[i][j][k].add(tab[i-1][j][k]);
						if(j-1>=k&&j>0)tab[i][j][k]=tab[i][j][k].add(tab[i][j-1][k]);
						if(j>=k-1&&k>0)tab[i][j][k]=tab[i][j][k].add(tab[i][j][k-1]);
					}
				}
			}
		}
		int n;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			n = cin.nextInt();
			System.out.println(tab[n][n][n]);
			System.out.println();
		}
	}

}

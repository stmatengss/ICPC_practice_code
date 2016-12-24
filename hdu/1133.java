////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:29:28
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:10560KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

import org.w3c.dom.css.Counter;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		Integer i, j;
		Integer n, m;
		BigInteger[][] dp = new BigInteger[104][104];
		BigInteger[] a = new BigInteger[104];
		a[0]=BigInteger.ONE;
		for (i = 1; i <= 100; i++) {
			a[i] = a[i - 1].multiply(new BigInteger(i.toString()));
		}
		for (i = 0; i <= 100; i++) {
			dp[i][0] = BigInteger.ONE;
			for (j = 1; j <= 100; j++) {
				dp[i][j] = BigInteger.ZERO;
			}
		}
		for (i = 1; i <= 100; i++) {
			for (j = 1; j <= i; j++) {
					dp[i][j] = dp[i - 1][j].add(dp[i][j - 1]);
			}
		}
		Integer counter=0;
		while (cin.hasNext()) {
			n = cin.nextInt();
			m = cin.nextInt();
			if (n == 0 && m == 0)
				break;
			counter++;
			System.out.println("Test #"+counter.toString()+":");
			System.out.println(dp[n][m].multiply(a[n]).multiply(a[m]));
		}
	}

}
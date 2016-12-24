////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:29:09
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:19152KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer i,j,n;
		BigInteger tab[] = new BigInteger[10004];
		for(i=1;i<=4;i++)
			tab[i]=BigInteger.ONE;
		for(i=5;i<=10000;i++)
			tab[i]=tab[i-1].add(tab[i-2]).add(tab[i-3]).add(tab[i-4]);
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			n=cin.nextInt();
			System.out.println(tab[n]);
		}
	}

}
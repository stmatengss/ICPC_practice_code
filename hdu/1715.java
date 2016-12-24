////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:28:34
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:13648KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer i,j,n,num;
		BigInteger tab[] = new BigInteger[1004];
		tab[1]=tab[2]=BigInteger.ONE;
		for(i=3;i<=1000;i++)
			tab[i]=tab[i-1].add(tab[i-2]);
		Scanner cin=new Scanner(System.in);
		n=cin.nextInt();
		while(n-->0){
			num=cin.nextInt();
			System.out.println(tab[num]);
		}
	}

}
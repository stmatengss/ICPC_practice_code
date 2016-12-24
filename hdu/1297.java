////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-17 15:13:26
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:13612KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

import com.sun.org.apache.xerces.internal.xinclude.XInclude11TextReader;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger tab[]=new BigInteger[1004];
		int i,j,k;
		tab[0]=BigInteger.ONE;
		tab[1]=BigInteger.ONE;
		tab[2]=new BigInteger("2");
		tab[3]=new BigInteger("4");
		for(i=4;i<=1000;i++){
			tab[i]=tab[i-1].add(tab[i-2]).add(tab[i-4]);
		}
		int n;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNextInt()){
			n=cin.nextInt();
			System.out.println(tab[n]);
		}
	}

}

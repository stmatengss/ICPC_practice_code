////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:27:41
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1865
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:13620KB
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
		String s;
		BigInteger tab[] = new BigInteger[1004];
		tab[0]=tab[1]=BigInteger.ONE;
		for(i=2;i<=1000;i++)
			tab[i]=tab[i-1].add(tab[i-2]);
		Scanner cin=new Scanner(System.in);
		n=cin.nextInt();
		cin.nextLine();
		while(n-->0){
			s=cin.nextLine();
			System.out.println(tab[s.length()]);
		}
	}

}
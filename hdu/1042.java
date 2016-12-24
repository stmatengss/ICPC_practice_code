////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:29:53
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:717MS
////Run memory:107428KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger []tab=new BigInteger[10004];
		tab[0]=BigInteger.ONE;
		Integer i,n;
		for(i=1;i<=10000;i++){
			tab[i]=tab[i-1].multiply(new BigInteger(i.toString()));
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			n=cin.nextInt();
			System.out.println(tab[n]);
		}
	}

}
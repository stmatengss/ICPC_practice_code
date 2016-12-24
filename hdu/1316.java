////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-17 17:30:11
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1316
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:10140KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger tab[] = new BigInteger[5004];
		int i, j, k;
		tab[1] = BigInteger.ONE;
		tab[2] = new BigInteger("2");
		for (i = 3; i <= 500; i++) {
			tab[i] = tab[i - 1].add(tab[i - 2]);
		}
		BigInteger begin, end;
		int left,right,mid;
		Scanner cin = new Scanner(System.in);
		while (true) {
			begin = cin.nextBigInteger();
			end = cin.nextBigInteger();
			if (begin.equals(BigInteger.ZERO) && end.equals(BigInteger.ZERO))
				break;
			left=0;right=500;
			mid=(right+left)/2;
			while(right-left>1){
				if(tab[mid].compareTo(begin)<0)left=mid;
				else right=mid;
				mid=(right+left)/2;
			}
			left=0;right=500;
			int mid2=(right+left)/2;
			while(right-left>1){
				if(tab[mid2].compareTo(end)>0)right=mid2;
				else left=mid2;
				mid2=(right+left)/2;
			}
			System.out.println(mid2-mid);
		}
	}
}

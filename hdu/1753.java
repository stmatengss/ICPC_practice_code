////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:28:13
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:10020KB
//////////////////System Comment End//////////////////
import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigDecimal a,b;
		String res;
		Integer i;
		Scanner cin=new Scanner(System.in);
		NumberFormat nf = NumberFormat.getInstance();
		while(cin.hasNext()){
			a=cin.nextBigDecimal();
			b=cin.nextBigDecimal();
			res=a.add(b).toString();
			i=res.length()-1;
			if(res.contains(".")){
				while(i>=0&&res.charAt(i)=='0'){
					res=res.substring(0,i);
					i--;
				}
			}
			if(res.charAt(res.length()-1)=='.')
				res=res.substring(0,res.length()-1);
			System.out.println(res);
		}
	}

}
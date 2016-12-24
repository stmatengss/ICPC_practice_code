////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 14:27:09
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2100
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:11520KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	static BigInteger cc=new BigInteger("26");
	
	static BigInteger trans(String s){
		BigInteger res=BigInteger.ZERO;
		Integer i,tmp;
		for(i=0;i<s.length();i++){
			tmp=s.charAt(i)-'A';
			res=res.multiply(cc);
			res=res.add(new BigInteger(tmp.toString()));
		}
//		System.out.println(res);
		return res;
	}
	
	static String trans(BigInteger s){
		String res="";
		if(s.equals(BigInteger.ZERO))return "A";
		int tmp;
		String tmps;
		char c;
		while(s.equals(BigInteger.ZERO)==false){
			tmps=s.mod(cc).toString();
			if(tmps.length()==2)
				tmp=(tmps.charAt(0)-'0')*10+(tmps.charAt(1)-'0');
			else 
				tmp=(tmps.charAt(0)-'0');
			tmp+=65;
			c=(char)tmp;
			res=c+res;
			s=s.divide(cc);
		}
		return res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger a,b;
		String sa[]=new String[3],s;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
//			s=cin.nextLine();
//			sa=s.split("  ");
			sa[0]=cin.next();
			sa[1]=cin.next();
			System.out.println(trans(trans(sa[0]).add(trans(sa[1]))));
		}
	}

}
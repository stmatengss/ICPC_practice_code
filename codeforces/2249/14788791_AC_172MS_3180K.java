import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		Integer n,k;
		while(true){
			n=in.nextInt();
			k=in.nextInt();
			//System.out.println(n);
			BigInteger res=BigInteger.ONE;
			if(n==0&&k==0)
			{
				break;
			}
			if(k>n-k){
				k=n-k;
			}
			//System.out.println(k);
			for(Integer i=0;i<k;i++){
				res=res.multiply(new BigInteger((new Integer(n-i)).toString()));
				//System.out.println((new Integer(n-i)).toString());
				//System.out.println(res);
			}
			for(Integer i=1;i<=k;i++){
				res=res.divide(new BigInteger((new Integer(i)).toString()));
				//System.out.println((new Integer(i)).toString());
			}
			System.out.println(res);
		}
	}

}

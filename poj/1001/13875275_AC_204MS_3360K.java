import java.math.*;
import java.util.Scanner;

public class Main{

	public static void main(String []args){
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			BigDecimal a=cin.nextBigDecimal();			
			int c=cin.nextInt();
			a=a.pow(c);
			String str=a.stripTrailingZeros().toPlainString();
			if(str.startsWith("0.")==true)
				str=str.substring(1);
			System.out.println(str);
		}
	}
}
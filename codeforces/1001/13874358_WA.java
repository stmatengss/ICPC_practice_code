import java.math.*;
import java.util.Scanner;

public class Main{

	public static void main(String []args){
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			BigDecimal a=cin.nextBigDecimal();			
			int c=cin.nextInt();
			BigDecimal b=a.pow(c);
			System.out.println(b);
		}
	}
}
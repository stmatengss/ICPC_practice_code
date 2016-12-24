////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-02 15:54:59
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:9700KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	static Matrix quickpow(Matrix ma,int n){
		Matrix res=new Matrix(ma.n);
		res.init();
		while(n>0){
			if((n&1)==1){
				res=res.multiply(ma);
			}
			ma=ma.multiply(ma);
			n=n>>1;
		}
		return res;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,j;
		int t,n,k;
		Scanner cin=new Scanner(System.in);
		t=cin.nextInt();
		while(t-->0){
			n=cin.nextInt();
			k=cin.nextInt();
			Matrix ma=new Matrix(n);
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					ma.a[i][j]=cin.nextLong();
				}
			}
			System.out.println(quickpow(ma, k).tr());
		}
	}

}

class Matrix {
	final long mod=9973;
	long a[][] = new long[11][11];
	int n;
	public Matrix(){}
	
	public Matrix(int n) {
		// TODO Auto-generated constructor stub
		this.n = n;
		int i,j;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				a[i][j]=0;
			}
		}
	}
	public Matrix multiply(Matrix ma) {
		Matrix res=new Matrix(ma.n);
		int i,j,k;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++){
					res.a[i][j]+=(a[i][k]*ma.a[k][j])%mod;
				}
			}
		}
		return res;
	}
	
	public long tr(){
		long res=0;
		int i;
		for(i=1;i<=n;i++)
			res+=a[i][i];
		return res%mod;
	}
	
	public void init() {
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(i==j)
					a[i][j]=1;
				else 		
					a[i][j]=0;
			}
	}
}

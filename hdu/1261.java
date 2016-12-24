////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 15:59:42
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1261
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:13512KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger res,counter;
		Integer i,j,n,tmp;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			n=cin.nextInt();
			if(n==0)break;
			res=BigInteger.ONE;
			counter=BigInteger.ONE;
			for(i=1;i<=n;i++){
				tmp=cin.nextInt();
				for(j=1;j<=tmp;j++){
					res=res.multiply(counter).divide(new BigInteger(j.toString()));
					counter=counter.add(BigInteger.ONE);
				}
			}
			System.out.println(res);
		}
	}

}

//int n;
//ll res,tmp,counter;
//
//int main()
//{
//    int i,j;
//    while(cin>>n,n)
//    {
//        res=1;
//        counter=1;
//        for(i=1;i<=n;i++)
//        {
//            cin>>tmp;
//            for(j=1;j<=tmp;j++)
//            {
//                res=res*counter++/j;
//            }
//        }
//        cout<<res<<endl;
//    }
////    cout << "Hello world!" << endl;
//    return 0;
//}

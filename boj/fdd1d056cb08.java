import java.util.*;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		BigInteger a = BigInteger.ZERO;
		BigInteger b = BigInteger.ONE;
		BigInteger c;

		Scanner sc = new Scanner(System.in);
		int n = 0;
		n = sc.nextInt();

		for (int i = 0; i < n; ++i) {
			c = a;
			a = b;
			b = b.add(c);
		}

		System.out.println(a);
	}
}

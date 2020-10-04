import java.util.*;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		BigInteger[][] c = new BigInteger[101][101];

		for (int i = 0; i <= 100; ++i) for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0) c[i][j] = BigInteger.ONE;
			else c[i][j] = c[i-1][j-1].add(c[i-1][j]);
		}

		Scanner sc = new Scanner(System.in);
		int a, b;
		a = sc.nextInt();
		b = sc.nextInt();

		System.out.println(c[a][b]);
	}
}

import java.util.Scanner;

public class Main {
	static private int[] ary = new int[15];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int len = 0;
		
		ary[1] = 9;
		for(int i=2; i<=9; i++)
			ary[i] = ary[i - 1] + (9 * (int)Math.pow(10, i - 1) * i);
		
		for(len = 1; len <=9; len++)
		{
			if((int)Math.pow(10, len) > n)
				break;
		}
		
		System.out.println(ary[len - 1] + ((n - (int)Math.pow(10, len - 1) + 1) * len));
	}
}
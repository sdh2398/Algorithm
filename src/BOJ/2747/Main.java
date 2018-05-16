import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ary = new int[50];
		
		ary[0] = 0;
		ary[1] = 1;
		
		for(int i=2; i<=n; i++)
			ary[i] = ary[i-1] + ary[i-2];
		
		System.out.println(ary[n]);		
	}
}
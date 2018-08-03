import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		a = Integer.valueOf(new StringBuilder(String.valueOf(a)).reverse().toString());
		b = Integer.valueOf(new StringBuilder(String.valueOf(b)).reverse().toString());
		
		System.out.println(a > b ? a : b);
	}
}

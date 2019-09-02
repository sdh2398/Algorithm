import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for (int i = 0; i < t; i++) {
			int num = sc.nextInt();

			for (int j = 2; j <= num; j++) {
				int cnt = 0;
				while (num % j == 0) {
					cnt++;
					num /= j;
				}

				if(cnt != 0)
					System.out.println(j + " " + cnt);
			}
		}
	}
}

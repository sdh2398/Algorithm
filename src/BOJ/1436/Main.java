import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int res = 0;
		int num = 666;
		int cnt = 0;
		while(true)
		{
			String str = num + "";
			if(str.contains("666"))
			{
				cnt++;
				if(cnt == n)
				{
					res = num;
					break;
				}
			}
			num++;
		}
		
		System.out.println(res);
	}
}
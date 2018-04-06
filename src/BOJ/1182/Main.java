import java.util.Scanner;

public class Main {
	private static int n, s, res, sum;
	private static int[] ary = new int[101];
	
	private static void dfs(int num)
	{
		if(num >= n)
			return;
		
		if(sum + ary[num] == s)
			res++;
		
		dfs(num + 1);
		
		sum += ary[num];
		dfs(num + 1);
		sum -= ary[num];
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = sc.nextInt();
		for(int i=0; i<n; i++)
			ary[i] = sc.nextInt();
		
		dfs(0);
		System.out.println(res);
		
	}

}

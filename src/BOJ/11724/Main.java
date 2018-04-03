import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static ArrayList<Integer>[] al = new ArrayList[1002];
	private static int n, m, res = 0;
	private static boolean[] visit = new boolean[1002];
	
	private static void dfs(int cur)
	{
		visit[cur] = true;
		
		for(int i=0; i<al[cur].size(); i++)
		{
			int next = al[cur].get(i);
			if(visit[next] == false)
				dfs(next);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		m = sc.nextInt();
		
		for(int i=1; i<=n; i++)
			al[i] = new ArrayList<Integer>();
			
		for(int i=0; i<m; i++)
		{
			int a, b;
			a = sc.nextInt();
			b = sc.nextInt();
			
			al[a].add(b);
			al[b].add(a);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(visit[i] == false)
			{
				res++;
				dfs(i);
			}
		}
		
		System.out.println(res);
	}
}

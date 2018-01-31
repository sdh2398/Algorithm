import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	private static ArrayList<Integer>[] al = new ArrayList[1002];
	private static Queue<Integer> q = new LinkedList<Integer>();
	
	static boolean[] chk = new boolean[1002]; 
	
	private static void dfs(int s)
	{
		chk[s] = true;
		System.out.print(s + " ");
		
		for(int i=0; i<al[s].size(); i++)
		{
			int next = al[s].get(i);
			if(chk[next] == false)
				dfs(next);
		}
	}
	
	private static void bfs(int s)
	{
		q.add(s);
		System.out.print(s + " ");
		chk[s] = true;
		
		while(!q.isEmpty())
		{
			int cur = q.remove();
			
			for(int i=0; i<al[cur].size(); i++)
			{
				int next = al[cur].get(i);
				if(chk[next] == false)
				{
					chk[next] = true;
					System.out.print(next + " ");
					q.add(next);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m, v;
		n = sc.nextInt();
		m = sc.nextInt();
		v = sc.nextInt();
		
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
			Collections.sort(al[i]);
		
		dfs(v);
		System.out.println();
		Arrays.fill(chk, false);
		bfs(v);
		System.out.println();
	}
}

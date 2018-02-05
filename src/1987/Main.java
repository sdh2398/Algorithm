import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static int n, m, res = 0;
	private static char[][] ary = new char[22][22];
	private static boolean[] visit = new boolean[30];
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	
	private static void dfs(int x, int y, int num)
	{
		char cur = ary[x][y];
		visit[cur - 'A'] = true;
		
		if(res < num + 1)
			res = num + 1;
		
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				int next = ary[nx][ny];
				if(visit[next - 'A'] == false)
					dfs(nx, ny, num + 1);
			}
		}
		visit[cur - 'A'] = false;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		m = sc.nextInt();
		
		for(int i=0; i<n; i++)
		{
			String input = sc.next();
			for(int j=0; j<m; j++)
				ary[i][j] = input.charAt(j);
		}
			
		dfs(0, 0, 0);
		
		System.out.println(res);
		
	}
}
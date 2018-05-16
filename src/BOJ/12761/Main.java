import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int a, b, n, m, flag;
	static int[] ary = new int[100002];
	static int[] visit = new int[100002];
	
	public static void bfs(int start)
	{
		Queue<Integer> q = new LinkedList<Integer>();
		int[] move = new int[8];
		q.add(start);
		visit[start] = 1; 
		
		move[0] = -1;
		move[1] = 1;
		move[2] = -a;
		move[3] = a;
		move[4] = -b;
		move[5] = b;
		
		while(!q.isEmpty())
		{
			if(flag == 1)
				break;
			int cur = q.remove();
			int next = 0;
			int curCnt = visit[cur] + 1;
			move[6] = cur * a;
			move[7] = cur * b;
			
			for(int i=0; i<8; i++)
			{
				if(i < 6)
					next = cur + move[i];
				else
					next = move[i];
				
				if(next >= 0 && next <= 100000)
				{
					if(visit[next] == 0)
					{
						visit[next] = curCnt;
						q.add(next);
						if(next == m)
						{
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		n = sc.nextInt();
		m = sc.nextInt();
	
		ary[n] = 1;
		bfs(n);
        
		System.out.println(visit[m] - 1);
	}
}
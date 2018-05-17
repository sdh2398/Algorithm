import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class pair{
	int x, y;
	
	pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static String[] ary = new String[1002];
	static int[][] visit = new int[1002][1002];
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static int[][] xy = new int[10][2];
	static int h, w;
	static int startx, starty, targetx, targety, res;
	static int num;
	
	static void bfs()
	{
		int[][] visit = new int[h][w];
		
		Queue<pair> q = new LinkedList<pair>();
		q.add(new pair(startx, starty));
		visit[startx][starty] = 1;
		
		while(!q.isEmpty())
		{
			pair tmp = q.poll();
			int curx = tmp.x;
			int cury = tmp.y;
			
			for(int i=0; i<4; i++)
			{
				int nextx = curx + dx[i];
				int nexty = cury + dy[i];
				
				if(nextx >= 0 && nextx < h && nexty >= 0 && nexty < w)
				{
					if(visit[nextx][nexty] == 0)
					{
						if(ary[nextx].charAt(nexty) != 'X')
						{
							if(nextx == targetx && nexty == targety)
							{
								res += visit[curx][cury];
								q.clear();
								break;
							}
							
							visit[nextx][nexty] = visit[curx][cury] + 1;
							q.add(new pair(nextx, nexty));							
						}
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		int n = sc.nextInt();
		sc.nextLine();
		for(int i=0; i<h; i++)
		{
			ary[i] = sc.nextLine();
			for(int j=0; j<w; j++)
			{
				if(ary[i].charAt(j) == 'S')
				{
					xy[0][0] = i;
					xy[0][1] = j;
				}
				else if(ary[i].charAt(j) != '.' && ary[i].charAt(j) != 'X')
				{
					int cur = ary[i].charAt(j) - '0';
					if(num < cur)
						num = cur;
					xy[cur][0] = i;
					xy[cur][1] = j;
				}
			}
		}
		
		startx = xy[0][0];
		starty = xy[0][1];
		targetx = xy[1][0];
		targety = xy[1][1];
		bfs();
		for(int i=1; i<num; i++)
		{
			startx = xy[i][0];
			starty = xy[i][1];
			targetx = xy[i+1][0];
			targety = xy[i+1][1];
			bfs();
		}
		
		System.out.println(res);
	}
}
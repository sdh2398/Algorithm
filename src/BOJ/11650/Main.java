import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static class xynum implements Comparable<xynum> 
	{
		public int x;
		public int y;
		
		@Override
		public int compareTo(xynum other) {
			// TODO Auto-generated method stub
			int ret = x - other.x;
			if(ret == 0)
				return y - other.y;
			else
				return ret;
		}
	}
	public static xynum[] xy = new xynum[100002];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		for(int i=0; i<n; i++)
		{
			xy[i] = new xynum();
			xy[i].x = sc.nextInt();
			xy[i].y = sc.nextInt();
		}
		Arrays.sort(xy, 0, n);
		for(int i=0; i<n; i++)
			System.out.println(xy[i].x + " " + xy[i].y);
	}
}
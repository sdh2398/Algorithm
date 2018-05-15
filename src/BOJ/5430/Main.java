import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		int n = 0;
		int flag;
		int res;
		String p;
		String x;
		for(int tc=0; tc<t; tc++)
		{
			Deque dq = new ArrayDeque();
			flag = 0;
			res = 0;
			p = sc.nextLine();
			n = sc.nextInt();
			sc.nextLine();
			x = sc.nextLine();
			x = x.substring(1, x.length() - 1);
			String[] arys = x.split(",");
			if(x.length() != 0)
				for(String ary : arys)
					dq.addLast(ary);
			
			int len = p.length();
			for(int i=0; i<len; i++)
			{
				if(p.charAt(i) == 'R')
				{
					if(flag == 0)
						flag = 1;
					else
						flag = 0;
				}
				else
				{
					if(dq.isEmpty())
					{
						res = 1;
						break;
					}
					if(flag == 0)
						dq.pollFirst();
					else
						dq.pollLast();
				}
			}
			if(res == 1)
				System.out.println("error");
			else
			{
				System.out.print("[");
				len = dq.size();
				for(int i=0; i<len; i++)
				{
					if(flag == 0)
						System.out.print(dq.poll());
					else
						System.out.print(dq.pollLast());
					if(i != len - 1)
						System.out.print(",");
				}
				System.out.println("]");
			}
		}
	}
}
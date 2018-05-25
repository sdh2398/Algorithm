import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;

class pair implements Comparable<pair>{
	public int first;
	public int second;
	
	public pair(int first, int second)
	{
		this.first = first;
		this.second = second;
	}

	@Override
	public int compareTo(pair target) {
		// TODO Auto-generated method stub
		if(this.first < target.first)
			return -1;
		else if(this.first > target.first)
			return 1;
			
		return 0;
	}
}

public class Main{
	public static ArrayList<pair>[] al = new ArrayList[20002];
	public static int[] distance = new int[20002];
	public static boolean[] visit = new boolean[20002];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] str = br.readLine().split(" ");
		int v = Integer.parseInt(str[0]);
		int e = Integer.parseInt(str[1]);
		int k = Integer.parseInt(br.readLine());
		
		for(int i=0; i<=v; i++)
		{
			al[i] = new ArrayList<pair>();
			distance[i] = Integer.MAX_VALUE;
		}
		
		for(int i=0; i<e; i++)
		{
			str = br.readLine().split(" ");
			int a = Integer.parseInt(str[0]);
			int b = Integer.parseInt(str[1]);
			int c = Integer.parseInt(str[2]);
			
			al[a].add(new pair(b, c));
		}
		
		PriorityQueue<pair> pq = new PriorityQueue<pair>();
		
		pq.add(new pair(0, k));
		distance[k] = 0;
		
		while(!pq.isEmpty())
		{
			int curDis = pq.peek().first;
			int curV = pq.poll().second;
			if(distance[curV] < curDis)
				continue;
			
			for(int i=0; i<al[curV].size(); i++)
			{
				int nextDis = distance[curV] + al[curV].get(i).second;
				int nextV = al[curV].get(i).first;
				
				if(distance[nextV] > nextDis)
				{
					distance[nextV] = nextDis;
					pq.add(new pair(nextDis, nextV));
				}
			}
		}
		for(int i=1; i<=v; i++)
		{
			if(distance[i] == Integer.MAX_VALUE)
				bw.write("INF \n");
			else
				bw.write(distance[i] + "\n");
			//bw.flush();
		}
		bw.flush();
	}
}
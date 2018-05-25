import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

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
	public static int[] dp = new int[102];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int res = 0;
		String[] str;
		pair[] p = new pair[n];
		
		for(int i=0; i<n; i++)
		{
			str = br.readLine().split(" ");
			p[i] = new pair(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
		}
		
		Arrays.sort(p);
		dp[0] = 1;
		for(int i=1; i<n; i++)
		{
			dp[i] = 1;
			for(int j=0; j<i; j++)
			{
				if(p[i].second > p[j].second)
				{
					if(dp[i] < dp[j] + 1)
					{
						dp[i] = dp[j] + 1;
						res = Math.max(res, dp[i]);
					}
				}
			}
		}
		bw.write(n - res + "");
		bw.flush();
	}
}
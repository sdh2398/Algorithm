import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static int[] dp = new int[50];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String str = br.readLine();
		int len = str.length();
		dp[0] = 1;
		for(int i=1; i<=len; i++)
		{
			dp[i] = 1;
			if(i != 1)
			{
				int num = (str.charAt(i - 2) - '0') * 10;
				num += str.charAt(i - 1) - '0';
				
				if(str.charAt(i-1) == '0')
				{
					if(i == 1 || str.charAt(i-2) == '0' || num >= 40)
					{
						dp[len] = 0;
						break;
					}
					else
						dp[i] = dp[i-2];
				}
				else
				{
					if(str.charAt(i-2) == '0')
						dp[i] = dp[i-1];
					else
					{
						if(num <= 34)
							dp[i] = dp[i-1] + dp[i-2];
						else
							dp[i] = dp[i-1];					
					}					
				}
			}
		}
		
		System.out.println(dp[len]);
	}
}
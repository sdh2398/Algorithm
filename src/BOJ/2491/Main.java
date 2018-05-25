import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static int[] ary = new int[100002];
	public static int[] dpMax = new int[100002];
	public static int[] dpMin = new int[100002];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int res = 1;
		String[] str;
		str = br.readLine().split(" ");
		
		for(int i=0; i<n; i++)
		{
			ary[i] = Integer.parseInt(str[i]);
			dpMax[i] = dpMin[i] = 1;
			if(i != 0)
			{
				if(ary[i - 1] <= ary[i])
					dpMax[i] = dpMax[i - 1] + 1;
				if(ary[i - 1] >= ary[i])
					dpMin[i] = dpMin[i - 1] + 1;
				res = Math.max(res, dpMax[i]);
				res = Math.max(res, dpMin[i]);				
			}
		}
		bw.write(res + "");
		bw.flush();
	}
}
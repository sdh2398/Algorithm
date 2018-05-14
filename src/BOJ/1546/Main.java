import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static double[] ary = new double[1002];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double sum = 0;
		for(int i=0; i<n; i++)
			ary[i] = sc.nextDouble();
        
		Arrays.sort(ary, 0, n);
		
		for(int i=0; i<n; i++)
		{
			ary[i] = ary[i] / ary[n - 1] * 100;
			sum += ary[i];
		}
		System.out.println(Double.parseDouble(String.format("%.2f", sum / n)));
	}
}
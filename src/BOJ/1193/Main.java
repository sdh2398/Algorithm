import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int a = 1;
		int b = 1;
		int flag = 0;
		for(int i=0; i<x - 1; i++)
		{
			if(i == 0)
				b++;
			else
			{
				if(a == 1 && flag == 0)
				{
					flag = 1;
					if(i != 1)
					{
						b++;
						continue;
					}
				}
				else if(b == 1 && flag == 1)
				{
					flag = 0;
					a++;
					continue;
				}
				
				if(flag == 1)
				{
					a++;
					b--;					
				}
				else
				{
					a--;
					b++;
				}
			}
		}
		System.out.println(a + "/" + b);
	}
}
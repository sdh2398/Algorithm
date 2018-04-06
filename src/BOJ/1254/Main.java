import java.util.Scanner;

public class Main {
	static private String ary;
	static private String rary;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int len = 0;
		int res = 0;
		ary = sc.next();
		len = ary.length();
		rary = new StringBuilder(ary).reverse().toString();
		
		for(int i=1; i<=len; i++)
		{
			if(ary.substring(len-i, len).equals(rary.substring(0, i)) == true)
				res = len - i;
		}
		System.out.println(res + len);
	}
}
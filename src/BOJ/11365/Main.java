import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String msg;
		
		while(true)
		{
			StringBuffer sb = new StringBuffer();
			msg = sc.nextLine();
			if(msg.equals("END"))
					break;
			sb.append(msg);
			System.out.println(sb.reverse());
		}
	}
}
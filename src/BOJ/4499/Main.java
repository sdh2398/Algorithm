import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str;
		int len = 0;
		int flag;
		while(true)
		{
			flag = 0;
			Stack s = new Stack();
			str = sc.nextLine();
			if(str.equals("."))
					break;
			len = str.length();
			
			for(int i=0; i<len; i++)
			{
				if(str.charAt(i) == '(' || str.charAt(i) == '[')
					s.push(str.charAt(i));
				
				else if(str.charAt(i) == ')')
				{
					if(s.empty())
					{
						flag = 1;
						break;
					}
					if(s.peek().equals('('))
						s.pop();
					else
						break;
				}
				else if(str.charAt(i) == ']')
				{
					if(s.empty())
					{
						flag = 1;
						break;
					}
					if(s.peek().equals('['))
						s.pop();
					else
						break;
				}
			}
			if(s.empty() && flag == 0)
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}
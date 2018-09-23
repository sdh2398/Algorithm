import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		String str;
		Stack<Character> st;

		for (int tc = 0; tc < t; tc++) {
			str = sc.next();
			st = new Stack<Character>();
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if (c == '(') {
					st.push(c);
				} else {
					if (!st.empty() && st.peek() == '(') {
						st.pop();
					} else {
						st.push(c);
					}
				}
			}
			if (st.size() == 0)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}

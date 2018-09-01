import java.util.Scanner;
import java.util.Stack;

class Main {
	public static void main(String[] args) throws Exception {
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int num;
		String input;
		Stack<Integer> st = new Stack<Integer>();

		for (int i = 0; i < n; i++) {
			input = scan.next();
			if (input.equals("push")) {
				num = scan.nextInt();
				st.push(num);
			} else if(input.equals("pop")) {
				if(st.isEmpty())
					System.out.println("-1");
				else
					System.out.println(st.pop());
			} else if(input.equals("size")) {
				System.out.println(st.size());
			} else if(input.equals("empty")) {
				if(st.isEmpty())
					System.out.println("1");
				else
					System.out.println("0");
			} else if(input.equals("top")) {
				if(st.isEmpty())
					System.out.println("-1");
				else
					System.out.println(st.peek());
			}
		}
	}
}
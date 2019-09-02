import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	private static ArrayList<Integer>[] graph;
	private static boolean[] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int v = sc.nextInt();

		visit = new boolean[1002];

		graph = new ArrayList[1002];

		for (int i = 1; i <= n; i++)
			graph[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();

			graph[s].add(e);
			graph[e].add(s);
		}

		for (int i = 1; i <= n; i++)
			Collections.sort(graph[i]);

		dfs(v);
		System.out.println();

		visit = new boolean[1002];

		bfs(v);

	}

	private static void dfs(int start) {
		System.out.print(start + " ");
		visit[start] = true;

		for (int n : graph[start]) {
			if (!visit[n])
				dfs(n);
		}
	}

	private static void bfs(int start) {
		Queue<Integer> q = new LinkedList<Integer>();

		q.add(start);

		while (!q.isEmpty()) {
			int cur = q.remove();
			System.out.print(cur + " ");
			visit[cur] = true;

//			graph[cur].stream().filter(next -> !visit[next]).forEach(next -> {
//				visit[next] = true;
//				q.add(next);
//			});

			for (int n : graph[cur]) {
				if (!visit[n]) {
					visit[n] = true;
					q.add(n);
				}
			}
		}
	}

}

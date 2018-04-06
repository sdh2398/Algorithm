#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, res;
int visit[1002];
vector<int> vec[1002];

void bfs(int start)
{
	res++;
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i];
			
			if (visit[next] == 0)
			{
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d ", &a, &b);

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
			bfs(i);
	}

	printf("%d \n", res);

	return 0;
}
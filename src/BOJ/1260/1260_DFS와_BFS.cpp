#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[1002];
bool chk[1002];

void dfs(int s)
{
	chk[s] = true;
	printf("%d ", s);
	for (int i = 0; i < vec[s].size(); i++)
	{
		int next = vec[s][i];
		if (chk[next] == false)
			dfs(next);
	}
}

void bfs(int s)
{
	queue<int> q;
	chk[s] = true;
	q.push(s);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		printf("%d ", cur);

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i];
			if (chk[next] == false)
			{
				chk[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n, m, v;
	scanf("%d %d %d ", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d ", &a, &b);

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	dfs(v);
	puts("");
	memset(chk, false, sizeof(chk));
	bfs(v);
	puts("");

	return 0;
}
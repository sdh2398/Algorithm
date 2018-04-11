#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec[10002];
vector<int> res;
int cnt[10002];
int visit[10002];

// bfs를 여러번 하는 경우에는 visit 방문 배열에 root값을 넣어서 방문했는지 확인하도록 한다.
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = start;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt[cur]++;

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i];
			if (visit[next] != start)
			{
				q.push(next);
				visit[next] = start;
			}
		}
	}
}

int main(void)
{
	int n, m;
	int maxcnt = 0;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d ", &a, &b);
		vec[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		bfs(i);

	for (int i = 1; i <= n; i++)
		maxcnt = max(cnt[i], maxcnt);

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == maxcnt)
			res.push_back(i);
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	puts("");

	return 0;
}
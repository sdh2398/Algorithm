#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, res, wall;
int ary[10][10];
int visit[10][10];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> vec;

void bfs()
{
	int tmpres = 0;
	queue<pair<int, int>> q;

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", ary[i][j]);
		puts("");
	}
	puts("");*/
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ary[i][j] == 2)
			{
				visit[i][j] = 1;
				q.push({ i, j });
			}
		}
	}*/

	for (int i = 0; i < vec.size(); i++)
	{
		visit[vec[i].first][vec[i].second] = 1;
		q.push({ vec[i].first, vec[i].second });
		tmpres++;
	}

	//printf("%d \n", q.size());

	while (!q.empty())
	{
		int curx, cury;
		curx = q.front().first;
		cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextx, nexty;
			nextx = curx + mx[i];
			nexty = cury + my[i];

			if (nextx >= 0 && nexty >= 0 && nextx < n && nexty < m)
			{
				if (visit[nextx][nexty] == 0 && ary[nextx][nexty] == 0)
				{
					visit[nextx][nexty] = 1;
					tmpres++;
					q.push({ nextx, nexty });
				}
			}
		}
	}


	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (visit[i][j] == 0 && ary[i][j] == 0)
				tmpres++;
	}*/
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//		printf("%d ", visit[i][j]);
//		puts("");
	//}
	tmpres = (n * m) - tmpres - wall - 3;
	//printf("%d \n", tmpres);
	res = max(res, tmpres);
}

//int tt;
void bf(int cnt)
{
		//tt++;
	if (cnt == 3)
	{
		memset(visit, 0, sizeof(visit));
		bfs();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ary[i][j] == 0)
			{
				ary[i][j] = 1;
				bf(cnt + 1);
				ary[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d ", &ary[i][j]);
			if (ary[i][j] == 2)
				vec.push_back({ i, j });
			if (ary[i][j] == 1)
				wall++;
		}
	}

	bf(0);
	//bfs();
	//printf("%d \n", tt);
	printf("%d \n", res);

	return 0;
}
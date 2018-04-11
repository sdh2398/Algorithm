#include <iostream>
#include <queue>
using namespace std;

int n, m, res;
int ary[1002][1002];
int visit[1002][1002];

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + mx[i];
			int ny = cury + my[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (ary[nx][ny] == 0 && visit[nx][ny] == 0)
				{
					q.push({ nx, ny });
					res = visit[nx][ny] = visit[curx][cury] + 1;
				}
			}
		}
	}
}

int main(void)
{
	int flag = 0;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d ", &ary[i][j]);
			if (ary[i][j] == 1)
			{
				visit[i][j] = 1;
				q.push({ i, j });
			}
			if (flag == 0 && ary[i][j] == 0)
				flag = 1;
		}
	}
	
	if (flag == 0)
	{
		printf("0\n");
		return 0;
	}

	bfs();

	res--;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ary[i][j] == 0 && visit[i][j] == 0)
				res = -1;
		}
	}

	printf("%d \n", res);

	return 0;
}
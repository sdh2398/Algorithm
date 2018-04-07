#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, res;
int ary[52][52];
int visit[52][52];

int mx[4] = { 0, 0, -1, 1 };
int my[4] = { -1, 1, 0, 0 };

int north[5] = { 0, 3, 1, 2, 3 };
int northdir[5] = { 3, 2, 1, 0, 0 };
int east[5] = { 2, 0, 3, 1, 0 };
int eastdir[5] = { 0, 3, 2, 1, 1 };
int south[5] = { 1, 2, 0, 3, 2 };
int southdir[5] = { 1, 0, 3, 2, 2 };
int west[5] = { 3, 1, 2, 0, 1 };
int westdir[5] = { 2, 1, 0, 3, 3 };

void bfs(int x, int y, int dir)
{
	queue<pair<int, int>> q;
	queue<int> qdir;
	q.push({ x, y });
	qdir.push(dir);
	visit[x][y] = 1;

	while (!q.empty())
	{
		int cx, cy, cd;
		cx = q.front().first;
		cy = q.front().second;
		cd = qdir.front();
		//printf("%d %d %d \n", cx, cy, cd);
		q.pop();
		qdir.pop();
		res++;

		for (int i = 0; i < 5; i++)
		{
			int nx, ny, nd;
			if (cd == 0)
			{
				nx = cx + mx[north[i]];
				ny = cy + my[north[i]];
				nd = northdir[i];
			}
			else if (cd == 1)
			{
				nx = cx + mx[east[i]];
				ny = cy + my[east[i]];
				nd = eastdir[i];
			}
			else if (cd == 2)
			{
				nx = cx + mx[south[i]];
				ny = cy + my[south[i]];
				nd = southdir[i];
			}
			else if (cd == 3)
			{
				nx = cx + mx[west[i]];
				ny = cy + my[west[i]];
				nd = westdir[i];
			}

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				//printf("nx %d ny %d \n", nx, ny);
				if ((visit[nx][ny] == 0 && ary[nx][ny] == 0) || (i == 4 && ary[nx][ny] == 0))
				{
					if (i == 4)
						res--;
					visit[nx][ny] = visit[cx][cy] + 1;
					q.push({ nx, ny });
					qdir.push(nd);
					break;
				}
			}
		}
	}
}

int main(void)
{
	int r, c, d;
	scanf("%d %d %d %d %d ", &n, &m, &r, &c, &d);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d ", &ary[i][j]);
	}

	bfs(r, c, d);

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", visit[i][j]);
		puts("");
	}*/

	printf("%d \n", res);

	return 0;
}
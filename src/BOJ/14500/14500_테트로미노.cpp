#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res;
int ary[502][502];
int visit[502][502];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int num, int cnt)
{
	if (cnt == 3)
	{
		res = max(res, num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visit[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				dfs(nx, ny, num + ary[nx][ny], cnt + 1);
				visit[nx][ny] = 0;
			}
		}
	}
}

int chk(int x1, int x2, int x3, int y1, int y2, int y3)
{
	if (x1 >= 0 && x2 >= 0 && x3 >= 0 && y1 >= 0 && y2 >= 0 && y3 >= 0)
	{
		if (x1 < n && x2 < n && x3 < n && y1 < m && y2 < m && y3 < m)
			return 1;
	}
	return 0;
}

void f(int x, int y)
{
	int x1, x2, x3;
	int y1, y2, y3;

	x1 = x; 
	y1 = y - 1;
	x2 = x; 
	y2 = y + 1;
	x3 = x - 1;
	y3 = y;
	if (chk(x1, x2, x3, y1, y2, y3))
		res = max(res, ary[x][y] + ary[x1][y1] + ary[x2][y2] + ary[x3][y3]);
	x3 = x + 1;
	if (chk(x1, x2, x3, y1, y2, y3))
		res = max(res, ary[x][y] + ary[x1][y1] + ary[x2][y2] + ary[x3][y3]);

	x1 = x - 1;
	y1 = y;
	x2 = x + 1;
	y2 = y;
	x3 = x;
	y3 = y - 1;
	if (chk(x1, x2, x3, y1, y2, y3))
		res = max(res, ary[x][y] + ary[x1][y1] + ary[x2][y2] + ary[x3][y3]);
	y3 = y + 1;
	if (chk(x1, x2, x3, y1, y2, y3))
		res = max(res, ary[x][y] + ary[x1][y1] + ary[x2][y2] + ary[x3][y3]);
}

int main(void)
{
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d ", &ary[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f(i, j);
			visit[i][j] = 1;
			dfs(i, j, ary[i][j], 0);
			visit[i][j] = 0;
		}
	}

	printf("%d \n", res);

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int n, m, h, res;
int ary[102][102][102];
int visit[102][102][102];
int mh[6] = { -1, 1, 0, 0, 0, 0 };
int mx[6] = { 0, 0, -1, 1, 0, 0 };
int my[6] = { 0, 0, 0, 0, -1, 1 };

void bfs()
{
	queue <pair<pair<int, int>, int>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (ary[i][j][k] == 1)
					q.push({ {i, j}, k });
			}
		}
	}

	while (!q.empty())
	{
		int curh = q.front().first.first;
		int curn = q.front().first.second;
		int curm = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nexth = curh + mh[i];
			int nextn = curn + mx[i];
			int nextm = curm + my[i];

			if (nexth >= 0 && nextn >= 0 && nextm >= 0 && nexth < h && nextn < n && nextm < m)
			{
				if (ary[nexth][nextn][nextm] == 0)
				{
					q.push({ {nexth, nextn}, nextm });
					res = ary[nexth][nextn][nextm] = ary[curh][curn][curm] + 1;
				}
			}
		}

	}
}

int main(void)
{
	scanf("%d %d %d ", &m, &n, &h);

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
				scanf("%d ", &ary[i][j][k]);
		}
	}

	bfs();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (ary[i][j][k] == 0)
					res = -1;
			}
		}
	}

	if (res >= 1)
		printf("%d \n", res - 1);
	else 
		printf("%d \n", res);
	
	return 0;
}
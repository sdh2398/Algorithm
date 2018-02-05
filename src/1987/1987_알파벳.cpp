#include <iostream>
#include <algorithm>
using namespace std;

int r, c, res;
char ary[22][22];
int visit[30];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int num)
{
	char cur = ary[x][y];
	visit[cur - 'A'] = 1;

	num++;
	res = max(res, num);

	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (nextx >= 0 && nexty >= 0 && nextx < r && nexty < c)
		{
			if (visit[ary[nextx][nexty] - 'A'] == 0)
				dfs(nextx, nexty, num);
		}
	}
	visit[cur - 'A'] = 0;
}

int main(void)
{
	scanf("%d %d ", &r, &c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			scanf("%c ", &ary[i][j]);
	}

	dfs(0, 0, 0);

	printf("%d \n", res);

	return 0;
}
#include <iostream>
using namespace std;

int n, l, res;
int ary[102][102];
int visit[102];

void dfs(int num, int cur, int flag)
{
	if (num == n - 1)
	{
		res++;
		return;
	}

	if (flag == 0)
	{
		if (ary[cur][num] == ary[cur][num + 1])
			dfs(num + 1, cur, flag);
		if (num + l >= n)
			return;

		int chk = 0;
		for (int i = num; i < num + l; i++)
		{
			if (visit[i] == 1)
				chk = 1;
		}
		for (int i = num; i < num + l - 1; i++)
		{
			if (ary[cur][i] != ary[cur][i + 1])
				chk = 1;
		}
		if (ary[cur][num] == ary[cur][num + l] - 1 && chk == 0)
		{
			for (int i = num; i < num + l; i++)
				visit[i] = 1;
			dfs(num + l, cur, flag);
			for (int i = num; i < num + l; i++)
				visit[i] = 0;
		}

		chk = 0;
		for (int i = num + 1; i <= num + l; i++)
		{
			if (visit[i] == 1)
				chk = 1;
		}
		for (int i = num + 1; i < num + l; i++)
		{
			if (ary[cur][i] != ary[cur][i + 1])
				chk = 1;
		}
		if (ary[cur][num] == ary[cur][num + 1] + 1 && chk == 0)
		{
			for (int i = num + 1; i <= num + l; i++)
				visit[i] = 1;
			dfs(num + l, cur, flag);
			for (int i = num + 1; i <= num + l; i++)
				visit[i] = 0;
		}
	}
	else if (flag == 1)
	{
		if (ary[num][cur] == ary[num + 1][cur])
			dfs(num + 1, cur, flag);
		if (num + l >= n)
			return;

		int chk = 0;
		for (int i = num; i < num + l; i++)
		{
			if (visit[i] == 1)
				chk = 1;
		}
		for (int i = num; i < num + l - 1; i++)
		{
			if (ary[i][cur] != ary[i + 1][cur])
				chk = 1;
		}
		if (ary[num][cur] == ary[num + l][cur] - 1 && chk == 0)
		{
			for (int i = num; i < num + l; i++)
				visit[i] = 1;
			dfs(num + l, cur, flag);
			for (int i = num; i < num + l; i++)
				visit[i] = 0;
		}

		chk = 0;
		for (int i = num + 1; i <= num + l; i++)
		{
			if (visit[i] == 1)
				chk = 1;
		}
		for (int i = num + 1; i < num + l; i++)
		{
			if (ary[i][cur] != ary[i + 1][cur] || visit[i] == 1)
				chk = 1;
		}
		if (ary[num][cur] == ary[num + 1][cur] + 1 && chk == 0)
		{
			for (int i = num + 1; i <= num + l; i++)
				visit[i] = 1;
			dfs(num + l, cur, flag);
			for (int i = num + 1; i <= num + l; i++)
				visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d ", &n, &l);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d ", &ary[i][j]);
	}

	for (int i = 0; i < n; i++)
		dfs(0, i, 0);
	for (int i = 0; i < n; i++)
		dfs(0, i, 1);

	printf("%d \n", res);

	return 0;
}
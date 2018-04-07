#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res = 987654321;
int ary[22][22];
int visit[22];

void calc()
{
	int sum1 = 0, sum2 = 0;
	vector<int> vec1;
	vector<int> vec2;

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 1)
			vec1.push_back(i);
		else
			vec2.push_back(i);
	}

	for (int i = 0; i < vec1.size(); i++)
	{
		for (int j = i + 1; j < vec1.size(); j++)
		{
			sum1 += ary[vec1[i]][vec1[j]];
			sum1 += ary[vec1[j]][vec1[i]];
		}
	}

	for (int i = 0; i < vec2.size(); i++)
	{
		for (int j = i + 1; j < vec2.size(); j++)
		{
			sum2 += ary[vec2[i]][vec2[j]];
			sum2 += ary[vec2[j]][vec2[i]];
		}
	}

	int tmpres = sum1 - sum2;
	if (tmpres >= 0)
		res = min(res, tmpres);
	else
		res = min(res, -tmpres);
}

void dfs(int num, int cnt)
{
	if (cnt == n / 2)
	{
		calc();
		return;
	}

	for (int i = num; i < n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d ", &ary[i][j]);
	}

	dfs(0, 0);
	printf("%d \n", res);

	return 0;
}
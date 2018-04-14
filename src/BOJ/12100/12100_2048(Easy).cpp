#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, res;
int ary[22][22];

void fun(int flag)
{
	// 위
	if (flag == 0)
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> vec;
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (ary[j][i] != 0)
				{
					if (j == 0)
						vec.push_back(ary[j][i]);
					else
					{
						if (vec.size() != 0 && vec[vec.size() - 1] == ary[j][i] && flag == 0)
						{
							vec[vec.size() - 1] = ary[j][i] * 2;
							flag = 1;
						}
						else
						{
							vec.push_back(ary[j][i]);
							flag = 0;
						}
					}
				}
				ary[j][i] = 0;
			}

			for (int j = 0; j < vec.size(); j++)
			{
				ary[j][i] = vec[j];
				res = max(res, ary[j][i]);
			}
		}
	}
	// 오른쪽
	else if (flag == 1)
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> vec;
			int flag = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				if (ary[i][j] != 0)
				{
					if (j == n - 1)
						vec.push_back(ary[i][j]);
					else
					{
						if (vec.size() != 0 && vec[vec.size() - 1] == ary[i][j] && flag == 0)
						{
							vec[vec.size() - 1] = ary[i][j] * 2;
							flag = 1;
						}
						else
						{
							vec.push_back(ary[i][j]);
							flag = 0;
						}
					}
					ary[i][j] = 0;
				}
			}

			for (int j = 0; j < vec.size(); j++)
			{
				ary[i][n - j - 1] = vec[j];
				res = max(res, ary[i][n - j - 1]);
			}
		}
	}
	// 아래
	else if (flag == 2)
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> vec;
			int flag = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				if (ary[j][i] != 0)
				{
					if (j == n - 1)
						vec.push_back(ary[j][i]);
					else
					{
						if (vec.size() != 0 && vec[vec.size() - 1] == ary[j][i] && flag == 0)
						{
							vec[vec.size() - 1] = ary[j][i] * 2;
							flag = 1;
						}
						else
						{
							vec.push_back(ary[j][i]);
							flag = 0;
						}
					}
					ary[j][i] = 0;
				}
			}

			for (int j = 0; j < vec.size(); j++)
			{
				ary[n - j - 1][i] = vec[j];
				res = max(res, ary[n - j - 1][i]);
			}
		}
	}
	// 왼쪽
	if (flag == 3)
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> vec;
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (ary[i][j] != 0)
				{
					if (j == 0)
						vec.push_back(ary[i][j]);
					else
					{
						if (vec.size() != 0 && vec[vec.size() - 1] == ary[i][j] && flag == 0)
						{
							vec[vec.size() - 1] = ary[i][j] * 2;
							flag = 1;
						}
						else
						{
							vec.push_back(ary[i][j]);
							flag = 0;
						}
					}
					ary[i][j] = 0;
				}
			}

			for (int j = 0; j < vec.size(); j++)
			{
				ary[i][j] = vec[j];
				res = max(res, ary[i][j]);
			}
		}
	}
}

void dfs(int num, int dir)
{
	if (num == 6)
		return;

	int tmpary[22][22];
	for (int i = 0; i < n; i++)
		memcpy(tmpary[i], ary[i], sizeof(int) * n);

	fun(dir);

	for (int i = 0; i < 4; i++)
	{
		if (i == dir)
			continue;
		dfs(num + 1, i);
	}

	for (int i = 0; i < n; i++)
		memcpy(ary[i], tmpary[i], sizeof(int) * n);
}

int main(void)
{
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d ", &ary[i][j]);
	}

	for (int i = 0; i < 4; i++)
		dfs(1, i);

	printf("%d \n", res);

	return 0;
}
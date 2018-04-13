#include <iostream>
#include <cstring>
using namespace std;

int ary[4][8];
int visit[4];

void shift(int num, int dir)
{
	int tmp;
	if (dir == 1)
	{
		tmp = ary[num][7];
		memmove(ary[num] + 1, ary[num], 4 * 7);
		ary[num][0] = tmp;
	}
	else if (dir == -1)
	{
		tmp = ary[num][0];
		memmove(ary[num], ary[num] + 1, 4 * 7);
		ary[num][7] = tmp;
	}
}

void magnet(int num, int dir)
{
	visit[num] = 1;

	if (num == 0 || num == 1 || num == 2)
	{
		if (ary[num][2] != ary[num + 1][6])
		{
			if (visit[num + 1] == 0)
				magnet(num + 1, -dir);
		}
	}

	if (num == 1 || num == 2 || num == 3)
	{
		if (ary[num][6] != ary[num - 1][2])
		{
			if (visit[num - 1] == 0)
				magnet(num - 1, -dir);
		}
	}

	shift(num, dir);
	visit[num] = 0;
}


int main(void)
{
	int k, res = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
			scanf("%1d ", &ary[i][j]);
	}

	scanf("%d ", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d %d ", &a, &b);
		magnet(a - 1, b);
	}

	int add = 1;
	for (int i = 0; i < 4; i++)
	{
		if (ary[i][0] == 1)
			res += add;
		add *= 2;
	}

	printf("%d \n", res);

	return 0;
}
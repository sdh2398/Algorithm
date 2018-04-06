#include <iostream>
using namespace std;

int ary[22][22];
int dice[7];

void nextdir(int dir)
{
	if (dir == 1)
	{
		int tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (dir == 2)
	{
		int tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = tmp;
	}
	else if (dir == 3)
	{
		int tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = tmp;
	}
	else if (dir == 4)
	{
		int tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
	}
}

int main(void)
{
	int n, m, x, y, k;
	scanf("%d %d %d %d %d ", &n, &m, &x, &y, &k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d ", &ary[i][j]);
	}

	for (int i = 0; i < k; i++)
	{
		int dir, tmpx, tmpy;
		scanf("%d ", &dir);
		tmpx = x;
		tmpy = y;
		if (dir == 1)
			y += 1;
		else if (dir == 2)
			y -= 1;
		else if (dir == 3)
			x -= 1;
		else if (dir == 4)
			x += 1;

		if (x >= 0 && y >= 0 && x < n && y < m)
		{
			nextdir(dir);
			if (ary[x][y] == 0)
				ary[x][y] = dice[5];
			else
			{
				dice[5] = ary[x][y];
				ary[x][y] = 0;
			}
			printf("%d \n", dice[2]);
		}
		else
		{
			x = tmpx;
			y = tmpy;
		}
	}

	return 0;
}
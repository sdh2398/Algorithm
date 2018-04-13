#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, res;
char ary[12][12];
int visit[12][12][12][12];

int incre(int curfix, int curm, int flag, int same, int nm, int xy)
{
	if (xy == 0)
	{
		for (int i = curm + 1; i < nm; i++)
		{
			if (ary[curfix][i] == 'O')
				return 0;
			else
			{
				if (flag == 0)
				{
					if (ary[curfix][i] == '#')
						return i - 1;
				}
				else
				{
					if (ary[curfix][i] == '#' || i == same)
						return i - 1;
				}
			}
		}
	}
	else
	{
		for (int i = curm + 1; i < nm; i++)
		{
			if (ary[i][curfix] == 'O')
				return 0;
			else
			{
				if (flag == 0)
				{
					if (ary[i][curfix] == '#')
						return i - 1;
				}
				else
				{
					if (ary[i][curfix] == '#' || i == same)
						return i - 1;
				}
			}
		}
	}
}

int decre(int curfix, int curm, int flag, int same, int xy)
{
	if (xy == 0)
	{
		for (int i = curm - 1; i >= 0; i--)
		{
			if (ary[curfix][i] == 'O')
				return 0;
			else
			{
				if (flag == 0)
				{
					if (ary[curfix][i] == '#')
						return i + 1;
				}
				else
				{
					if (ary[curfix][i] == '#' || i == same)
						return i + 1;
				}
			}
		}
	}
	else
	{
		for (int i = curm - 1; i >= 0; i--)
		{
			if (ary[i][curfix] == 'O')
				return 0;
			else
			{
				if (flag == 0)
				{
					if (ary[i][curfix] == '#')
						return i + 1;
				}
				else
				{
					if (ary[i][curfix] == '#' || i == same)
						return i + 1;
				}
			}
		}
	}
}

void bfs(int rx, int ry, int bx, int by)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { rx,ry },{ bx, by } });
	visit[rx][ry][bx][by] = 1;
	while (!q.empty())
	{
		if (res != 0)
			break;

		int currx = q.front().first.first;
		int curry = q.front().first.second;
		int curbx = q.front().second.first;
		int curby = q.front().second.second;
		q.pop();
		int nextrx = 0, nextry = 0, nextbx = 0, nextby = 0;
		int ret, bflag = 0;

		if (visit[currx][curry][curbx][curby] > 10)
			break;

		// 위
		if (curry == curby)
		{
			if (currx < curbx)
			{
				ret = decre(curry, currx, 0, 0, 1);
				if (ret == 0)
					res = visit[currx][curry][curbx][curby];
				else
				{
					nextrx = ret;
					nextry = curry;
				}

				ret = decre(curby, curbx, 1, nextrx, 1);
				if (ret == 0)
				{
					if (res != 0)
						res = 0;
					bflag = 1;
				}
				else
				{
					nextbx = ret;
					nextby = curby;
				}
			}
			else
			{
				ret = decre(curby, curbx, 0, 0, 1);
				if (ret == 0)
					bflag = 1;
				else
				{
					nextbx = ret;
					nextby = curby;
				}

				ret = decre(curry, currx, 1, nextbx, 1);
				if (ret == 0)
				{
					if (bflag == 0)
						res = visit[currx][curry][curbx][curby];
				}
				else
				{
					nextrx = ret;
					nextry = curry;
				}
			}
		}
		else
		{
			ret = decre(curry, currx, 0, 0, 1);
			if (ret == 0)
				res = visit[currx][curry][curbx][curby];
			else
			{
				nextrx = ret;
				nextry = curry;
			}

			ret = decre(curby, curbx, 0, 0, 1);
			if (ret == 0)
			{
				if (res != 0)
					res = 0;
				bflag = 1;
			}
			else
			{
				nextbx = ret;
				nextby = curby;
			}
		}

		if (bflag == 0)
		{
			if (visit[nextrx][nextry][nextbx][nextby] == 0)
			{
				q.push({ { nextrx, nextry },{ nextbx, nextby } });
				visit[nextrx][nextry][nextbx][nextby] = visit[currx][curry][curbx][curby] + 1;
			}
		}

		if (res != 0)
			break;
		nextrx = 0;
		nextry = 0;
		nextbx = 0;
		nextby = 0;
		bflag = 0;
		//왼쪽
		if (currx == curbx)
		{
			if (curry < curby)
			{
				ret = decre(currx, curry, 0, 0, 0);
				if (ret == 0)
					res = visit[currx][curry][curbx][curby];
				else
				{
					nextrx = currx;
					nextry = ret;
				}

				ret = decre(curbx, curby, 1, nextry, 0);
				if (ret == 0)
				{
					if (res != 0)
						res = 0;
					bflag = 1;
				}
				else
				{
					nextbx = curbx;
					nextby = ret;
				}
			}
			else
			{
				ret = decre(curbx, curby, 0, 0, 0);
				if (ret == 0)
					bflag = 1;
				else
				{
					nextbx = curbx;
					nextby = ret;
				}
				ret = decre(currx, curry, 1, nextby, 0);
				if (ret == 0)
				{
					if (bflag == 0)
						res = visit[currx][curry][curbx][curby];
				}
				else
				{
					nextrx = currx;
					nextry = ret;
				}
			}
		}
		else
		{
			ret = decre(currx, curry, 0, 0, 0);
			if (ret == 0)
				res = visit[currx][curry][curbx][curby];
			else
			{
				nextrx = currx;
				nextry = ret;
			}

			ret = decre(curbx, curby, 0, 0, 0);
			if (ret == 0)
			{
				if (res != 0)
					res = 0;
				bflag = 1;
			}
			else
			{
				nextbx = curbx;
				nextby = ret;
			}
		}
		if (bflag == 0)
		{
			if (visit[nextrx][nextry][nextbx][nextby] == 0)
			{
				q.push({ { nextrx, nextry },{ nextbx, nextby } });
				visit[nextrx][nextry][nextbx][nextby] = visit[currx][curry][curbx][curby] + 1;
			}
		}

		if (res != 0)
			break;
		nextrx = 0;
		nextry = 0;
		nextbx = 0;
		nextby = 0;
		bflag = 0;
		//아래
		if (curry == curby)
		{
			if (currx > curbx)
			{
				ret = incre(curry, currx, 0, 0, n, 1);
				if (ret == 0)
					res = visit[currx][curry][curbx][curby];
				else
				{
					nextrx = ret;
					nextry = curry;
				}

				ret = incre(curby, curbx, 1, nextrx, n, 1);
				if (ret == 0)
				{
					if (res != 0)
						res = 0;
					bflag = 1;
				}
				else
				{
					nextbx = ret;
					nextby = curby;
				}
			}
			else
			{
				ret = incre(curby, curbx, 0, 0, n, 1);
				if (ret == 0)
					bflag = 1;
				else
				{
					nextbx = ret;
					nextby = curby;
				}

				ret = incre(curry, currx, 1, nextbx, n, 1);
				if (ret == 0)
				{
					if (bflag == 0)
						res = visit[currx][curry][curbx][curby];
				}
				else
				{
					nextrx = ret;
					nextry = curry;
				}
			}
		}
		else
		{
			ret = incre(curry, currx, 0, 0, n, 1);
			if (ret == 0)
				res = visit[currx][curry][curbx][curby];
			else
			{
				nextrx = ret;
				nextry = curry;
			}

			ret = incre(curby, curbx, 0, 0, n, 1);
			if (ret == 0)
			{
				if (res != 0)
					res = 0;
				bflag = 1;
			}
			else
			{
				nextbx = ret;
				nextby = curby;
			}
		}
		if (bflag == 0)
		{
			if (visit[nextrx][nextry][nextbx][nextby] == 0)
			{
				q.push({ { nextrx, nextry },{ nextbx, nextby } });
				visit[nextrx][nextry][nextbx][nextby] = visit[currx][curry][curbx][curby] + 1;
			}
		}

		if (res != 0)
			break;
		nextrx = 0;
		nextry = 0;
		nextbx = 0;
		nextby = 0;
		bflag = 0;
		// 오른쪽
		if (currx == curbx)
		{
			if (curry > curby)
			{
				ret = incre(currx, curry, 0, 0, m, 0);
				if (ret == 0)
					res = visit[currx][curry][curbx][curby];
				else
				{
					nextrx = currx;
					nextry = ret;
				}

				ret = incre(curbx, curby, 1, nextry, m, 0);
				if (ret == 0)
				{
					if (res != 0)
						res = 0;
					bflag = 1;
				}
				else
				{
					nextbx = curbx;
					nextby = ret;
				}
			}
			else
			{
				ret = incre(curbx, curby, 0, 0, m, 0);
				if (ret == 0)
					bflag = 1;
				else
				{
					nextbx = curbx;
					nextby = ret;
				}

				ret = incre(currx, curry, 1, nextby, m, 0);
				if (ret == 0)
				{
					if (bflag == 0)
						res = visit[currx][curry][curbx][curby];
				}
				else
				{
					nextrx = currx;
					nextry = ret;
				}
			}
		}
		else
		{
			ret = incre(currx, curry, 0, 0, m, 0);
			if (ret == 0)
				res = visit[currx][curry][curbx][curby];
			else
			{
				nextrx = currx;
				nextry = ret;
			}

			ret = incre(curbx, curby, 0, 0, m, 0);
			if (ret == 0)
			{
				if (res != 0)
					res = 0;
				bflag = 1;
			}
			else
			{
				nextbx = curbx;
				nextby = ret;
			}
		}

		if (bflag == 0)
		{
			if (visit[nextrx][nextry][nextbx][nextby] == 0)
			{
				q.push({ { nextrx, nextry },{ nextbx, nextby } });
				visit[nextrx][nextry][nextbx][nextby] = visit[currx][curry][curbx][curby] + 1;
			}
		}
	}
}

int main(void)
{
	int rx, ry, bx, by;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			scanf("%c ", &a);
			ary[i][j] = a;

			if (ary[i][j] == 'R')
			{
				ary[i][j] = '.';
				rx = i;
				ry = j;
			}
			else if (ary[i][j] == 'B')
			{
				ary[i][j] = '.';
				bx = i;
				by = j;
			}
		}
	}

	bfs(rx, ry, bx, by);
	if (res == 0)
		printf("-1\n");
	else
		printf("%d \n", res);
	return 0;
}
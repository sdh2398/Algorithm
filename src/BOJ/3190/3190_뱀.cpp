#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, k, l, res;
int ary[102][102];
int aryl[102][2];

int mx[4] = { 0, 1, 0, -1 };
int my[4] = { 1, 0, -1, 0 };

int nextdir[4][2];

void bfs()
{
	queue<pair<int, int>> q;
	deque<pair<int, int>> dq;
	ary[1][1] = 2;
	q.push({ 0, 0 });
	dq.push_back({ 1, 1 });

	while (!q.empty())
	{
		res++;
		int curx, cury;
		curx = dq.front().first;
		cury = dq.front().second;

		int dir, in;
		dir = q.front().first;
		in = q.front().second;
		q.pop();

		int nextx, nexty;
		nextx = curx + mx[dir];
		nexty = cury + my[dir];

		if (!(nextx >= 1 && nexty >= 1 && nextx <= n && nexty <= n) || ary[nextx][nexty] == 2)
			break;


		dq.push_front({ nextx, nexty });
		if (ary[nextx][nexty] == 0)
		{
			int backx, backy;
			backx = dq.back().first;
			backy = dq.back().second;
			ary[backx][backy] = 0;
			dq.pop_back();
		}
		ary[nextx][nexty] = 2;

		if (res == aryl[in][0])
		{
			if (in == l)
				break;
			dir = nextdir[dir][aryl[in][1]];
			in++;
			q.push({ dir, in });
		}
		else
			q.push({ dir, in });
	}
}

int main(void)
{
	scanf("%d %d ", &n, &k);

	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d %d ", &a, &b);
		ary[a][b] = 1;
	}

	scanf("%d ", &l);
	for (int i = 0; i < l; i++)
	{
		char a;
		scanf("%d %c ", &aryl[i][0], &a);
		if (a == 'L')
			aryl[i][1] = 0;
		else
			aryl[i][1] = 1;
	}

	nextdir[0][0] = 3;
	nextdir[0][1] = 1;
	nextdir[1][0] = 0;
	nextdir[1][1] = 2;
	nextdir[2][0] = 1;
	nextdir[2][1] = 3;
	nextdir[3][0] = 2;
	nextdir[3][1] = 0;

	bfs();
	printf("%d \n", res);

	return 0;
}
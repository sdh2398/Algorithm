#include <iostream>
#include <cstring>
using namespace std;

int m, n, x, y, res;
int ary[40002];

int add(int a, int b, int c)
{
	if ((a + b) % c == 0)
		return c;
	else
		return (a + b) % c;
}

void calendar(int a, int b, int c, int d) // x, y 중 작은 값을 기준으로 계산한다.
{
	ary[a] = 1;
	res = a;
	int next = add(a, b, d);
	if (ary[next] == 0)
	{
		res += b;
		if (next == c)
		{
			printf("%d \n", res);
			return;
		}
	}

	while (ary[next] == 0)
	{
		ary[next] = 1;
		next = add(next, b, d);
		res += b;

		if (next == c)
		{
			printf("%d \n", res);
			return;
		}
	}

	printf("%d \n", -1);
}

int main(void)
{
	int t;
	scanf("%d ", &t);

	for (int tc = 0; tc < t; tc++)
	{
		memset(ary, 0, sizeof(ary));
		scanf("%d %d %d %d ", &m, &n, &x, &y);

		int flag = 0;

		if (x == y)
			flag = 3;
		else if (x < y)
			flag = 1;
		else
			flag = 2;

		if (flag == 1)
			calendar(x, m, y, n);
		else if (flag == 2)
			calendar(y, n, x, m);
		else
			printf("%d \n", x);
	}

	return 0;
}
#include <iostream>
using namespace std;

int ary[30];
int res, n, s, sum;

void dfs(int a)
{
	if (a >= n)
		return;

	if (sum + ary[a] == s)
		res++;

	dfs(a + 1);

	sum += ary[a];
	dfs(a + 1);
	sum -= ary[a];
}

int main(void)
{
	scanf("%d %d ", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%d ", &ary[i]);

	dfs(0);

	printf("%d \n", res);
	return 0;
}
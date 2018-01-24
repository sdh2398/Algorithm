#include <iostream>
using namespace std;

long long ary[101][101][101];
long long mod = 1000000007;

int main(void)
{
	int n, l, r;
	scanf("%d %d %d ", &n, &l, &r);

	ary[1][1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				ary[i][j][k] = ary[i - 1][j - 1][k] + ary[i - 1][j][k - 1] + (ary[i - 1][j][k] * (i - 2));
				ary[i][j][k] %= mod;
			}
		}
	}

	printf("%lld \n", ary[n][l][r]);

	return 0;
}
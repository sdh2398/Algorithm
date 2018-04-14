#include <iostream>
#include <algorithm>
using namespace std;

int ary[202];
int dp[202];

int main(void)
{
	int n, res = 1;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
		scanf("%d ", &ary[i]);

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (ary[j] < ary[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				res = max(res, dp[i]);
			}
		}
	}

	printf("%d \n", n - res);

	return 0;
}
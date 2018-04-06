#include <iostream>
#include <algorithm>
using namespace std;

int res;
int t[16];
int p[16];
int dp[16];

int main(void)
{
	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d ", &t[i], &p[i]);

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + t[i] - 1 >= n)
			dp[i] = dp[i + 1];

		else
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
			//dp[i] = dp[i + t[i]] + p[i];

		/*if (i + t[i] == n)
			dp[i] = p[i];
		else
			dp[i] = dp[i + t[i]] + p[i];

		if (i != n - 1)
			dp[i] = max(dp[i], dp[i + 1]);
			*/
		res = max(res, dp[i]);
	}

	//for (int i = 0; i < n; i++)
	//	printf("%d ", dp[i]);
	//puts("");

//	for (int i = 0; i < n; i++)
	//	res = max(res, dp[i]);

	printf("%d \n", res);

	return 0;
}
#include <iostream>
using namespace std;

int ary[1000002];
int dp[1000002];

int main(void)
{
	int n, result = 0;
	scanf("%d ", &n);

	// 맨 뒤, 맨 앞으로만 보낼 수 있기 때문에 1씩 증가하는 최장 부분 수열을 구해야 한다.
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d ", &a);
		dp[a] = 1;

		if (dp[a - 1] != 0)
			dp[a] = dp[a - 1] + 1;
		if (result < dp[a])
			result = dp[a];
	}

	printf("%d\n", n - result);

	return 0;
}
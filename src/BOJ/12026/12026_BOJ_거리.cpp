#include <iostream>
#include <algorithm>
using namespace std;

char ary[1002];
int dp[1002];

int main(void)
{
	int n;
	scanf("%d ", &n);
	scanf("%s ", ary);
	
	dp[0] = 0;

	for (int i = 1; i < n; i++)
		dp[i] = 1000002;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if ((ary[i] == 'B' && ary[j] == 'O') || (ary[i] == 'O' && ary[j] == 'J') || (ary[i] == 'J' && ary[j] == 'B'))
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
		}
	}

	if (dp[n - 1] == 1000002)
		printf("-1\n");
	else
		printf("%d \n", dp[n - 1]);
	return 0;
}
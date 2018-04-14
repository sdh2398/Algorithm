#include <iostream>
#include <cstring>
using namespace std;

int ary[1000002];
int dp[1000002];

int lower_bound(int end, int n)
{
	int start = 0;

	while (start < end)
	{
		int mid = (start + end) / 2;

		if (dp[mid] >= n)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main(void)
{
	int n;

	memset(dp, 0, sizeof(dp));
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
		scanf("%d ", &ary[i]);

	dp[0] = ary[0];
	int idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (dp[idx] < ary[i])
		{
			idx++;
			dp[idx] = ary[i];
		}
		else
		{
			int curidx = lower_bound(idx, ary[i]);
			dp[curidx] = ary[i];
		}
	}

	printf("%d \n", idx + 1);

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n, resmax, resmin;
int ary[15];
int ary2[5];

void dfs(int cnt, int num)
{
	if (cnt == n - 1)
	{
		resmax = max(resmax, num);
		resmin = min(resmin, num);
	}

	if (ary2[0] > 0)
	{
		ary2[0]--;
		dfs(cnt + 1, num + ary[cnt + 1]);
		ary2[0]++;
	}
	if (ary2[1] > 0)
	{
		ary2[1]--;
		dfs(cnt + 1, num - ary[cnt + 1]);
		ary2[1]++;
	}
	if (ary2[2] > 0)
	{
		ary2[2]--;
		dfs(cnt + 1, num * ary[cnt + 1]);
		ary2[2]++;
	}
	if (ary2[3] > 0)
	{
		ary2[3]--;
		dfs(cnt + 1, num / ary[cnt + 1]);
		ary2[3]++;
	}
}

int main(void)
{
	scanf("%d ", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d ", &ary[i]);
	
	for (int i = 0; i < 4; i++)
		scanf("%d ", &ary2[i]);
	
	dfs(0, ary[0]);
	printf("%d \n%d \n", resmax, resmin);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ary[500002];
int visit[8002];
vector<int> vec;

int main(void)
{
	int n, sum = 0;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d ", &ary[i]);
		sum += ary[i];
		if (ary[i] < 0)
		{
			int tmp;
			tmp = 4000 - ary[i];
			visit[tmp]++;
		}
		else
			visit[ary[i]]++;
	}

	printf("%.0lf\n", (double)sum / n);

	sort(ary, ary + n);
	printf("%d \n", ary[n / 2]);

	int cntmax = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (cntmax < visit[i])
			cntmax = visit[i];
	}

	int flag = 0;
	int maxres = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (visit[i] == cntmax)
		{
			if (i <= 4000)
				vec.push_back(i);
			else
				vec.push_back(-(i - 4000));
		}
	}

	sort(vec.begin(), vec.end());
	if (vec.size() >= 2)
		printf("%d \n", vec[1]);
	else
		printf("%d \n", vec[0]);

	printf("%d \n", ary[n - 1] - ary[0]);

	return 0;
}
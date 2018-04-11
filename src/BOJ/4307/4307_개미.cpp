#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int t, l, n, minres, maxres;
	scanf("%d ", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d %d ", &l, &n);

		minres = 0;
		maxres = 0;

		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d ", &a);

			if (l / 2 >= a)
			{
				minres = max(minres, a);
				maxres = max(maxres, l - a);
			}
			else
			{
				minres = max(minres, l - a);
				maxres = max(maxres, a);
			}
		}

		printf("%d %d \n", minres, maxres);
	}

	return 0;
}
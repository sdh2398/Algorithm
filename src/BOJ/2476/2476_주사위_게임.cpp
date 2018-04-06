#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int res;
int visit[7];

int main(void)
{
	int n;
	scanf("%d ", &n);

	int tmpres;
	for (int i = 0; i < n; i++)
	{
		memset(visit, 0, sizeof(visit));
		int vmax = 0;
		int nmax = 0;
		int a, b, c;

		scanf("%d ", &a);
		visit[a]++;
		vmax = max(vmax, visit[a]);
		nmax = max(nmax, a);

		scanf("%d ", &b);
		visit[b]++;
		vmax = max(vmax, visit[b]);
		nmax = max(nmax, b);

		scanf("%d ", &c);
		visit[c]++;
		vmax = max(vmax, visit[c]);
		nmax = max(nmax, c);

		if (vmax == 1)
		{
			tmpres = nmax * 100;
		}
		else if (vmax == 2)
		{
			for (int i = 1; i <= 6; i++)
			{
				if (visit[i] == 2)
				{
					tmpres = 1000 + (i * 100);
					break;
				}
			}
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				if (visit[i] == 3)
				{
					tmpres = 10000 + (i * 1000);
					break;
				}
			}
		}
		res = max(res, tmpres);
	}

	printf("%d \n", res);

	return 0;
}
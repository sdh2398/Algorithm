#include <iostream>
using namespace std;

int ary[1000002];

int main(void)
{
	int n, b, c;
	long long res = 0;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
		scanf("%d ", &ary[i]);
	scanf("%d %d ", &b, &c);

	for (int i = 0; i < n; i++)
	{
		res++;
		if (ary[i] <= b)
			continue;

		int tmp = ary[i] - b;
		if (tmp % c != 0)
			res += (tmp / c) + 1;
		else
			res += tmp / c;
	}

	printf("%lld \n", res);
	
	return 0;
}
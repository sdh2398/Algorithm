#include <iostream>
#include <algorithm>
using namespace std;

long long res;
long long ary[10002];

int main(void)
{
	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld ", &ary[i]);

	sort(ary, ary + n);

	for (int i = 1; i < n; i++)
		res += (ary[i] - ary[i - 1]) * i * (n - i);

	printf("%lld \n", 2 * res);

	return 0;
}
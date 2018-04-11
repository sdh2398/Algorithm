#include <iostream>
using namespace std;

long long GCD(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		GCD(b, a % b);
}

int main(void)
{
	long long a, b;
	scanf("%lld %lld ", &a, &b);

	long long size = GCD(a, b);

	for (int i = 0; i < size; i++)
		printf("1");
	puts("");

	return 0;
}
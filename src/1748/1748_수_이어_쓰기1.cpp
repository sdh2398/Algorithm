#include <iostream>
#include <cmath>
using namespace std;

int ary[15];

int main(void)
{
	int n, len;
	scanf("%d ", &n);

	ary[1] = 9;
	for (int i = 2; i <= 9; i++)
		ary[i] = ary[i - 1] + (9 * (int)pow(10, i - 1) * i);

	for (len = 1; len <= 9; len++)
	{
		if (pow(10, len) > n)
			break;
	}

	printf("%d \n", ary[len - 1] + ((n - (int)pow(10, len - 1)) + 1) * len);

	return 0;
}
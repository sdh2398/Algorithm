#include <iostream>
using namespace std;

int main(void)
{
	int n;
	scanf("%d ", &n);

	int s = 1, add = 6;
	int cnt = 1;
	while (s < n)
	{
		cnt++;
		s += add;
		add += 6;
	}

	printf("%d \n", cnt);
	return 0;
}
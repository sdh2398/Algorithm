#include <iostream>
using namespace std;

int mnum, msum, flag;
int ary[10002];

int main(void)
{
	int m, n;
	scanf("%d %d ", &m, &n);

	for (int i = 2; i <= n; i++)
	{
		if (ary[i] == 0)
		{
			if (m <= i && mnum == 0)
			{
				flag = 1;
				mnum = i;
			}
			if (m <= i && i <= n)
				msum += i;

			for (int j = i; j <= n; j += i)
				ary[j] = 1;
		}
	}

	if (flag == 1)
		printf("%d \n%d \n", msum, mnum);
	else
		printf("-1\n");

	return 0;
}
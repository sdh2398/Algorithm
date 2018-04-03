#include <iostream>
#include <algorithm>
using namespace std;

int ary[10002];
int ary2[10002];

int main(void)
{
	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d ", &ary[i]);
		ary2[i] = ary[i];
	}

	sort(ary2, ary2 + n);
	next_permutation(ary, ary + n);

	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (ary[i] != ary2[i])
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", ary[i]);
		puts("");
	}
	else
		printf("-1\n");


	return 0;
}
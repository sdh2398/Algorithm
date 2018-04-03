#include <iostream>
using namespace std;

int ary[10][2];
int visit[10];

int indexSearch(int num)
{
	for (int i = 0; i < 6; i++)
	{
		if (ary[i][0] == num)
			return i;
	}
}

int main(void)
{
	int k, res;
	scanf("%d ", &k);

	for (int i = 0; i < 6; i++)
	{
		scanf("%d %d ", &ary[i][0], &ary[i][1]);
		visit[ary[i][0]]++;
	}

	int index;
	if (visit[1] == 2 && visit[3] == 2)
		index = indexSearch(4);
	else if (visit[1] == 2 && visit[4] == 2)
		index = indexSearch(2);
	else if (visit[2] == 2 && visit[4] == 2)
		index = indexSearch(3);
	else if (visit[2] == 2 && visit[3] == 2)
		index = indexSearch(1);

	res = k * (ary[index][1] * ary[(index + 1) % 6][1] - ary[(index + 3) % 6][1] * ary[(index + 4) % 6][1]);

	printf("%d \n", res);

	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

char ary[22];

int main(void)
{
	int t, r, size;
	scanf("%d ", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d ", &r);
		scanf("%s ", ary);

		size = strlen(ary);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < r; j++)
				printf("%c", ary[i]);
		}
		puts("");
	}

	return 0;
}
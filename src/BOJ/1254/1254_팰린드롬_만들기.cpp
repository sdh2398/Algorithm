#include <iostream>
#include <cstring>
using namespace std;

int len;
char ary[1002];
char rary[1002];

int pchk(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (rary[i] != ary[len - x + i])
			return 1;
	}
	return 0;
}

int main(void)
{
	int res = 0;
	scanf("%s ", ary);

	len = strlen(ary);
	for (int i = 0; i < len; i++)
		rary[i] = ary[len - i - 1];

	for (int i = 1; i <= len; i++)
	{
		if (pchk(i) == 0)
			res = len - i;
	}

	printf("%d \n", res + len);

	return 0;
}
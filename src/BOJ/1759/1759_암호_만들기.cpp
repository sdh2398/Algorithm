#include <iostream>
#include <algorithm>
using namespace std;

char pr[20];
char ary[20];
int l, c;

int mj(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	return 0;
}

void pass(int cur, int pos, int mo, int ja)
{
	if (cur == c + 1)
		return;

	if (pos == l)
	{
		if (mo >= 1 && ja >= 2)
			printf("%s \n", pr);
		return;
	}

	pr[pos] = ary[cur];
	if (mj(ary[cur]) == 1)
		mo++;
	else
		ja++;
	pass(cur + 1, pos + 1, mo, ja);

	if (mj(ary[cur]) == 1)
		mo--;
	else
		ja--;
	pass(cur + 1, pos, mo, ja);
}

int main(void)
{
	scanf("%d %d ", &l, &c);

	for (int i = 0; i < c; i++)
		scanf("%c ", &ary[i]);

	sort(ary, ary + c);

	pass(0, 0, 0, 0);

	return 0;
}
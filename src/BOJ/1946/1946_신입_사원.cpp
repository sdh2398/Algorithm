#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int t, n, res;
	scanf("%d ", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d ", &n);
		vector<pair<int, int>> vec;
		res = 1;

		for(int i=0; i<n; i++)
		{
			int a, b;
			scanf("%d %d ", &a, &b);
			vec.push_back({ a, b });
		}

		sort(vec.begin(), vec.end());

		int cur = vec[0].second;

		for (int i = 1; i < vec.size(); i++)
		{
			if (cur > vec[i].second)
			{
				res++;
				cur = vec[i].second;
			}
		}
		printf("%d \n", res);
	}
	
	return 0;
}
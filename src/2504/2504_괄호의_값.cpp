#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char ary[33];
stack<int> st;

int emp()
{
	if (st.empty() == 1)
		return 1;
	else
		return 0;
}

int main(void)
{
	int len, cur, tmp, res = 0, flag = 0;
	scanf("%s ", &ary);
	len = strlen(ary);

	for (int i = 0; i < len; i++)
	{
		if (ary[i] == '(' || ary[i] == '[')
			st.push(ary[i]);

		else if (ary[i] == ')')
		{
			flag = emp();
			if (flag == 1) break;
			tmp = 0;
			cur = 2;
			while (st.top() != '(')
			{
				if (st.top() == '[')
				{
					flag = 1;
					break;
				}
				int sttop = st.top();
				st.pop();
				tmp += sttop;

				flag = emp();
				if (flag == 1) break;
			}
			if (flag == 1) break;
			st.pop();
			if (tmp == 0)
				st.push(2);
			else
				st.push(2 * tmp);
		}
		else if (ary[i] == ']')
		{
			flag = emp();
			if (flag == 1) break;
			tmp = 0;
			cur = 3;
			while (st.top() != '[')
			{
				if (st.top() == '(')
				{
					flag = 1;
					break;
				}
				int sttop = st.top();
				st.pop();
				tmp += sttop;

				flag = emp();
				if (flag == 1) break;
			}
			if (flag == 1) break;
			st.pop();
			if (tmp == 0)
				st.push(3);
			else
				st.push(3 * tmp);
		}

		if (flag == 1)
			break;
	}

	while (st.empty() == 0)
	{
		if (st.top() == '(' || st.top() == '[')
		{
			flag = 1;
			break;
		}

		res += st.top();
		st.pop();
	}

	if (flag == 1)
		printf("%d \n", 0);
	else
		printf("%d \n", res);

	return 0;
}
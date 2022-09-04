#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> edge[55];

int solve(int node)
{
	if (edge[node].size() == 0)
		return 0;

	vector<int> childs;
	for (int child : edge[node])
		childs.push_back(solve(child));

	int result = 0;
	sort(childs.rbegin(), childs.rend());
	for (int i = 1; i <= edge[node].size(); i++)
		result = max(result, childs[i - 1] + i);

	return result;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if (i)
			edge[a].push_back(i);
	}

	printf("%d", solve(0));
}
#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n;
int nums[500001]; // 입력 배열
int sorted[500001]; // 정렬된 인덱스
int tree[2000001]; // 세그먼트 트리

void add(int start, int end, int node, int target)
{
	if (target < start || end < target)
		return;
	
	tree[node]++;

	if (start != end)
	{
		int mid = start + end >> 1;
		add(start, mid, node * 2, target);
		add(mid + 1, end, node * 2 + 1, target);
	}
}

int find(int start, int end, int left, int right, int node)
{
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = start + end >> 1;
	return find(start, mid, left, right, node * 2) + find(mid + 1, end, left, right, node * 2 + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", nums + i);
		sorted[i] = i;
	}

	sort(sorted, sorted + n, [](int a, int b) {
		if (nums[a] == nums[b])
			return a < b;
		return nums[a] < nums[b];
	});

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		result += find(0, n - 1, sorted[i] + 1, n - 1, 1);
		add(0, n - 1, 1, sorted[i]);
	}
	printf("%lld", result);
}
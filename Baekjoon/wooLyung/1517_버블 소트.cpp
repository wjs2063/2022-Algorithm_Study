#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n;
int nums[500001]; // 입력 배열
int arr1[500001];
int arr2[500001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", nums + i);

	stack<int> s;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.empty() || nums[s.top()] > nums[i])
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && nums[s.top()] <= nums[i])
			{
				arr1[i] += arr1[s.top()] + 1;
				if (nums[s.top()] == nums[i])
					arr2[i] += arr2[s.top()] + 1;
				s.pop();
			}
			s.push(i);
		}
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr1[i] - arr2[i];
		// printf("%d - %d\n", arr1[i], arr2[i]);
	}

	printf("%lld", sum);
}
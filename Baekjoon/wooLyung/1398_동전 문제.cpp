#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int len = 24;
long long arr[] = {
	1,
	10,
	25,
	100,
	1000,
	2500,
	10000,
	100000,
	250000,
	1000000,
	10000000,
	25000000,
	100000000,
	1000000000,
	2500000000,
	10000000000,
	100000000000,
	250000000000,
	1000000000000,
	10000000000000,
	25000000000000,
	100000000000000,
	1000000000000000,
	2500000000000000
};

int solve(long long a)
{
	int result = 0;
	for (int i = len - 1; i >= 0; i -= 3)
	{
		int tmp = 100000000;
		int C = a / arr[i];

		for (int c = 0; c <= C; c++)
		{
			int cnt = 0;
			long long a0 = a;

			cnt += c;
			a0 -= c * arr[i];

			cnt += a0 / arr[i - 1];
			a0 %= arr[i - 1];

			cnt += a0 / arr[i - 2];

			tmp = min(tmp, cnt);
		}

		result += tmp;
		a %= arr[i - 2];
	}

	return result;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long a;
		scanf("%lld", &a);
		printf("%d\n", solve(a));
	}
}
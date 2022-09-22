#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[333];
int sum[333];
int dp[333][333];
int pre[333][333];

void backTracking(int a, int b);

int main()
{
	// 입력
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", nums + i);

	// 초기화
	for (int i = 0; i < 333; i++)
		for (int j = 0; j < 333; j++)
			dp[i][j] = 100000000;

	// 누적합
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + nums[i - 1];

	// DP
	for (int a = 0; a < n; a++)
	{
		int tmp = 100000000;

		// a번째 인덱스까지 나눔
		for (int c = 0; c <= a; c++)
		{
			if (c == 0) // 0 ~ a까지 처음 묶음
			{
				dp[a][1] = sum[a + 1] - sum[0];
			}
			else
			{
				int tmp = 1000000000;
				for (int b = a; b > 0; b--) // b - 1까지 c 묶음이 있는 상태로 묶음
				{
					int curr = max(dp[b - 1][c], sum[a + 1] - sum[b]);
					if (tmp > curr)
					{
						tmp = curr;
						pre[a][c + 1] = b - 1;
					}
				}
				dp[a][c + 1] = tmp;
			}
		}
	}

	printf("%d\n", dp[n - 1][m]);
	backTracking(n - 1, m);
}

void backTracking(int a, int b)
{
	if (b != 0)
	{
		backTracking(pre[a][b], b - 1);
		if (b != 1)
			printf("%d ", a - pre[a][b]);
		else
			printf("%d ", a + 1);
	}
}
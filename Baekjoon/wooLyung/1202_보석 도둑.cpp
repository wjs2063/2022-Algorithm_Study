#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, k;
vector<pii> gem;
vector<int> backpack;

bool exist[333333] = { false, };
int parent[333333];

int Find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[min(x, y)] = max(x, y);
}

int main()
{
	// 입력
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int m, v;
		scanf("%d %d", &m, &v);
		gem.push_back({ m, v });
	}
	for (int i = 0; i < k; i++)
	{
		int c;
		scanf("%d", &c);
		backpack.push_back(c);
		parent[i] = i;
	}

	// 정렬
	sort(gem.begin(), gem.end(), [](const pii& p1, const pii& p2) {
		return p1.second > p2.second;
		});
	sort(backpack.begin(), backpack.end());

	long long answer = 0;
	for (int i = 0; i < n; i++)
	{
		pii g = gem[i];

		// 보석이 들어갈 수 있는 가장 작은 가방의 인덱스
		int idx = lower_bound(backpack.begin(), backpack.end(), g.first) - backpack.begin();

		if (idx >= k)
			continue;

		if (!exist[idx])
		{
			// 보석이 들어갈 수 있을 경우 보석을 넣음
			exist[idx] = true;
			answer += g.second;

			// 인접한 두 인덱스에 대하여, 존재한다면 Union
			if (idx - 1 >= 0 && exist[idx - 1])
				Union(idx, idx - 1);
			if (idx + 1 < k && exist[idx + 1])
				Union(idx, idx + 1);
		}
		else
		{
			// 보석이 들어갈 수 없을 경우 가장 오른쪽의 인덱스를 찾음
			int p = Find(idx);

			if (p + 1 < k)
			{
				idx = p + 1;

				// 보석이 들어갈 수 있을 경우 보석을 넣음
				exist[idx] = true;
				answer += g.second;

				// 인접한 두 인덱스에 대하여, 존재한다면 Union
				if (idx - 1 >= 0 && exist[idx - 1])
					Union(idx, idx - 1);
				if (idx + 1 < k && exist[idx + 1])
					Union(idx, idx + 1);
			}
		}
	}

	printf("%lld", answer);
}
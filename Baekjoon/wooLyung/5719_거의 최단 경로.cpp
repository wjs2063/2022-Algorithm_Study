#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, m, s, d;
int edge[501][501] = { 0, }; // 인접 행렬
vector<int> edgev[501]; // 인접 리스트
int dist[501]; // 최단 거리
vector<int> pre[501]; // 최단 경로에 속하는 이전 정점
bool visited[501]; // dfs 방문 체크

struct element
{
	int a, b;
	
	element(int a, int b) : a(a), b(b) { }

	int getDist()
	{
		return dist[a] + edge[a][b];
	}
};

bool operator<(element a, element b)
{
	return a.getDist() > b.getDist();
}

void dfs(int node)
{
	for (int k : pre[node])
	{
		edge[k][node] = -1;
		if (!visited[k])
		{
			visited[k] = true;
			dfs(k);
		}
	}
}

int main()
{
	while (true)
	{
		scanf("%d %d", &n, &m);

		if (n == 0)
			break;

		scanf("%d %d", &s, &d);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				edge[i][j] = 0;
			dist[i] = 100000000;
			pre[i].clear();
			edgev[i].clear();
			visited[i] = false;
		}

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge[a][b] = c;
			edgev[a].push_back(b);
		}

		// 1번째 다익스트라 : 최단 경로에 속하는 간선 찾기
		priority_queue<element> pq;
		pq.push(element(s, s));
		dist[s] = 0;
		edge[s][s] = 0;

		while (!pq.empty())
		{
			element t = pq.top();
			pq.pop();

			// 처음 방문함
			if (t.getDist() < dist[t.b] || t.a == s && t.b == s)
			{
				if (t.b != s)
					pre[t.b].push_back(t.a);
				dist[t.b] = t.getDist();

				for (int k : edgev[t.b])
					pq.push(element(t.b, k));
			}
			// 처음 방문이 아님
			else if (t.getDist() == dist[t.b])
			{
				pre[t.b].push_back(t.a);
			}
		}

		// 최단 경로에 속하는 간선 끊기
		visited[d] = true;
		dfs(d);

		// 2번째 다익스트라 : 거의 최단 경로
		for (int i = 0; i < n; i++)
			dist[i] = 100000000;

		pq.push(element(s, s));
		dist[s] = 0;
		edge[s][s] = 0;
		while (!pq.empty())
		{
			element t = pq.top();
			pq.pop();

			// 처음 방문함
			if (t.getDist() < dist[t.b] || t.a == s && t.b == s)
			{
				dist[t.b] = t.getDist();

				for (int k : edgev[t.b])
					if (edge[t.b][k] != -1)
						pq.push(element(t.b, k));
			}
		}

		printf("%d\n", dist[d] > 10000000 ? -1 : dist[d]);
	}
}
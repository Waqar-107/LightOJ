#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 110
#define inf 100000000
#define pp pair<int,int>

using namespace std;

bool vis[N];
int d1[N], d2[N];
vector<int> adj[N];

void bfs(int s,int id)
{
	memset(vis, 0, sizeof(vis));

	vis[s] = 1;

	if (id == 1)
		d1[s] = 0;
	else
		d2[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		for (int i = 0; i < adj[u].size(); i++)
		{
			if (!vis[adj[u][i]])
			{
				vis[adj[u][i]] = 1;

				if (id == 1)
					d1[adj[u][i]] = d1[u] + 1;
				else
					d2[adj[u][i]] = d2[u] + 1;

				q.push(adj[u][i]);
			}
		}
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int s,d,t;
	int u, v, w;
	int x, y;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		scanf("%d%d", &n, &m);

		for (i = 0; i < N; i++)
			adj[i].clear();

		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		scanf("%d%d", &s, &d);

		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));

		bfs(s, 1);
		bfs(d, 2);

		x = 0;
		for (i = 0; i < n; i++)
		{
			//cout << d1[i] << " " << d2[i] << endl;
			x = max(x, d1[i] + d2[i]);
		}
		
		printf("Case %d: %d\n", k, x); k++;
	}

	return 0;
}

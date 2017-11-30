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
#define N 200010
#define inf 100000000
#define pp pair<int,int>

using namespace std;

int x, y;
bool vis[N], ex[N];
vector<int> adj[N];

void dfs(int s, int c)
{
	vis[s] = 1;
	
	if (c == 0)
		x++;
	else
		y++;

	for (int i = 0; i < adj[s].size(); i++)
	{
		if (!vis[adj[s][i]])
		{
			dfs(adj[s][i], 1-c);
		}
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int s,d,t;
	int u, v, w;
	
	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		scanf("%d", &n);

		for (i = 0; i < N; i++)
			adj[i].clear();

		memset(vis, 0, sizeof(vis));
		memset(ex, 0, sizeof(ex));

		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);

			ex[u] = 1; ex[v] = 1;
		}

		m = 0;
		for (i = 1; i < N; i++)
		{
			x = 0, y = 0;
			if (ex[i] && !vis[i])
			{
				dfs(i, 0);
			}

			m += max(x, y);
		}

		printf("Case %d: %d\n", k,m); k++;
	}

	return 0;
}

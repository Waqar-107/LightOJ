#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
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
#define pp pair<int,int>
#define N 100100

using namespace std;

ll ans;
bool vis[N];
vector<int> adj[N];

ll dfs(int s)
{
	vis[s] = 1;

	ll temp;
	ll cnt = 0;
	for (int i = 0; i < adj[s].size(); i++)
	{
		if (!vis[adj[s][i]])
		{
			temp = dfs(adj[s][i]);

			ans += (temp*cnt);
			cnt += temp;
		}
	}

	return cnt + 1;
}

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m, x;
	int u, v;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < N; j++)
			adj[j].clear();

		scanf("%d", &m);
		printf("Case %d: %d", i, m - 1);

		for (j = 1; j < m; j++)
		{
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ans = 0;
		memset(vis, 0, sizeof(vis));
		dfs(1);
		
		printf(" %lld\n", ans);
	}
	
	return 0;
}

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
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1020
#define inf 100000
#define pp pair<int,int>

using namespace std;

int d[N];
int qtv, qtm;
vector<int> adj[N];
bool vis[N];

void dfs(int s)
{
	vis[s] = 1; qtv++; qtm += d[s]; //cout << d[s]<<" r "<<s;nl

	for (int i = 0; i < adj[s].size(); i++)
	{
		if (!vis[adj[s][i]])
			dfs(adj[s][i]);
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, n, m;
	int u, v, w;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		int avg=0;
		printf("Case %d: ", i);
		scanf("%d%d", &n, &m);

		for (j = 1; j <= n; j++)
			scanf("%d", &d[j]), avg += d[j];

		for (j = 1; j <= m; j++)
		{
			scanf("%d%d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		memset(vis, 0, sizeof(vis));

		bool f = 1;
		if (avg%n == 0)
		{
			avg /= n;
			qtm = 0, qtv = 0;
			for (j = 1; j <= n; j++)
			{
				if (!vis[j] && f)
				{
					dfs(j);

					//cout << qtm << " " << qtv;nl
					if (qtm%qtv != 0)
						f = 0;

					if (avg*qtv != qtm)
						f = 0;
				}
			}

			if (f)
				printf("Yes\n");

			else
				printf("No\n");
		}

		else
			printf("No\n");

		//clear
		for (j = 0; j < N; j++)
			adj[j].clear();
	}

	return 0;
}

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
#define N 110
#define inf 100000
#define pp pair<int,int>

using namespace std;

int tot, n, x;
int dist[N][N];
int dir[N][N];
bool vis[N];

void dfs(int s)
{
	vis[s] = 1;

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[s][i] < inf && !vis[i])
		{
			if (!dir[s][i])
				x += dist[s][i];

			dfs(i); cnt++;
		}
	}

	//in the last node cnt=0
	if (!cnt)
	{
		if (!dir[s][1])
			x += dist[s][1];
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, m;
	int u, v, w;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("Case %d: ", i);
		scanf("%d", &n);

		tot = 0; x = 0;
		
		memset(vis, 0, sizeof(vis));
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
				dist[j][k] = inf, dir[j][k]=0;
		}

		for (j = 0; j < n; j++)
		{
			scanf("%d%d%d", &u, &v, &w);

			tot += w;
			dist[u][v] = w;
			dist[v][u] = w;
			dir[u][v] = 1;
		}

		dfs(1);
		//cout << tot << " " << x;nl
		printf("%d\n", min(x, tot - x));
	}

	return 0;
}

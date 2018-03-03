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
#define N 100010
#define pp pair<int,int>

using namespace std;

bool cyc;
int color[N];
vector<int> adj[N];
map<string, int> mp;

void dfs(int s)
{
	if (cyc)return;

	if (!color[s])
	{
		color[s] = 1;

		for (int e=0;e<adj[s].size();e++)
			dfs(adj[s][e]);

		color[s] = 2;
	}

	else if (color[s] == 1)
	{
		cyc = 1; return;
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m, t;
	int u, v;
	string a, b;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		//clear the map and the vectors
		for (j = 0; j < N; j++)
			adj[j].clear();

		mp.clear();

		printf("Case %d: ", i);

		scanf("%d", &m); k = 1;
		while (m--)
		{
			cin >> a >> b;
			if (!mp[a])
				u = k, k++, mp[a]=u;
			else
				u = mp[a];

			if (!mp[b])
				v = k, k++, mp[b]=v;
			else
				v = mp[b];

			//b depends on a
			adj[v].push_back(u);
		}

		cyc = 0;
		memset(color, 0, sizeof(color));
		
		for (j = 1; j < k; j++)
		{
			if (!color[j] && !cyc)
				dfs(j);
		}

		if (cyc)
			printf("No\n");
		else
			printf("Yes\n");
	}
	
	return 0;
}

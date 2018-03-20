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
#define N 550
#define inf 10000000
#define pp pair<int,int>

using namespace std;

string s[N];
int cry, n, m, ans[N][N];
bool vis1[N][N];
bool vis2[N][N];

void dfs(int r, int c)
{
	if (r < 0 || c < 0 || r >= m || c >= n)
		return;

	if (s[r][c] == '#')
		return;

	vis1[r][c] = 1;
	
	if (s[r][c] == 'C')
		cry++;

	if (!vis1[r + 1][c])
		dfs(r + 1, c);

	if (!vis1[r - 1][c])
		dfs(r - 1, c);

	if (!vis1[r][c + 1])
		dfs(r, c + 1);

	if (!vis1[r][c - 1])
		dfs(r, c - 1);
}

void dfs2(int r, int c)
{
	if (r < 0 || c < 0 || r >= m || c >= n)
		return;

	if (s[r][c] == '#')
		return;

	vis2[r][c] = 1;
	ans[r][c] = cry;

	if (!vis2[r + 1][c])
		dfs2(r + 1, c);

	if (!vis2[r - 1][c])
		dfs2(r - 1, c);

	if (!vis2[r][c+1])
		dfs2(r, c+1);

	if (!vis2[r][c-1])
		dfs2(r, c-1);
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, t2;
	int x, y;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("Case %d:\n", i);

		scanf("%d%d%d", &m, &n, &t2);

		for (j = 0; j < m; j++)
			cin >> s[j];

		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));

		while (t2--)
		{
			scanf("%d%d", &x, &y);

			x--; y--;
			if (vis2[x][y])
				printf("%d\n", ans[x][y]);

			else
			{
				cry = 0;
				dfs(x, y);
				dfs2(x, y);
				printf("%d\n", ans[x][y]);
			}
		}
	}

	return 0;
}

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
#define N 25
#define inf 100000
#define pp pair<int,int>

using namespace std;

string s[N];
pp a, b, c, h;
int dist[N][N], n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool vis[N][N];

void bfs(int r,int c)
{
	memset(vis, 0, sizeof(vis));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			dist[i][j] = inf;
	}

	queue<pp> q;

	q.push({ r,c });
	dist[r][c] = 0;
	
	pp u;
	int x, y;
	while (!q.empty())
	{
		u = q.front();
		q.pop();

		if (vis[u.first][u.second])
			continue;

		for (int i = 0; i < 4; i++)
		{
			x = u.first + dx[i]; y = u.second + dy[i];

			if (x >= 0 && x < m && y >= 0 && y < n)
			{
				if (s[x][y] != '#' && s[x][y] != 'm' && !vis[x][y])
				{
					q.push({ x,y });
					dist[x][y] = 1 + dist[u.first][u.second];
				}
			}
		}

		vis[u.first][u.second] = 1;
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, t2;
	int x, y, z;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("Case %d: ", i);

		scanf("%d%d", &m, &n);
		for (j = 0; j < m; j++)
		{
			cin >> s[j];
			for (k = 0; k < n; k++)
			{
				if (s[j][k] == 'a')
					a = { j,k };

				else if (s[j][k] == 'b')
					b = { j,k };

				else if (s[j][k] == 'c')
					c = { j,k };

				else if (s[j][k] == 'h')
					h = { j,k };
			}
		}

		bfs(h.first, h.second);

		x = dist[a.first][a.second];
		y = dist[b.first][b.second];
		z = dist[c.first][c.second];

		printf("%d\n", max(x, max(y, z)));
	}

	return 0;
}

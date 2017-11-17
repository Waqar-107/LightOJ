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
#define N 55
#define inf 100000000
#define pp pair<int,int>

using namespace std;

struct edge
{
	int u, v, w;

	edge(int a, int b, int c)
	{
		u = a; v = b; w = c;
	}
};

class DisjointSetUnion
{
	int n;
	int *p, *r;

public:
	DisjointSetUnion(int x)
	{
		n = x;

		p = new int[n + 1];
		r = new int[n + 1];

		for (int i = 0; i <= n; i++)
			p[i] = i,r[i]=1;
	}

	void Union(int x, int y)
	{
		int a = Find(x);
		int b = Find(y);

		if (r[a]>r[b])
		{
			p[b] = a;
			r[a] += r[b];
		}

		else
		{
			p[a] = b;
			r[b] += r[a];
		}
	}

	int Find(int a)
	{
		if (p[a] == a)
			return a;

		return p[a] = Find(p[a]);
	}

	void fr()
	{
		delete[] p;
		delete[] r;
	}

	bool isConnected()
	{
		int x = Find(0),y;
		for (int i = 1; i < n; i++)
		{
			y = Find(i);
			if (x != y)
				return 0;
		}

		return 1;
	}
};

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int mat[N][N];

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int t,x;
	int u, v, w;
	
	cin >> t;

	k = 1;
	while (t--)
	{
		printf("Case %d: ", k); k++;

		scanf("%d", &n);

		memset(mat, 0, sizeof(mat));
		DisjointSetUnion dsu(n);
		vector<edge> v;
		
		int cnt = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &w);

				cnt += w;
				if (w > 0 && i != j)
				{
					v.push_back(edge(i, j, w));
				}
			}
		}

		sort(v.begin(), v.end(), cmp);

		j = 0;
		for (i = 0; i < v.size(); i++)
		{
			if (dsu.Find(v[i].u) != dsu.Find(v[i].v))
				dsu.Union(v[i].u, v[i].v), j += v[i].w;
		}

		if (dsu.isConnected())
			printf("%d\n", cnt - j);
		else
			printf("-1\n");
	}

	return 0;
}

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
#define N 100005
#define inf 100000000
#define pp pair<int,int>

using namespace std;

struct d
{
	string a, b;
	int w;

	d() {}
	d(string x, string y, int z)
	{
		a = x; b = y; w = z;
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

		for (int i = 1; i <= n; i++)
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

	bool ds()
	{
		int x = -1,y;
		for (int i = 1; i <= n; i++)
		{
			if (x == -1)
				x = Find(i);
			else
			{
				y = Find(i);
				if (x != y)
					return 0;
			}
		}

		return 1;
	}
};

bool cmp(d a, d b)
{
	return a.w < b.w;
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int t,x;
	int u, v2;
	int cnt;
	string s, z;
	
	cin >> t;

	k = 1;
	while (t--)
	{
		printf("Case %d: ", k); k++;

		map<string, int> mp;

		x = 1; cnt = 0;

		scanf("%d", &n);
		vector<d> v;

		for (i = 0; i < n; i++)
		{
			cin >> s >> z >> m;
			v.push_back(d(s, z, m));

			if (!mp[s])
				mp[s] = x, x++;

			if (!mp[z])
				mp[z] = x, x++;
		}

		DisjointSetUnion dsu(mp.size());
		
		sort(v.begin(), v.end(), cmp);
		for(i=0;i<n;i++)
		{
			s = v[i].a; z = v[i].b;
			u = mp[s]; v2= mp[z];

			if (dsu.Find(u) != dsu.Find(v2))
			{
				cnt += v[i].w;
				dsu.Union(u, v2);
			}
		}

		if (dsu.ds())
			printf("%d\n", cnt);
		else
			printf("Impossible\n");

		dsu.fr();
	}
	
	return 0;
}

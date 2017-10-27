/***from dust i have come, dust i will be***/

#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<cmath>
#include<queue>
#include<algorithm>

typedef long long int ll;

#define dbg printf("in\n");
#define nl printf("\n");
#define inf 1000000
#define N 100020

using namespace std;

class segTree
{
	int i;
	int *arr; ll *ans;

public:
	segTree(int n)
	{
		arr = new int[n + 1];
		ans = new ll[4 * n];

		i = 1;
	}

	void input(int x)
	{
		arr[i] = x; i++;
	}

	void build(int at, int l, int r)
	{
		ans[at] = 0;

		if (l == r)
		{
			ans[at] = arr[l];
			return;
		}

		int mid = (l + r) / 2;

		build(at * 2, l, mid);
		build(at * 2 + 1, mid + 1, r);

		ans[at] = ans[at * 2] + ans[at * 2 + 1];
	}

	ll query(int at, int L, int R, int l, int r)
	{
		if (r < L || R < l)
			return 0;

		if (l <= L && R <= r)
			return ans[at];

		int mid = (L + R) / 2;

		ll x = query(at * 2, L, mid, l, r);
		ll y = query(at * 2 + 1, mid + 1, R, l, r);

		return x + y;
	}

	void update(int at, int l, int r, int pos, ll u, bool p)
	{
		if (l == r)
		{
			if (p)
				printf("%lld\n", ans[at]);

			ans[at] = u;
			return;
		}

		int mid = (l + r) / 2;

		if (pos <= mid)
			update(at * 2, l, mid, pos, u, p);

		else
			update(at * 2 + 1, mid + 1, r, pos, u, p);

		ans[at] = ans[at * 2] + ans[at * 2 + 1];
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, x, t, q;
	int l, r, y;
	ll u;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d:\n", k); k++;

		scanf("%d%d", &n, &q);

		segTree s(n);
		ll *a = new ll[n];

		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s.input(x);
			a[i] = x;
		}

		s.build(1, 1, n);

		while (q--)
		{
			scanf("%d", &y);

			//empty
			if (y == 1)
			{
				scanf("%d", &x); a[x] = 0; x++;
				s.update(1, 1, n, x, 0, 1);
			}

			//update
			else if (y == 2)
			{
				scanf("%d%lld", &l, &u); a[l] += u; l++;
				s.update(1, 1, n, l, a[l - 1], 0);
			}

			//query
			else
			{
				scanf("%d%d", &l, &r); l++; r++;
				printf("%lld\n", s.query(1, 1, n, l, r));
			}
		}
	}

	return 0;
}

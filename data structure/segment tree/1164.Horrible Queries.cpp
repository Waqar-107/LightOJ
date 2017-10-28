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
	int *arr;
	ll *ans, *lazy;

public:
	segTree(int n)
	{
		arr = new int[n + 1];
		ans = new ll[4 * n];
		lazy = new ll[4 * n];

		for (i = 1; i <4* n; i++)
			ans[i] = 0, lazy[i] = 0;

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

	ll query(int at, int l, int r, int L, int R)
	{
		//resolve the pending
		if (lazy[at] != 0)
		{
			ans[at] += (r - l + 1)*lazy[at];

			//if not a leaf, then update the lazy for children
			if (l != r)
			{
				lazy[at * 2] += lazy[at];
				lazy[at * 2 + 1] += lazy[at];
			}

			lazy[at] = 0;
		}

		//out of range
		if (l > r || l > R || L > r)
			return 0;

		//segment lies in the range
		if (l >= L &&  r <= R)
			return ans[at];

		int mid = (l + r) / 2;

		ll x = query(at * 2, l, mid, L, R);
		ll y = query(at * 2 + 1, mid + 1, r, L, R);

		return x + y;
	}

	void update(int at, int l, int r, int L, int R, ll u)
	{
		//resolve pendings
		if (lazy[at] != 0)
		{
			ans[at] += (r - l + 1)*lazy[at];

			//if not leaf then set lazy for the children, they will be updated later
			if (l != r)
			{
				lazy[at * 2] += lazy[at];
				lazy[at * 2 + 1] += lazy[at];
			}

			lazy[at] = 0;
		}

		//out of range
		if (l > r || l > R || r < L)
			return;

		//current segment fully in range
		if (l >= L && r <= R)
		{
			ans[at] += (r - l + 1)*u;

			//set the children for later updating
			if (l != r)
			{
				lazy[at * 2] += u;
				lazy[at * 2 + 1] += u;
			}

			return;
		}

		//if not completely in range
		int mid = (l + r) / 2;

		update(at * 2, l, mid, L, R, u);
		update(at * 2 + 1, mid + 1, r, L, R, u);

		ans[at] = ans[at * 2] + ans[at * 2 + 1];
	}

	void print()
	{
		for (i = 1; i <= 27; i++)
			cout << ans[i] << " ";
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, t, m;
	int a, x;
	int l, r;
	ll u;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d:\n", k); k++;
		scanf("%d%d", &n, &m);

		segTree s(n);

		for (i = 0; i < n; i++)
			s.input(0);

		s.build(1, 1, n);

		while (m--)
		{
			scanf("%d", &a);

			if (!a)
			{
				scanf("%d%d%lld", &l, &r, &u);
				l++; r++;

				s.update(1, 1, n, l, r, u);
			}

			else
			{
				scanf("%d%d", &l, &r);
				l++; r++;

				printf("%lld\n", s.query(1, 1, n, l, r));
			}
		}
	}

	return 0;
}

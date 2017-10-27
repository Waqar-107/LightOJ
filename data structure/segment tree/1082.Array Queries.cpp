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
#define pp pair<int,int>
#define N 1010

using namespace std;

class segTree
{
	int i;
	int *arr, *ans;

public:
	segTree(int n)
	{
		arr = new int[n + 1];
		ans=new int[4 * n];

		i = 1;
	}

	void input(int x)
	{
		arr[i] = x; i++;
	}

	void build(int at, int l, int r)
	{
		ans[at] = inf;

		if (l == r)
		{
			ans[at] = arr[l];
			return;
		}

		int mid = (l + r) / 2;

		build(at * 2, l, mid);
		build(at * 2 + 1, mid + 1, r);

		ans[at] = min(ans[at * 2], ans[at * 2 + 1]);
	}

	int query(int at, int L, int R, int l, int r)
	{
		if (r < L || R < l)
			return inf;

		if (l <= L && R<=r)
			return ans[at];

		int mid = (L + R) / 2;

		int x = query(at * 2, L, mid, l, r);
		int y = query(at * 2 + 1, mid + 1, R, l, r);

		return min(x, y);
	}

};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n,x,t,q;
	int l, r;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d:\n", k); k++;

		scanf("%d%d", &n, &q);

		segTree s(n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s.input(x);
		}

		s.build(1,1,n);
		//s.print();
		while (q--)
		{
			scanf("%d%d", &l, &r);

			printf("%d\n", s.query(1, 1, n, l, r));
		}
	}

	return 0;
}

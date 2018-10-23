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
#define N 100100
#define inf 1e18

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

ll koyta_zero(ll n)
{
	ll p = 5, cnt = 0, x;
	while (1)
	{
		x = n / p; p *= 5;
		cnt += x;

		if (!x)return cnt;
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m, t;

	ll hi, lo, mid, ans, q, x;

	sf(t);
	for (i = 1; i <= t; i++)
	{
		printf("Case %d: ",i);

		sfl(q);
		hi = inf, lo = 1, ans = inf;

		while (lo <= hi)
		{
			mid = (hi + lo) / 2;

			x = koyta_zero(mid);

			if (x == q)
				hi = mid - 1, ans = min(mid, ans);

			else if (x > q)
				hi = mid - 1;

			else
				lo = mid + 1;
		}

		if (ans == inf)
			printf("impossible\n");
		else
			printf("%lld\n", ans);
	}

	return 0;
}

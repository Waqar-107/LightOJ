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
#define N 5000000
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

vector<int> phi;
ull pre[N + 1];

void euler(int n)
{
	phi.resize(n + 1);

	for (int i = 0; i <= n; i++)
		phi[i] = i;

	for (int p = 2; p <= n; p++)
	{
		//p is prime
		if (phi[p] == p)
		{
			phi[p] = p - 1;
			for (int i = 2 * p; i <= n; i += p)
				phi[i] = (phi[i] / p) * (p - 1);
		}
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m, t;

	euler(N);
	memset(pre, 0, sizeof(pre));

	ull x;
	for (i = 2; i <= N; i++)
		x = (ull)phi[i], pre[i] = pre[i - 1] + x * x;

	sf(t);
	for (i = 1; i <= t; i++)
	{ 
		sff(j, k);
		printf("Case %d: ", i);
		cout << pre[k] - pre[j - 1];
		pfs("\n");
	}
	
	return 0;
}

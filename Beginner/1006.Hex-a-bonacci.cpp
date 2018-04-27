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

#define dbg printf("in\n")
#define nl printf("\n");
#define N 10100
#define mod 10000007

using namespace std;

ll dp[N], sum, n;
int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, m, idx = 1;
	int x, y;

	scanf("%d", &t);

	while (t--)
	{
		printf("Case %d: ", idx); idx++;
		
		sum = 0;
		for (i = 0; i < 6; i++) {
			scanf("%lld", &dp[i]);
		}

		scanf("%lld", &n);

		for (i = 6; i <= n; i++)
		{
			dp[i] = (dp[i - 1]%mod + dp[i - 2]%mod + dp[i - 3]%mod + dp[i - 4]%mod + dp[i - 5]%mod + dp[i - 6]%mod) % mod;
		}

		printf("%lld\n", dp[n]%mod);
	}


	return 0;
}


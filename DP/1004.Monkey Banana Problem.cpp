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
#define N 250

using namespace std;

vector<int> dp[N];
vector<int> v[N];

void clr()
{
	for (int i = 0; i < N; i++)
		dp[i].clear(), v[i].clear();
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int t, n, m, idx = 1;
	int x, y;

	scanf("%d", &t);

	while (t--)
	{
		printf("Case %d: ", idx); idx++;

		clr();
		scanf("%d", &n);

		//upper-part input
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= i; j++)
				scanf("%d", &m), v[i].push_back(m);
		}

		//lower-part input
		k = n - 1;
		for (i = n + 1; i <= 2 * n - 1; i++)
		{
			for (j = 1; j <= k; j++)
				scanf("%d", &m), v[i].push_back(m);
			k--;
		}
		
		//upper-part calculation
		dp[1].push_back(v[1][0]);
		for (i = 2; i <= n; i++)
		{
			dp[i].push_back(dp[i - 1][0] + v[i][0]);
			x = 0, y = 1;

			for (j = 2; j < i; j++)
			{
				dp[i].push_back(max(dp[i - 1][x], dp[i - 1][y]) + v[i][j - 1]);
				x++; y++;
			}

			dp[i].push_back(dp[i - 1][i - 2] + v[i][i - 1]);
		}

		/*for (i = 1; i <= n; i++)
		{
			for (int e : dp[i])
				cout << e << " ";
			nl
		}*/

		//lower-part calculation
		k = n - 1;
		for (i = n + 1; i <= 2 * n + 1; i++)
		{
			x = 0; y = 1;
			for (j = 1; j <= k; j++)
			{
				dp[i].push_back(max(dp[i - 1][x], dp[i - 1][y]) + v[i][j - 1]);
				x++; y++;
			}

			k--;
		}

		printf("%d\n", dp[2 * n - 1][0]);
	}

	return 0;
}


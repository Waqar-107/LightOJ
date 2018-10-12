#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
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
#define nl printf("\n")
#define N 120
#define inf 1000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

string s;
int dp[N][N];

int solve(int i, int j)
{
	if (i >= j) return 0;

	if (dp[i][j] != -1)return dp[i][j];

	//if equal then no need to insert a char
	if (s[i] == s[j])
	{
		dp[i][j] = solve(i + 1, j - 1);
		return dp[i][j];
	}

	//we can either insert a char for i -> (i+1,j) or a char for j->(i,j-1) 
	dp[i][j] = 1 + min(solve(i + 1, j), solve(i, j - 1));
	return dp[i][j];
}

int main()
{
	freopen("in2.txt", "r", stdin);
	
	int i, j, k;
	int n, m, t;
	
	sf(t);
	for (i = 1; i <= t; i++)
	{
		cin >> s;

		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n",i,solve(0, s.length() - 1));
	}

	return 0;
}

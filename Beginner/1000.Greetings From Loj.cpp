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
		scanf("%d%d", &n, &m);
		printf("%d\n", n + m);
	}

	return 0;
}


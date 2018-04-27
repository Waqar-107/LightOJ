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
		scanf("%d", &n);

		if (n <= 10)
			printf("0 %d\n", n);
		else
			printf("10 %d\n", n - 10);
	}


	return 0;
}


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
#define N 3010
#define pi acos(-1.0)
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

int gcd(int a, int b)
{
	if (a%b == 0)
		return b;

	return gcd(b, a%b);
}

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m;
	double R, x;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		printf("Case %d: ", i);

		int pos = 0, tot = 0;
		while (m--)
		{
			scanf("%d", &k);

			tot += abs(k);
			if (k > 0)
				pos++;
		}

		if (!pos)
			printf("inf\n");

		else
		{
			int x = gcd(tot, pos);
			pos /= x;
			tot /= x;

			printf("%d/%d\n", tot, pos);
		}

	}

	return 0;
}

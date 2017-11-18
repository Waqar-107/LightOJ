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
#define N 100010
#define inf 100000000
#define pp pair<ll,ll>

using namespace std;

int a[110];
int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m,t;
	
	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d: ", k); k ++ ;

		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		int cnt = 0;
		for (i = 1; i <= n; i++)
		{
			while (i != a[i])
			{
				j = a[i];
				swap(a[i], a[j]);
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}

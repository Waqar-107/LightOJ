#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
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
#define pp pair<int,int>
#define N 550

using namespace std;

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m, x;
	int r, q;
	
	scanf("%d\n", &n);
	
	for (j = 1; j <= n; j++) 
	{
		printf("Case %d: ", j);

		scanf("%d", &m);

		k = m;
		int sum = 0;
		while (m)
		{
			r = m % 10;
			sum = sum * 10 + r;
			m /= 10;
		}

		if (sum == k)
			printf("Yes\n");

		else
			printf("No\n");
	}

	return 0;
}

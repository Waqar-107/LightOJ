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
#define pp pair<string,int>

using namespace std;

bool cmp(pp a, pp b)
{
	return a.second< b.second;
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, t;
	int l,w,h;
	string s;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d: ", k); k++;

		scanf("%d", &n); 
		pp *a = new pp[n];

		for (i = 0; i < n; i++)
		{
			cin >> s;
			scanf("%d%d%d", &l, &w, &h);

			a[i]= { s,(l*w*h)};
		}

		sort(a, a + n, cmp);
		
		if (a[0].second != a[n - 1].second)
		{
			cout << a[n - 1].first;
			printf(" took chocolate from ");
			cout << a[0].first << endl;
		}

		else
		{
			printf("no thief\n");
		}
	}

	return 0;
}

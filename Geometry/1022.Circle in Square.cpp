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
#define pi 2*acos(0.0)
#define pp pair<string,int>

using namespace std;

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, t;
	double r, ar;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		printf("Case %d: ", k); k++;
		scanf("%lf", &r);

		ar = (4 * r*r) - (pi*r*r);
		ar += (0.000000001);
		printf("%.2lf\n", ar);
	}

	return 0;
}

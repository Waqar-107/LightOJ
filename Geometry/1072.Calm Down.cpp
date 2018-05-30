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

vector<int> v[N];

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m;
	double R, x;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		cin >> R >> m;
		printf("Case %d: ", i);

		x = 1 + sin(pi / m);
		x = (R *sin(pi / m)) / x;
		
		cout << setprecision(10) << x << endl;
	}

	return 0;
}

/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 35
#define inf 1e18
#define mod 100000007

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int, int>

using namespace std;

ll dp[N][N];

ll solve(int n, int k)
{
    if(k == 1)
        dp[n][k] = n;

    else if(n == k || k == 0)
        dp[n][k] = 1;

    else if(dp[n][k] == -1)
        dp[n][k] = solve(n - 1, k) + solve(n - 1, k - 1);

    return dp[n][k];
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, q;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            dp[i][j] = -1;
    }

    sf(q);
    for(i = 1; i <= q; i++)
    {
        printf("Case %d: ", i);

        sff(n, k);

        if(n < k){
            pfs("0\n");
            continue;
        }

        ll t = 1, x = n, j = k;
        while(j--)
        {
            t *= x;
            x--;
        }

        solve(n, k);
        cout << (dp[n][k] * t) << endl;
    }

    return 0;
}

/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 201010
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

ll dp[55][1010];

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, q;

    sf(q);
    for(int c = 1; c <= q; c++)
    {
        printf("Case %d: ", c);

        sff(n, k);

        int a[n + 1], b[n + 1];
        for(i = 1; i <= n; i++)
            sf(a[i]);

        for(i = 1; i <= n; i++)
            sf(b[i]);

        memset(dp, 0, sizeof(dp));

        // base case -> ways to make 0 is always 1
        for(i = 0; i<= n; i++)
            dp[i][0] = 1;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= k; j++)
            {
                for(m = 0; m <= b[i]; m++)
                {
                    if(j < m * a[i])break;
                    dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j - m * a[i]] % mod)) % mod;
                }
            }
        }

        cout << dp[n][k] << endl;
    }

    return 0;
}

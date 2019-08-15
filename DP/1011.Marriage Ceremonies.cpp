/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 65600
#define inf 1e18
#define mod 998244353

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

#define mod 10000007

using namespace std;

int n;
ll dp[N];
int mat[20][20];

ll solve(int mask, int lvl)
{
   if(mask == (1 << n) - 1)return 0;
   if(lvl >= n)return 0;

   if(dp[mask] != -1)return dp[mask];

   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
       //cout <<lvl<<" "<< (1 << i) << " "<< mask<<" "<<((1 << i) & mask);nl;
       if(((1 << i) & mask) == 0)
           ans = max(ans, mat[lvl][i] + solve((1 << i) | mask, lvl + 1));
   }

   return dp[mask] = ans;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int m, q;

    sf(q);
    for(i = 1; i <= q; i++)
    {
        printf("Case %d: ", i);

        sf(n);
        fill(dp, dp + N, -1);
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
                sf(mat[j][k]);
        }

        printf("%lld\n", solve(0, 0));
    }

    return 0;
}

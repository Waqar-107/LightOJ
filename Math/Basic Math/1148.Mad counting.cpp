/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 1000010
#define inf 1000000000
#define mod 1000003

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d\n",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<string,int>

using namespace std;

int mp[N];
void solve()
{
    int i,j,k;
    int n,m;

    int cnt=0;
    memset(mp,0,sizeof(mp));

    sf(n);
    for(i=0;i<n;i++)
    {
        sf(m);

        if(!mp[m])
            cnt+=(m+1), mp[m]=m;
        else
            mp[m]--;
    }

    pf(cnt);
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m,t;

    sf(t);
    for(i=1;i<=t;i++)
    {
        printf("Case %d: ",i);
        solve();
    }

    return 0;
}

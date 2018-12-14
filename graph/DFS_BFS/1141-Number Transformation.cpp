/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1010

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

bool status[N];
vector<int> primes;

void sieve_of_eratosthenes() {
    int sq = sqrtl(N * 1.0);

    memset(status, 0, sizeof(status));

    status[0] = status[1] = 1;

    //all the evens except 2 is composite
    for (int i = 4; i < N; i += 2)
        status[i] = 1;

    for (int i = 3; i <= sq; i += 2) {
        if (!status[i]) {
            //i is prime so its multipliers are not
            for (int j = i * i; j < N; j += i + i)
                status[j] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!status[i])
            primes.pb(i);
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;
    int d, c;

    map<int, bool> vis;
    queue<pp> q;

    sieve_of_eratosthenes();

    sf(t);
    for (i = 1; i <= t; i++) {
        sff(n, m);
        printf("Case %d: ", i);

        q.push({n, 0});k = 0;

        while (q.size()) {
            c = q.front().first;
            d = q.front().second;

            q.pop();

            vis[c] = true;

            if (c == m) {
                pf(d); pfs("\n"); k = 1;
                break;
            }

            if(c < m)
            {
                for (int e : primes) {
                    if (c > e && (c % e) == 0 && (e + c) <= m && !vis[(e + c)])
                        q.push({e + c, d + 1});
                }
            }
        }

        if(!k)
            pfs("-1\n");

        while(!q.empty())
            q.pop();

        vis.clear();
    }

    return 0;
}

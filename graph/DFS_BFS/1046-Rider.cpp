/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 15

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

int n, m;
int d, x, y;
string a[N];
bool vis[N][N];
int cnt[N][N], cnt2[N][N];

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool inside(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void bfs(int r, int c, int v) {
    queue<pair<pp, int>> q;
    q.push({{r, c}, 0});

    vis[r][c] = true;

    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        d = q.front().second;

        q.pop();
        cnt2[x][y]++;

        for (int i = 0; i < 8; i++) {
            if (inside(x + dx[i], y + dy[i]) && !vis[x + dx[i]][y + dy[i]]) {
                q.push({{x + dx[i], y + dy[i]}, d + 1});
                vis[x + dx[i]][y + dy[i]] = true;
                if((d + 1) % v == 0)
                    cnt[x + dx[i]][y + dy[i]] += (d + 1) / v;
                else
                    cnt[x + dx[i]][y + dy[i]] += (d + 1) / v + 1;
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int t, z;

    sf(t);
    for (i = 1; i <= t; i++) {
        sff(n, m);
        printf("Case %d: ", i);

        for (j = 0; j < n; j++)
            cin >> a[j];

        z = 0;
        memset(cnt2, 0, sizeof((cnt2)));
        memset(cnt, 0, sizeof(cnt));

        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (a[j][k] != '.') {
                    memset(vis, 0, sizeof(vis));
                    bfs(j, k, a[j][k] - '0');
                    z++;
                }
            }
        }

        int mn = -1;
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
               // cout << cnt[j][k] << " ";
                if (cnt2[j][k] == z) {
                    if (mn == -1 || mn > cnt[j][k])
                        mn = cnt[j][k];
                }
            }
            //nl;
        }

        pf(mn);
        nl;
    }

    return 0;
}

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

#define dbg printf("in\n")
#define nl printf("\n");
#define N 100010
#define pp pair<int,int>

using namespace std;

int cnt[N];
bool vis[N];
vector<int> adj[N];

void dfs(int s)
{
   vis[s]=1;cnt[s]++;

   for(int i=0;i<adj[s].size();i++)
   {
       if(!vis[adj[s][i]])
        dfs(adj[s][i]);
   }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m,t;
    int u,v,w;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        printf("Case %d: ",i);

        for(j=0; j<N; j++)
            adj[j].clear();

        scanf("%d%d%d",&k,&n,&m);

        int a[k];
        for(j=0;j<k;j++)
            scanf("%d",&a[k]);

        for(j=0; j<m; j++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        memset(cnt,0,sizeof(cnt));
        for(j=0;j<k;j++)
        {
            memset(vis,0,sizeof(vis));
            dfs(a[k]);
        }

        int x=0;
        for(j=1;j<=n;j++)
        {
            if(cnt[j]==k)
                x++;
        }

        printf("%d\n",x);
    }

    return 0;
}

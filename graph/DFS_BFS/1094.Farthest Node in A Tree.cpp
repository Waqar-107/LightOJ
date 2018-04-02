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

int ans;
bool vis[N];
vector<pp> adj[N];

int dfs(int s)
{
    vis[s]=1;//cout<<"visited "<<s<<endl;
    vector<int> temp;

    int x;
    for(int i=0; i<adj[s].size(); i++)
    {
        if(!vis[adj[s][i].first])
        {
            x=dfs(adj[s][i].first)+adj[s][i].second;
            temp.push_back(x);
            //cout<<x<<"  "<<s<<"  "<<adj[s][i].first;nl
        }
    }

    sort(temp.begin(),temp.end(),greater<int>());

    if(temp.size()>1)
        ans=max(temp[0]+temp[1],ans);

    if(temp.size())
    {
        ans=max(ans,temp[0]);
        return temp[0];
    }

    return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m,t;
    int u,v,w;

    cin>>t;
    for(i=1; i<=t; i++)
    {
        printf("Case %d: ",i);

        memset(vis,0,sizeof(vis));
        for(j=0; j<N; j++)
            adj[j].clear();

        cin>>n;
        for(j=0; j<n-1; j++)
        {
            cin>>u>>v>>w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        ans=0;

        dfs(1);
        cout<<ans<<endl;
    }

    return 0;
}

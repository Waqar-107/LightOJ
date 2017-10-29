/***from dust i have come, dust i will be***/
 
#include<bits/stdc++.h>
 
typedef long long int ll;
 
#define dbg printf("in\n");
#define nl printf("\n");
#define pp pair<int,int>
#define N 21
 
using namespace std;
 
int n,m;
bool vis[N][N];
char mp[N][N];
 
void dfs(int i,int j)
{
    if(i<=0 || j<=0 || i>n || j>m || vis[i][j])
        return;
 
    if(mp[i][j]=='#')
        return;
 
    vis[i][j]=1;
 
    dfs(i+1,j);dfs(i-1,j);
    dfs(i,j+1);dfs(i,j-1);
}
 
int main()
{
    //freopen("in.txt","r",stdin);
 
    int i,j,k;
    int u,v,t;
 
    scanf("%d",&t);
 
    k=1;
    while(t--)
    {
        printf("Case %d: ",k);k++;
        scanf("%d%d",&m,&n);
 
        memset(vis,0,sizeof(vis));
 
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>mp[i][j];
 
                if(mp[i][j]=='@')
                    u=i,v=j;
            }
        }
 
        dfs(u,v);
 
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(vis[i][j])
                    cnt++;
            }
        }
 
        cout<<cnt<<endl;
    }
 
    return 0;
}

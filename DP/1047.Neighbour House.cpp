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
#define N 25

using namespace std;

int dp[N][3];
int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int t,n,m;
    int r,g,b;

    scanf("%d",&t);

    k=1;
    while(t--)
    {
        printf("Case %d: ",k);k++;

        scanf("%d",&n);

        scanf("%d%d%d",&r,&g,&b);
        dp[1][0]=r;dp[1][1]=g;dp[1][2]=b;

        for(i=2;i<=n;i++)
        {
            scanf("%d%d%d",&r,&g,&b);

            //paint red
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+r;

            //paint green
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+g;

            //paint blue
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+b;
        }

        printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
    }

    return 0;
}


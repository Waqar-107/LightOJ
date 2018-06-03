/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 150

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m,t;
    ull sum;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        printf("Case %d: ",i);

        cin>>n;sum=0;
        while(n--)
        {
            cin>>m;

            if(m>0)
                sum+=m;
        }

        cout<<sum<<endl;
    }


    return 0;
}

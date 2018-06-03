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
    int p,q;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";

        cin>>n>>p>>q;

        //at most q gram, and p eggs
        int a[n];
        for(j=0;j<n;j++)
            cin>>a[j];

        int ans=0;k=0;
        while(q>0)
        {
            if(ans>=n || ans>=p)
                break;

            if(q<a[k])
                break;

            q-=a[k];ans++;k++;
        }

        cout<<ans<<endl;
    }


    return 0;
}

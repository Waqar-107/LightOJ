/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 100100
#define inf 10000000000000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d\n",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<ll,int>

using namespace std;

char str[N];
int tree[N*4], lazy[N*4];

void build(int at,int L,int R)
{
    if(L==R){
        tree[at]=str[L-1]-'0';
        return;
    }

    int mid=(L+R)/2;

    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
}

void query(int at,int L,int R,int idx)
{
    if(R<idx || idx<L) return;

    //resolve pending
    if(L==R)
    {
        tree[at]+=lazy[at]%2; lazy[at]=0;

        if(L==idx)
            pf(tree[at]%2), pfs("\n");

        return;
    }

    if(lazy[at])
    {
        lazy[at*2]+=lazy[at];
        lazy[at*2+1]+=lazy[at];
        lazy[at]=0;
    }

    int mid=(L+R)/2;

    query(at*2,L,mid,idx);
    query(at*2+1,mid+1,R,idx);
}

void update(int at,int L,int R,int l,int r)
{
    if(R<l || r<L) return;

    if(l<=L && R<=r)
    {
        lazy[at]++;
        //cout<<lazy[at]<<" "<<L<<" "<<R<<" "<<l<<" "<<r;nl
        return;
    }

    if(L==R) return;

    int mid=(L+R)/2;

    update(at*2,L,mid,l,r);
    update(at*2+1,mid+1,R,l,r);
}

void solve()
{
    int i,j,k;
    int n,len;
    char ch[5];

    scanf("%s",str); len=strlen(str);
    build(1,1,len);

    sf(n);
    while(n--)
    {
        scanf("%s",ch);

        if(ch[0]=='Q')
        {
            sf(k);
            query(1,1,len,k);
        }

        else
        {
            sff(j,k);
            update(1,1,len,j,k);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int i,j,k;
    int n,m;

    sf(n);
    for(i=1;i<=n;i++)
    {
        printf("Case %d:\n",i);

        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));

        solve();
    }

    return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1080

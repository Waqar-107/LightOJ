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
#define N 1001
#define inf 1000000000
#define pp pair<int,int>

using namespace std;

bool cmp(pp a,pp b)
{
    if(a.second==b.second)
        return a.first>b.first;

    return a.second<b.second;
}

int cnt(int n)
{
    int sq=sqrt(n);
    set<int> s;

    for(int i=1;i<=sq;i++)
    {
        if(n%i==0)
            s.insert(i),s.insert(n/i);
    }

    return s.size();
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m,t;

    vector<pp> v;

    n=1000;
    for(i=1;i<=n;i++)
        v.push_back({i,cnt(i)});

    sort(v.begin(),v.end(),cmp);

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,v[n-1].first);
    }

    return 0;
}

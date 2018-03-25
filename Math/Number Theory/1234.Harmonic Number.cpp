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

int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m,t;

    vector<double> v;

    n=100000000;
    double sum=0;v.push_back(0);
    for(i=1;i<=n;i++)
    {
        sum+=(1.0/i);

        if(i%1000==0)
            v.push_back(sum);
    }

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);

        m=n/1000;
        sum=v[m];k=m;

        for(j=1+k*1000;j<=n;j++)
            sum+=(1.0/j);

        printf("Case %d: %.10f\n",i,sum);
    }

    return 0;
}

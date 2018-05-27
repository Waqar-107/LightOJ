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
#define N 1100
#define pi acos(-1.0)

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m;
    double r1,r2,h,p,v;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Case %d: ",i);

        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);

        r1=r2+((r1-r2)*p)/h;
        v=(pi*p*(r1*r1+r1*r2+r2*r2))/3.0;

        cout<<setprecision(15)<<v;nl
        //printf("%lf\n",v);
    }

    return 0;
}

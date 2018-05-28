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
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m;

    double a,b,c,d;
    double x,h,area;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        printf("Case %d: ",i);

        cin>>a>>b>>c>>d;

        x=(a-c)*(a-c)+d*d-b*b;
        x=x/(2.0*(a-c));

        h=d*d-x*x;
        h=sqrt(h);

        area=0.5*(a+c)*h;
        cout<<setprecision(10)<<area<<endl;
    }

    return 0;
}

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

    double ox,oy,r;
    double ax,ay,theta;
    double bx,by,ans;
    double a,b,c;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        printf("Case %d: ",i);

        cin>>ox>>oy>>ax>>ay>>bx>>by;

        r=(ox-ax)*(ox-ax)+(oy-ay)*(oy-ay);
        r=sqrt(r);

        //arc length s=r*theta, theta in radian
        c=sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
        a=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        b=sqrt((ox-bx)*(ox-bx)+(oy-by)*(oy-by));

        theta=acos((b*b+a*a-c*c)/(2*b*a));
        ans=a*theta;

        cout<<setprecision(15)<<ans<<endl;
    }

    return 0;
}

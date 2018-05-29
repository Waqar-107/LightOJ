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

    int ax,bx,cx,dx;
    int ay,by,cy,dy;
    int area;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        printf("Case %d: ",i);

        cin>>ax>>ay;
        cin>>bx>>by;
        cin>>cx>>cy;

        dx=cx-(bx-ax);
        dy=cy-(by-ay);
        cout<<dx<<" "<<dy<<" ";

        area=(ax*by+bx*cy+cx*dy+dx*ay)-(ay*bx+by*cx+cy*dx+dy*ax);
        area=area/2;

        if(area<0)
            area*=(-1.0);

        cout<<area<<endl;
    }

    return 0;
}

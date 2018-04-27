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

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int t,n,m;
    int l,r;
    int x,y;

    scanf("%d",&t);

    k=1;
    while(t--)
    {
        printf("Case %d:\n",k);k++;

        scanf("%d%d",&n,&m);

        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        int high,low,mid;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);

            x=-1,y=-1;

            //for r
            high=n-1,low=0;
            while(low<=high)
            {
                mid=(high+low)/2;

                if(a[mid]==r)
                {
                    y=mid;
                    break;
                }

                if(a[mid]>r)
                    high=mid-1;
                else
                    y=max(y,mid),low=mid+1;
            }

            //for l
            high=y,low=0;
            while(low<=high)
            {
                mid=(high+low)/2;

                if(a[mid]==l)
                {
                    x=mid;
                    break;
                }

                if(a[mid]<l)
                    low=mid+1;
                else
                {
                    if(x==-1)
                        x=mid;
                    else
                        x=min(x,mid);
                    high=mid-1;
                }
            }

            //cout<<y<<" "<<x;nl
            if(x>=0 && y>=0 && y>=x)
                printf("%d\n",y-x+1);
            else
                printf("0\n");
        }
    }

    return 0;
}


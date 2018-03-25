#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

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
    int x,y;
    int p,l,t;

    scanf("%d",&t);

    for(i=1; i<=t; i++)
    {
        printf("Case %d: ",i);
        scanf("%d%d",&p,&l);

        x=p-l;
        y=sqrt(x);
        set<int> s;

        for(j=1; j<=y; j++)
        {
            if(x%j==0)
            {
                if(l<j)
                    s.insert(j);

                if(l<x/j)
                    s.insert(x/j);
            }
        }

        if(s.size()==0)
            printf("impossible\n");

        else
        {
            set<int>::iterator it=s.begin();
            while(it!=s.end())
            {
                printf("%d",*it++);
                if(it!=s.end())
                    printf(" ");
            }

            printf("\n");
        }
    }

    return 0;
}

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
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 510
#define inf 1000000

using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;

    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);

        scanf("%d%d",&n,&m);

        string t="";
        for(j=0;j<n;j++)
            t+=s[j];

        do{
            cout<<t<<endl;

            m--;
            if(!m)
                break;

        }while(next_permutation(t.begin(),t.end()));
    }

    return 0;
}

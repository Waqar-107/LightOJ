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
#define N 100010
#define inf 1000000

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int i,j,k;
    int t,n,m;
    string s;

    cin>>t;k=1;
    while(t--)
    {
        printf("Case %d:\n",k);k++;

        cin>>n;

        int cnt=0;
        while(n--)
        {
            cin>>s;
            if(s=="donate")
                cin>>m,cnt+=m;
            else
                cout<<cnt<<endl;
        }
    }

    return 0;
}

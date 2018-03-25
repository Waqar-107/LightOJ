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

    ll i,j,k;
    ll n,m,t,b;
    string a;

    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a;
        cin>>b;

        k=0;
        if(a[0]=='-')
            k=1;

        n=a.length();

        ll d=0;
        for(; k<n; k++)
        {
            d=d*10+(a[k]-'0');
            d=d%b;
        }

        printf("Case %lld: ",i);
        if (d)
            cout << "not divisible" << endl;
        else
            cout << "divisible" << endl;
    }

    return 0;
}

#include<bits/stdc++.h>

#define dbg printf("in\n");
#define nl printf("\n");

using namespace std;

struct edge
{
    int u,v,w;

    edge(){}
    edge(int x,int y,int z)
    {
        u=x;v=y;w=z;
    }
};

class DisjointSetUnion
{
    int n;
    int *p,*r;

public:
    DisjointSetUnion(int x)
    {
        n=x;

        p=new int[n+1];
        r=new int[n+1];

        for(int i=1;i<=n;i++)
            p[i]=i;

        memset(r,0,sizeof(r));
    }

    void Union(int x,int y)
    {
        int a=p[x];
        int b=p[y];

        if(r[a]>r[b])
        {
            p[b]=a;
            r[a]=max(r[a],r[b]+1);
        }

        else
        {
            p[a]=b;
            r[b]=max(r[b],r[b]+1);
        }
    }

    int Find(int a)
    {
        if(p[a]==a)
            return a;

        return p[a]=Find(p[a]);
    }
};

bool cmp(edge u,edge v)
{
    return u.w<v.w;
}

bool cmp2(edge u,edge v)
{
    return u.w>v.w;
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j,k;
    int n,m,t;
    int u,v,w;

    scanf("%d",&t);

    j=1;
    while(t--)
    {
        scanf("%d",&n);
        DisjointSetUnion dsu(n+1);

        vector<edge> a;
        while(1)
        {
            scanf("%d%d%d",&u,&v,&w);

            if(!u && !v && !w)
                break;

            u++,v++;
            a.push_back(edge(u,v,w));
        }

        //-------------------------------------------------min
        sort(a.begin(),a.end(),cmp);

        int min_sum=0;
        for(i=0; i<a.size(); i++)
        {
            if(dsu.Find(a[i].u)!=dsu.Find(a[i].v))
            {
                min_sum+=a[i].w;
                dsu.Union(a[i].u,a[i].v);
            }
        }
        //-------------------------------------------------min

        //-------------------------------------------------max
        sort(a.begin(),a.end(),cmp2);
        DisjointSetUnion dsu2(n+1);

        int max_sum=0;
        for(i=0; i<a.size(); i++)
        {
            if(dsu2.Find(a[i].u)!=dsu2.Find(a[i].v))
            {
                max_sum+=a[i].w;
                dsu2.Union(a[i].u,a[i].v);
            }
        }
        //-------------------------------------------------min

        k=min_sum+max_sum;
        if(k%2)
            printf("Case %d: %d/2\n",j,k);
        else
            printf("Case %d: %d\n",j,k/2);

        j++;
    }

    return 0;
}

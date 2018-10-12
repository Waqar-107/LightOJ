#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
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
#define nl printf("\n")
#define N 35
#define inf 1000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pff(n,m) printf("%d %d\n",n,m)
#define pffl(n,m) printf("%I64d %I64d\n",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

struct trieNode
{
	bool end;
	trieNode *next[10];
	trieNode() 
	{
		end = false;
		for (int i = 0; i < 10; i++)
			next[i] = NULL;
	}
};

string s;
bool ans;
class trie
{
	trieNode *root;
	void fr(trieNode *curr)
	{
		for (int i = 0; i < 10; i++)
		{
			if (curr->next[i])
				fr(curr->next[i]);
		}

		delete(curr);
	}

public:
	trie() {
		root = new trieNode();
	}

	void insertWord()
	{
		trieNode *curr = root;
		
		int n = s.length(), id;
		for (int i = 0; i < n; i++)
		{
			id = s[i] - '0';

			if (curr->next[id] == NULL)
				curr->next[id] = new trieNode();

			curr = curr->next[id];

			//123456 inserted after 123
			if (curr->end)
				ans = false;
		}

		curr->end = true;

		//123 inserted after 123456
		for (int i = 0; i < 10; i++)
		{
			if (curr->next[i] != NULL) {
				ans = false;
				break;
			}
		}
	}

	void freeMem() {
		fr(root);
	}
};

int main()
{
	freopen("in2.txt", "r", stdin);
	
	int i, j, k;
	int n, t;
	
	sf(t); 
	for (i = 1; i <= t; i++)
	{
		printf("Case %d: ", i);

		trie tr;
		sf(n);

		ans = 1;
		while (n--)
		{
			cin >> s;
			tr.insertWord();
		}

		if (ans)
			printf("YES\n");
		else
			printf("NO\n");

		tr.freeMem();
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i, j, k;
	int n, m;
	char s[110], t[110];

	scanf("%d\n", &n);
	
	for (j = 1; j <= n; j++) 
	{
		gets(s);
		gets(t);
		
		printf("Case %d:", j);
        
        int cnt=0,cnt2=0;
        
		m = strlen(s);
		for (i = 0; i < m; i++) {
			s[i] = tolower(s[i]);
			
			if(s[i]!=' ')
			    cnt+=s[i];
		}

		m = strlen(t);
		for (i = 0; i < m; i++) {
		    t[i] = tolower(t[i]);
		    
		    if(t[i]!=' ')
		        cnt2+=t[i];   
		}

		if (cnt==cnt2)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

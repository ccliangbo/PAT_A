#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	char s[81];
	scanf("%s",s);
	int len;
	len=strlen(s);
	int n1,n2;
	for(n2=3;n2<=len;n2++)
	{
		if((len+2-n2)%2!=0 )
			continue;
		n1=(len+2-n2)/2;
		if(n1<=n2)
			break;
	}
	int i,j;
	int pos=0;
	for(i=0;i<n1-1;i++)
	{
		putchar(s[i]);
		for(j=0;j<n2-2;j++)
			putchar(' ');
		putchar(s[len-1-i]);
		putchar('\n');
	}
	for(i=0;i<n2;i++)
		putchar(s[n1-1+i]);
	return 0;
}

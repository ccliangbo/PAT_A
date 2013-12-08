#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

class R{
public:
	int next;
	int tag;
};
R a[100000];
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int i,n,h1,h2;
	int from,to;
	char dummy[2];
	scanf("%d%d%d",&h1,&h2,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&from,dummy,&to);
		a[from].next=to;
		a[from].tag=0;
	}
	while(h1!=-1 && h2!=-1)
	{
		
		if(a[h1].tag==2)
		{
			printf("%05d",h1);
			return 0;
		}
		a[h1].tag=1;
		h1=a[h1].next;
		if(a[h2].tag==1)
		{
			printf("%05d",h2);
			return 0;
		}
		a[h2].tag=2;
		h2=a[h2].next;
	}
	while(h1!=-1)
	{
		if(a[h1].tag==2)
		{
			printf("%05d",h1);
			return 0;
		}
		a[h1].tag=1;
		h1=a[h1].next;
	}
	while(h2!=-1)
	{
		if(a[h2].tag==1)
		{
			printf("%05d",h2);
			return 0;
		}
		a[h2].tag=2;
		h2=a[h2].next;
	}
	printf("-1");
	return 0;
}

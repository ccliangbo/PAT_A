#include<stdio.h>

int a[100001];
int b[100001];
int d[100001];
int n;
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	a[1]=0;
	for(i=2;i<=n;i++)
		a[i]=a[i-1]+d[i-1];
	b[n]=d[n];
	for(i=n-1;i>=1;i--)
		b[i]=b[i+1]+d[i];
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		int from,to;
		scanf("%d%d",&from,&to);
		if(from>to)
		{
			int t;
			t=from;
			from=to;
			to=t;
		}
		int t0,nt0;
		nt0=a[to]-a[from];
		t0=a[from]+b[to];
		if(nt0<t0)
			printf("%d\n",nt0);
		else
			printf("%d\n",t0);
	}
	return 0;
}

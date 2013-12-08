#include<stdio.h>

int n,m,l;
int a[10001];
int b[10001];
int dict[201];
int binS(int max,int x)
{
	int from=1;
	int to=max-1;
	int m;
	while(from<to)
	{
		m=(from+to)/2;
		if(m<=x)
		{
			from=m+1;
		}
		else
			to=m-1;
	}
	return from-1;
}
int linS(int max,int x)
{
	int i=1;
	while(b[i]<=x)
		i++;
	return i-1;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		dict[i]=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		dict[t]=i;
	}
	int rl=0;
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		int t;
		scanf("%d",&t);
		if(dict[t]>0)
		{
			a[rl++]=dict[t];
		}
	}
	//for(i=0;i<rl;i++) printf("%d ",a[i]);printf("\n");
	int max=1;
	b[1]=a[0];
	for(i = 1; i<rl;i++)
	{
		if(a[i]>=b[max])
		{
			max++;
			b[max]=a[i];
		}
		else
		{
			int j=linS(max,a[i]);
			b[j+1]=a[i];
		}
	}
	printf("%d",max);
	return 0;
}

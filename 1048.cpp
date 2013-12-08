#include<stdio.h>

int main()
{
	int b[1001];
	int i;
	for(i=1;i<=1000;i++)
		b[i]=0;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		b[t]++;
	}
	for(i=1;i<=m/2;i++)
	{
		if(i != m-i && b[i] > 0 && b[m-i]> 0)
		{
			printf("%d %d",i,m-i);
			return 0;
		}
		if(i == m-i && b[i]>=2)
		{
			printf("%d %d",i,m-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}

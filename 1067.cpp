#include<stdio.h>
#define DEBUG
int a[100000];
int dict[100000];
int main()
{
	int n,i,p;
	int count=0;
	int wellp=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		a[i]=t;
		dict[t]=i;
	}
	for(i=0;i<n;i++)
		if(a[i]==0)
		{
			p=i;
			break;
		}
#ifdef DEBUG
printf("a:\n");
for(i=0;i<10;i++)
	printf("%d ",a[i]);
printf("\n");
printf("dict:\n");
for(i=0;i<10;i++)
	printf("%d ",dict[i]);
printf("\n");
printf("p=%d\n",p);
printf("\n");
#endif
	while(wellp<n)
	{
		while(p!=0)
		{
			i=dict[p];
			a[p]=p;
			dict[p]=p;
			p=i;
			dict[0]=i;
			a[i]=0;
			count++;
#ifdef DEBUG
printf("a:\n");
for(i=0;i<10;i++)
	printf("%d ",a[i]);
printf("\n");
printf("dict:\n");
for(i=0;i<10;i++)
	printf("%d ",dict[i]);
printf("\n");
printf("p=%d\n",p);
printf("\n");
#endif
		}
		while(wellp<n && a[wellp]==wellp)
			wellp++;
		if(wellp<n)
		{
			a[0]=a[wellp];
			dict[a[wellp]]=0;
			p=wellp;
			dict[0]=p;
			a[p]=0;
			count++;
#ifdef DEBUG
printf("a:\n");
for(i=0;i<10;i++)
	printf("%d ",a[i]);
printf("\n");
printf("dict:\n");
for(i=0;i<10;i++)
	printf("%d ",dict[i]);
printf("\n");
printf("p=%d\n",p);
printf("\n");
#endif
		}
	}
	printf("%d",count);
	return 0;
}

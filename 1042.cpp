#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,k,j;
	int a[55];
	int b[55];
	int r[55];
	scanf("%d",&k);
	for(i=1;i<=54;i++)
		scanf("%d",&r[i]);
	for(i=1;i<=54;i++)
		a[i]=i;
	for(i=0;i<k;i++)
	{
		for(j=1;j<=54;j++)
			b[r[j]]=a[j];
		for(j=1;j<=54;j++)
			a[j]=b[j];
	}
	for(i=1;i<=53;i++)
	{
		if(a[i]<=13)
			printf("S%d ",a[i]);
		else if(a[i]<=26)
			printf("H%d ",a[i]-13);
		else if(a[i]<=39)
			printf("C%d ",a[i]-26);
		else if(a[i]<=52)
			printf("D%d ",a[i]-39);
		else
			printf("J%d ",a[i]-52);
	}
	if(a[i]<=13)
		printf("S%d",a[i]);
	else if(a[i]<=26)
		printf("H%d",a[i]-13);
	else if(a[i]<=39)
		printf("C%d",a[i]-26);
	else if(a[i]<=52)
		printf("D%d",a[i]-39);
	else
		printf("J%d",a[i]-52);
	return 0;
}
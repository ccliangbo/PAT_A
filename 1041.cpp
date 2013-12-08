#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int bucket[10001];
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,n,t;
	scanf("%d",&n);
	for(i=1;i<=10000;i++)
		bucket[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(bucket[t]==0)
			bucket[t]=i;
		else
			bucket[t]=-1;
	}
	int min=0;
	bucket[0]=100001;
	for(i=1;i<=10000;i++)
		if(bucket[i]>0 && bucket[i]<bucket[min])
			min=i;
	if(min==0)
		printf("None");
	else
		printf("%d",min);
	return 0;
}
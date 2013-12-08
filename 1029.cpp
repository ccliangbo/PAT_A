#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

long a[1000000];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	
	int m,n,i,j,me;
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%ld",&a[i]);
	scanf("%d",&n);
	me=n+m;
	if(me %2 == 0)
		me=me/2;
	else
		me=me/2+1;
	int count=0;
	j=0;
	long front;
	scanf("%ld",&front);
	i=0;
	while(count<me-1)
	{
		if(j<n && i<m)
		{
			if(front<a[i])
			{
				if(j<n-1)
					scanf("%ld",&front);
				j++;
				count++;
			}
			else
			{
				i++;
				count++;
			}
		}
		else if(j==n)
		{
			i++;
			count++;
		}
		else
		{
			if(j<n-1)
					scanf("%ld",&front);
				j++;
				count++;
		}
	}
	if(j<n && i<m)
	{
		if(front<a[i])
		{
			printf("%ld",front);
		}
		else
		{
			printf("%ld",a[i]);
		}
	}
	else if(j==n)
	{
		printf("%ld",a[i]);
	}
	else
	{
		printf("%ld",front);
	}
	return 0;
}

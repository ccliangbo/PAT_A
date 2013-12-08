#include<stdio.h>
#include<string.h>

int main()
{
	int time;
	scanf("%d",&time);
	for(int repeat=1;repeat<=time;repeat++)
	{
		long long int a,b,c,t;
		scanf("%lld%lld%lld",&a,&b,&c);
		t=a+b;
		if(a>0 && b>0 && t<=0)
			printf("Case #%d: true\n",repeat);
		else if(a<0 && b<0 && t>=0)
			printf("Case #%d: false\n",repeat);
		else
		{
			if(t>c)
				printf("Case #%d: true\n",repeat);
			else
				printf("Case #%d: false\n",repeat);
		}
	}
	return 0;
}

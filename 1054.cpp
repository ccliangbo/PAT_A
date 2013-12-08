#include<stdio.h>

int main()
{
	int fre=0;
	int can=-1;
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			int t;
			scanf("%d",&t);
			if(fre==0)
			{
				fre=1;
				can=t;
			}
			else if(can == t)
				fre++;
			else
				fre--;
		}
	printf("%d",can);
}

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#undef DEBUG



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int i,high,low;
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	printf("#");
	for(i=0;i<3;i++)
	{
		high=a[i]/13;
		low=a[i]%13;
		if(high>=10)
			printf("%c",high-10+'A');
		else
			printf("%d",high);
		if(low>=10)
			printf("%c",low-10+'A');
		else
			printf("%d",low);
	}
	return 0;
}

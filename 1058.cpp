#include<stdio.h>
int main()
{
	int ag,as,ak,bg,bs,bk;
	scanf("%d.%d.%d%d.%d.%d",&ag,&as,&ak,&bg,&bs,&bk);
	//printf("%d.%d.%d\n",ag,as,ak);
	//printf("%d.%d.%d\n",bg,bs,bk);
	ag+=bg;
	as+=bs;
	ak+=bk;
	//printf("%d.%d.%d\n",ag,as,ak);
	if(ak>=29)
	{
		as++;
		ak=ak%29;
	}
	if(as>=17)
	{
		ag++;
		as=as%17;
	}
	printf("%d.%d.%d",ag,as,ak);
	return 0;
}

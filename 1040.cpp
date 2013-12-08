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
	char buffer[1001];
	gets(buffer);
	int len=strlen(buffer);
	int max=1;
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=1;i-j>=0 && i+j<len;j++)
			if(buffer[i-j]!=buffer[i+j])
				break;
		if((j-1)*2+1>max)
			max=(j-1)*2+1;
	}
	double p,r;
	for(p=0.5;p<len;p=p+1)
	{
		for(r=0.5;p-r>=0 && p+r<len;r=r+1)
			if(buffer[(int)(p-r)]!=buffer[(int)(p+r)])
				break;
		if((p+r)-(p-r)-1>max)
			max=(int)((p+r)-(p-r)-1);
	}
	printf("%d",max);
	return 0;
}
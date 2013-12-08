#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<string.h>

using namespace std;

#undef DEBUG

class Big
{
public:
	int a[200];
	int b[200];
	int len;
	void read(char s[])
	{
		int i;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			a[i]=s[len-i-1]-'0';
		}
	}
	void gen()
	{
		int i;
		for(i=0;i<len;i++)
			b[i]=a[len-i-1];
	}
	bool check()
	{
		gen();
		int i;
		for(i=0;i<len;i++)
			if(a[i]!=b[i])
				return false;
		return true;
	}

	void add()
	{
		int i;
		a[len]=0;
		for(i=0;i<len;i++)
			a[i]=a[i]+b[i];
		for(i=0;i<len;i++)
			if(a[i]>=10)
			{
				a[i]=a[i]%10;
				a[i+1]++;
			}
		if(a[len]!=0)
			len++;
	}
	void print()
	{
		for(int i=len-1;i>=0;i--)
			printf("%d",a[i]);
	}
};
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	char buffer[30];
	int k;
	scanf("%s%d",buffer,&k);
	Big b;
	b.read(buffer);
	int step=0;
	while(step<k)
	{
		if(b.check())
			break;
		else
		{
			b.add();
			step++;
		}
	}
	b.print();
	printf("\n%d",step);
	return 0;
}

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
	int a[30];
	int len;
	int newlen;
	int bucket1[10];
	int bucket2[10];
	void read(char s[])
	{
		int i;
		for(i=0;i<10;i++)
			bucket1[i]=0;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			a[i]=s[len-i-1]-'0';
			bucket1[a[i]]++;
		}
	}
	void dub()
	{
		int i;
		for(i=0;i<len;i++)
		{
			a[i]*=2;
		}
		a[len]=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>=10)
			{
				a[i]=a[i]%10;
				a[i+1]++;
			}
		}
		if(a[len] !=0)
			newlen=len+1;
		else
			newlen=len;
		for(i=0;i<10;i++)
			bucket2[i]=0;
		for(i=0;i<newlen;i++)
			bucket2[a[i]]++;
	}

	bool check()
	{
		for(int i=0;i<10;i++)
			if(bucket1[i]!=bucket2[i])
				return false;
		return true;
	}

	void print()
	{
		for(int i=newlen-1;i>=0;i--)
			printf("%d",a[i]);
	}
};
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	char buffer[30];
	scanf("%s",buffer);
	Big b;
	b.read(buffer);
	b.dub();
	if(b.check())
		printf("Yes\n");
	else
		printf("No\n");
	b.print();
	return 0;
}

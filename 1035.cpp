#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Node
{
public:
	char a[11];
	char p[11];
};
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,m,i;
	vector<Node> v;
	char s1[11];
	char s2[11];
	scanf("%d",&n);
	m=0;
	for(i=0;i<n;i++)
	{
		bool change=false;
		scanf("%s%s",s1,s2);
		for(int j=0;j<strlen(s2);j++)
		{
			if(s2[j]=='1')
			{
				change=true;
				s2[j]='@';
				continue;
			}
			if(s2[j]=='0')
			{
				change=true;
				s2[j]='%';
				continue;
			}
			if(s2[j]=='l')
			{
				change=true;
				s2[j]='L';
				continue;
			}
			if(s2[j]=='O')
			{
				change=true;
				s2[j]='o';
				continue;
			}
		}
		if(change)
		{
			Node r;
			strcpy(r.a,s1);
			strcpy(r.p,s2);
			v.push_back(r);
		}
	}
	if(v.size()==0)
	{
		if(n==1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified",n);
	}
	else
	{
		printf("%d\n",v.size());
		for(i=0;i<v.size();i++)
		{
			printf("%s %s\n",v[i].a,v[i].p);
		}
	}
	return 0;
}
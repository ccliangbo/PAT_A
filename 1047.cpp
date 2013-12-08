#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
class Name{
public:
	char name[5];
	bool operator < (const Name & right) const
	{
		if(strcmp(name,right.name) < 0)
			return true;
		return false;
	}
};
int main()
{
	int n,k;
	vector<Name> v[2501];
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
	{
		char name[5];
		int nc;
		scanf("%s%d",name,&nc);
		for(int j=0;j<nc;j++)
		{
			int c;
			scanf("%d",&c);
			Name na;
			strcpy(na.name,name);
			v[c].push_back(na);
		}
	}
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",i,v[i].size());
		sort(v[i].begin(),v[i].end());
		for(unsigned int j=0;j<v[i].size();j++)
			printf("%s\n",v[i][j].name);
	}
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

vector<int> stu[26*26*26*10];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int count=0;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int index,nj;
		scanf("%d%d",&index,&nj);
		for(int j=0;j<nj;j++)
		{
			char name[5];
			scanf("%s",name);
			int base=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
			stu[base].push_back(index);
		}
	}
	for(int i=0;i<n;i++)
	{
		char name[5];
		scanf("%s",name);
		int base=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
		if(stu[base].size()>0)
		{
			sort(stu[base].begin(),stu[base].end());
			printf("%s %d",name,stu[base].size());
			for(int j=0;j<stu[base].size();j++)
				printf(" %d",stu[base][j]);
			printf("\n");
		}
		else
			printf("%s 0\n",name);
	}
	return 0;
}
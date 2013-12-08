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
	char name[11];
	char id[11];
	int grade;
	bool operator<(const Node & right) const
	{
		return grade<right.grade;
	}
};
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	vector<Node> mv;
	vector<Node> fv;
	for(i=0;i<n;i++)
	{
		char name[11];
		char id[11];
		char gender[2];
		int grade;
		scanf("%s%s%s%d",name,gender,id,&grade);
		if(strcmp(gender,"M") == 0)
		{
			Node r;
			strcpy(r.id,id);
			strcpy(r.name,name);
			r.grade=grade;
			mv.push_back(r);
		}
		else
		{
			Node r;
			strcpy(r.id,id);
			strcpy(r.name,name);
			r.grade=grade;
			fv.push_back(r);
		}
	}
	bool haveM,haveF;
	int max,min;
	if(fv.size()==0)
	{
		haveF=false;
		printf("Absent\n");
	}
	else
	{
		haveF=true;
		sort(fv.begin(),fv.end());
		max=fv[fv.size()-1].grade;
		printf("%s %s\n",fv[fv.size()-1].name,fv[fv.size()-1].id);
	}
	if(mv.size()==0)
	{
		haveM=false;
		printf("Absent\n");
	}
	else
	{
		haveM=true;
		sort(mv.begin(),mv.end());
		min=mv[0].grade;
		printf("%s %s\n",mv[0].name,mv[0].id);
	}
	if(haveM && haveF)
		printf("%d",max-min);
	else
		printf("NA");
	return 0;
}
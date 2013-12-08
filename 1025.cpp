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

class Record
{
public:
	char id[20];
	int score;
	int localR;
	int totalR;
	int location;
	bool operator < (const Record& r) const
	{
		if(score>r.score)
			return true;
		if(score == r.score && strcmp(id,r.id)<0)
			return true;
		return false;
	}
};


int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int n,i,k,j;
	scanf("%d",&n);
	vector<Record> tv;
	vector<Record> v;
	int totalNumber=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		totalNumber+=k;
		v.clear();
		for(j=0;j<k;j++)
		{
			Record r;
			scanf("%s%d",r.id,&r.score);
			r.location=i+1;
			v.push_back(r);
		}
		sort(v.begin(),v.end());
		int crank,lastScore;
		crank=0;
		lastScore=-1;
		for(j=0;j<k;j++)
		{
			if(lastScore!=v[j].score)
			{
				crank=j+1;
				lastScore=v[j].score;
			}
			v[j].localR=crank;
		}
		tv.insert(tv.end(),v.begin(),v.end());
	}
	sort(tv.begin(),tv.end());
	int crank,lastScore;
	crank=0;
	lastScore=-1;
	printf("%d\n",totalNumber);
	for(j=0;j<totalNumber;j++)
	{
		if(lastScore!=tv[j].score)
		{
			crank=j+1;
			lastScore=tv[j].score;
		}
		tv[j].totalR=crank;
		printf("%s %d %d %d\n",tv[j].id,tv[j].totalR,tv[j].location,tv[j].localR);
	}
	return 0;
}

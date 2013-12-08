#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

class Record{
public:
	char id[10];
	char name[10];
	int score;
};

bool less_1(const Record & x, const Record & y)
{
	if(strcmp(x.id,y.id)<0)
		return true;
	return false;
}

bool less_2(const Record & x, const Record & y)
{
	if(strcmp(x.name,y.name)<0)
		return true;
	else if(strcmp(x.name,y.name)>0)
		return false;
	if(strcmp(x.id,y.id)<0)
		return true;
	return false;
}

bool less_3(const Record & x, const Record & y)
{
	if(x.score<y.score)
		return true;
	else if(x.score>y.score)
		return false;
	if(strcmp(x.id,y.id)<0)
		return true;
	return false;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int n,c;
	scanf("%d%d",&n,&c);
	vector<Record> v;
	v.reserve(n);
	int i;
	for(i=0;i<n;i++)
	{
		Record r;
		scanf("%s%s%d",r.id,r.name,&r.score);
		v.push_back(r);
	}
	if(c==1)
		sort(v.begin(),v.end(),less_1);
	else if(c==2)
		sort(v.begin(),v.end(),less_2);
	else
		sort(v.begin(),v.end(),less_3);
	for(i=0;i<n;i++)
	{
		printf("%s %s %d\n",v[i].id,v[i].name,v[i].score);
	}
	return 0;
}

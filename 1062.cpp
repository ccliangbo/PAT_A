#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define DEBUG
class People{
public:
	int id;
	int v;
	int t;
	bool operator<(const People & right) const
	{
		if(v+t>right.v+right.t)
			return true;
		if(v+t<right.v+right.t)
			return false;
		if(v>right.v)
			return true;
		if(v<right.v)
			return false;
		if(id<right.id)
			return true;
		else
			return false;
	}
};
int main()
{
	int n,l,h,m;
	m=0;
	scanf("%d%d%d",&n,&l,&h);
	int i;
	vector<People> sage;
	vector<People> noble;
	vector<People> fool;
	vector<People> small;
	for(i=0;i<n;i++)
	{
		int id,v,t;
		scanf("%d%d%d",&id,&v,&t);
		if(v<l || t <l )
			continue;
		People p;
		p.id=id;
		p.t=t;
		p.v=v;
		m++;
		if(v>=h && t>=h)
		{
			sage.push_back(p);
		}
		else if(t<h && v>=h)
			noble.push_back(p);
		else if(t<h && v<h && v>=t)
			fool.push_back(p);
		else
			small.push_back(p);
	}
	sort(sage.begin(),sage.end());
	sort(noble.begin(),noble.end());
	sort(fool.begin(),fool.end());
	sort(small.begin(),small.end());
	printf("%d\n",m);
#ifdef DEBUG
printf("begin sage\n");
#endif
	for(i=0;i<sage.size();i++)
		printf("%08d %d %d\n",sage[i].id, sage[i].v,sage[i].t);
#ifdef DEBUG
printf("begin noble\n");
#endif
	for(i=0;i<noble.size();i++)
		printf("%08d %d %d\n",noble[i].id, noble[i].v,noble[i].t);
#ifdef DEBUG
printf("begin fool\n");
#endif
	for(i=0;i<fool.size();i++)
		printf("%08d %d %d\n",fool[i].id, fool[i].v,fool[i].t);
#ifdef DEBUG
printf("begin small\n");
#endif
	for(i=0;i<small.size();i++)
		printf("%08d %d %d\n",small[i].id, small[i].v,small[i].t);
	return 0;
}

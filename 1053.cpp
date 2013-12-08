#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
public:
	int weight;
	vector<int> child;
};
Node a[100];
int path[100];
int n,m,s;
bool less_1(int x,int y)
{
	if (a[x].weight>a[y].weight)
		return true;
	return false;
}
void visit(int root,int weight,int level)
{
	//level means next block to fill in path[]
	if(weight == 0)
	{
		if(a[root].child.size()!=0)
			return;
		int i;
		for(i=0;i<level-1;i++)
			printf("%d ",a[path[i]].weight);
		printf("%d\n",a[path[level-1]].weight);
	}
	else
	{
		sort(a[root].child.begin(),a[root].child.end(),less_1);
		int i;
		for(i=0;i<a[root].child.size();i++)
		{
			if(weight >= a[a[root].child[i]].weight)
			{
				path[level]=a[root].child[i];
				visit(a[root].child[i],weight-a[a[root].child[i]].weight,level+1);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].weight);
	}
	for(i=0;i<m;i++)
	{
		int id,num;
		scanf("%d%d",&id,&num);
		for(j=0;j<num;j++)
		{
			int t;
			scanf("%d",&t);
			a[id].child.push_back(t);
		}
	}
	path[0]=0;
	visit(0,s-a[0].weight,1);
	return 0;
}

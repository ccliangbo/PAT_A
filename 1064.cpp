#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[1000];
int n;
vector<int> v;
int pos;
void visit(int root)
{
	if(root*2+1<n)
		visit(root*2+1);
	a[root]=v[pos++];
	if(root*2+2<n)
		visit(root*2+2);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	pos=0;
	visit(0);
	printf("%d",a[0]);
	for(i=1;i<n;i++)
		printf(" %d",a[i]);
	return 0;
}

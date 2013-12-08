#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//#define DEBUG
class Node{
public:
	int address;
	int key;
	int next;
	bool operator<(const Node & right) const
	{
		if(key<right.key)
			return true;
		return false;
	}
};
int main()
{
	Node memory[100000];
	int n,head;
	scanf("%d%d",&n,&head);
	int i;
	for(i=0;i<n;i++)
	{
		int a,k,next;
		scanf("%d%d%d",&a,&k,&next);
		memory[a].address=a;
		memory[a].key=k;
		memory[a].next=next;
	}
	vector<Node> v;
	int p;
	p=head;
	if(head == -1)
	{
		printf("0 -1\n");
		return 0;
	}
	while(p!=-1)
	{
		v.push_back(memory[p]);
		p=memory[p].next;
	}
#ifdef DEBUG
printf("before sort\n");
#endif
	sort(v.begin(),v.end());
#ifdef DEBUG
printf("after sort\n");
#endif
	printf("%d %05d\n",v.size(),v[0].address);
	for(i=0;i<v.size()-1;i++)
	{
		printf("%05d %d %05d\n",v[i].address,v[i].key,v[i+1].address);
	}
#ifdef DEBUG
printf("before last output\n");
#endif
	printf("%05d %d -1\n",v[v.size()-1].address,v[v.size()-1].key);
	return 0;
}

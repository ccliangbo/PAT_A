#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

#define DEBUG

int n;
int post[30];
int in[30];

class Node
{
public:
	int id;
	Node * left;
	Node * right;
};

Node * con(int postfrom, int postto, int infrom,int into)
{
	Node * r=new Node;
	r->id=post[postto];
	if(postto-postfrom == 0)
	{
		r->left=NULL;
		r->right=NULL;
	}
	else
	{
		int i;
		for(i=infrom;i<=into;i++)
			if(in[i]==post[postto])
				break;
		int lc,rc;
		lc=i-infrom;
		rc=into-i;
		if(lc>0)
			r->left=con(postfrom,postfrom+lc-1,infrom,i-1);
		else
			r->left=NULL;
		if(rc>0)
			r->right=con(postfrom+lc,postfrom+lc+rc-1,i+1,into);
		else
			r->right=NULL;
	}
	return r;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&post[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	Node * root=con(0,n-1,0,n-1);

	queue<Node *> q;
	q.push(root);
	bool first=true;
	while(q.size()!=0)
	{
		if(first)
		{
			printf("%d",q.front()->id);
			first=false;
		}
		else
			printf(" %d",q.front()->id);
		if(q.front()->left!=NULL)
			q.push(q.front()->left);
		if(q.front()->right!=NULL)
			q.push(q.front()->right);
		q.pop();
	}
	return 0;
}
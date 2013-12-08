#include<stdio.h>
//#define DEBUG
class Node{
public:
	int key;
	Node *left,*right;
};
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int getHeight(Node *root)
{
	if(root==NULL)
		return 0;
	return max(getHeight(root->left),getHeight(root->right))+1;
}
Node * turnRight(Node *root)
{
	Node * rootLeft=root->left;
	root->left=rootLeft->right;
	rootLeft->right=root;
	return rootLeft;
}
Node * turnLeft(Node *root)
{
	Node *rootRight=root->right;
	root->right=rootRight->left;
	rootRight->left=root;
	return rootRight;
}
Node *turnLeftRight(Node * root)
{
	root->left=turnLeft(root->left);
	return turnRight(root);
}
Node *turnRightLeft(Node *root)
{
	root->right=turnRight(root->right);
	return turnLeft(root);
}
Node *insert(Node *root, int key)
{
	if(root==NULL)
	{
		root= new Node;
		root->key=key;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(key<root->key)
		root->left=insert(root->left, key);
	else
		root->right=insert(root->right, key);
	if(getHeight(root->left)-getHeight(root->right)>=2)
	{
		Node *p=root->left;
		if(getHeight(p->left)>getHeight(p->right))
			root=turnRight(root);
		else
			root=turnLeftRight(root);
	}
	else if(getHeight(root->right)-getHeight(root->left)>=2)
	{
		Node *p=root->right;
		if(getHeight(p->right)>getHeight(p->left))
			root=turnLeft(root);
		else
			root=turnRightLeft(root);
	}
	return root;
}
int main()
{
	int n;
	Node *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
#ifdef DEBUG
printf("reading, i=%d, t=%d\n",i,t);
#endif
		root=insert(root,t);
	}
	printf("%d",root->key);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

//#define DEBUG
int a[1001];
int n;
bool firstOutput=true;
void tryBST(int from, int to)
{
#ifdef DEBUG
	printf("from=%d,to=%d\n",from,to);
#endif
	int i;
	for(i=from+1;i<=to;i++)
		if(a[i]>=a[from])
			break;
	int newRoot=i;
#ifdef DEBUG
	printf("newRoot=%d\n",newRoot);
#endif
	for(i=newRoot+1;i<=to;i++)
		if(a[i]<a[from])
		{
			//not a BST
			printf("NO");
			exit(0);
		}
	if(from+1<newRoot-1)
		tryBST(from+1,newRoot-1);
	if(newRoot<to)
		tryBST(newRoot,to);
}
void tryMirrorBST(int from, int to)
{
	int i;
	for(i=from+1;i<=to;i++)
		if(a[i]<a[from])
			break;
	int newRoot=i;
	for(i=newRoot+1;i<=to;i++)
		if(a[i]>=a[from])
		{
			//not a BST
			printf("NO");
			exit(0);
		}
	if(from+1<newRoot-1)
		tryMirrorBST(from+1,newRoot-1);
	if(newRoot<to)
		tryMirrorBST(newRoot,to);
}
void visitBST(int from, int to)
{
	int i;
	for(i=from+1;i<=to;i++)
		if(a[i]>=a[from])
			break;
	int newRoot=i;
	if(from+1<newRoot-1)
		visitBST(from+1,newRoot-1);
	if(from+1 == newRoot -1)
		if(firstOutput)
		{
			printf("%d",a[from+1]);
			firstOutput=false;
		}
	else
		printf(" %d",a[from+1]);
		
	if(newRoot<to)
		visitBST(newRoot,to);
	if(newRoot == to)
		if(firstOutput)
		{
			printf("%d",a[to]);
			firstOutput=false;
		}
	else
		printf(" %d",a[to]);
	if(firstOutput)
	{
		printf("%d",a[from]);
		firstOutput=false;
	}
	else
		printf(" %d",a[from]);
}
void visitMirrorBST(int from, int to)
{
	int i;
	for(i=from+1;i<=to;i++)
		if(a[i]<a[from])
			break;
	int newRoot=i;
	if(from+1<newRoot-1)
		visitMirrorBST(from+1,newRoot-1);
	if(from+1 == newRoot -1)
		if(firstOutput)
		{
			printf("%d",a[from+1]);
			firstOutput=false;
		}
	else
		printf(" %d",a[from+1]);
	if(newRoot<to)
		visitMirrorBST(newRoot,to);
	if(newRoot == to)
		if(firstOutput)
		{
			printf("%d",a[to]);
			firstOutput=false;
		}
	else
		printf(" %d",a[to]);
	if(firstOutput)
	{
		printf("%d",a[from]);
		firstOutput=false;
	}
	else
		printf(" %d",a[from]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(a[0]>a[1])
	{
		tryBST(0,n-1);
		printf("YES\n");
		visitBST(0,n-1);
	}
	else
	{
		tryMirrorBST(0,n-1);
		printf("YES\n");
		visitMirrorBST(0,n-1);
	}
	return 0;
}

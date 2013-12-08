#include<stdio.h>
#include<vector>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;
//#define DEBUG
int stack_top;
int bucket[100001];
int medP;
int medRank;
int findPre(int x)
{
	for(int i=x-1;i>=0;i--)
		if(bucket[i]>0)
			return i;
	return -1;
}
int findNext(int x)
{
	for(int i=x+1;i<=100001;i++)
		if(bucket[i]>0)
			return i;
	return -1;
}
void adjustMed()
{
#ifdef DEBUG
printf("begin to adjust, size=%d, medP=%d, medRank=%d\n",stack_top,medP,medRank);
#endif
	int r;
	if(stack_top%2 == 0)
		r=stack_top/2;
	else
		r=(stack_top+1)/2;
#ifdef DEBUG
printf("r=%d\n",r);
#endif
	if(medRank <= r && r <= medRank+bucket[medP]-1)
		;
	else if(medRank >r)
	{
		int newMedP=findPre(medP);
		int newMedRank=medRank-bucket[newMedP];
		medP=newMedP;
		medRank=newMedRank;
	}
	else
	{
		int newMedP=findNext(medP);
		int newMedRank=medRank+bucket[medP];
		medP=newMedP;
		medRank=newMedRank;
	}
#ifdef DEBUG
printf("end adjust, size=%d, medP=%d, medRank=%d\n",stack_top,medP,medRank);
#endif
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int s[100001];
	stack_top=0;
	for(i=0;i<100001;i++)
		bucket[i]=0;
	for(i=0;i<n;i++)
	{
		char command[20];
		scanf("%s",command);
#ifdef DEBUG
printf("i=%d, command=%s\n",i,command);
#endif
		if(strcmp(command,"Pop")==0)
		{
			if(stack_top==0)
			{
				printf("Invalid\n");
			}
			else
			{
				int t=s[stack_top];
				printf("%d\n",t);
				stack_top--;
				if(medP == t && bucket[medP] ==1 )
				{
					int newMedP=findPre(medP);
					int newMedRank=medRank-bucket[newMedP];
					medP=newMedP;
					medRank=newMedRank;
				}
				else if(medP > t)
				{
					medRank--;
				}
				bucket[t]--;
				adjustMed();
			}
		}
		else if(strcmp(command,"Push")==0)
		{
			int t;
			scanf("%d",&t);
			if(stack_top  == 0)
			{
				stack_top++;
				s[stack_top]=t;
				bucket[t]++;
				medP=t;
				medRank=1;
			}
			else
			{
				stack_top++;
				s[stack_top]=t;
				bucket[t]++;
				if(t<medP)
					medRank++;
				adjustMed();
			}
		}
		else if(strcmp(command,"PeekMedian")==0)
		{
			if(stack_top==0)
				printf("Invalid\n");
			else
			{
				printf("%d\n",medP);
			}
		}
		else
			printf("Invalid\n");
	}
	return 0;
}

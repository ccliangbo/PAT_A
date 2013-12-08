#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

//#define DEBUG
class Node
{
	public:
	char name[10];
	int age;
	int worth;
};
Node people[100001];
bool less_1(int x,int y)
{
	if(people[x].worth > people[y].worth)
		return true;
	else if(people[x].worth < people[y].worth)
		return false;
	if(strcmp(people[x].name,people[y].name) <0)
		return true;
	return false;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	vector<int> ageList[201];
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d",people[i].name,&(people[i].age),&(people[i].worth));
		if(ageList[people[i].age].size()<=100)
			ageList[people[i].age].push_back(i);
	}
	for(i=1;i<=200;i++)
		sort(ageList[i].begin(),ageList[i].end(),less_1);
	for(i=1;i<=k;i++)
	{
		int m,min,max;
		scanf("%d%d%d",&m,&min,&max);
		printf("Case #%d:\n",i);
		vector<int>::iterator top[201];
		int count=0;
		for(int j=min;j<=max;j++)
		{
			top[j]=ageList[j].begin();
			count+=ageList[j].size();
		}
		if(count==0)
			printf("None\n");
		else
		{
			int nm;
			if(count<m)
				nm=count;
			else
				nm=m;
			count=0;
#ifdef DEBUG
printf("nm=%d\n",nm);
#endif
			while(count<nm)
			{
				int index=-1;
				int maxMoney=-1000001;
				for(int j=min;j<=max;j++)
					if(top[j]!=ageList[j].end() && people[*(top[j])].worth > maxMoney)
					{
							maxMoney=people[*(top[j])].worth;
							index=j;
					}
#ifdef DEBUG
printf("index=%d\n",index);
#endif
				printf("%s %d %d\n",people[*(top[index])].name,people[*(top[index])].age,people[*(top[index])].worth);
				count++;
				top[index]++;
			}
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
using namespace std;
#define DEBUG
class Road{
public:
	int to;
	int dist;
};
vector<Road> adjacent[1011];//1 to 1000 for houses, 1001 to 1010 for gas
int n,m,ds;
int min_dist,sum_dist;
void di(int s)
{
#ifdef DEBUG
printf("begin di: s=%d\n",s);
#endif
	int len[1011];
	bool inS[1011];
	int i;
	for(i=1;i<=1010;i++)
	{
		inS[i]=false;
		len[i]=INT_MAX;
	}
	for(i=0;i<adjacent[s].size();i++)
	{
		len[adjacent[s][i].to]=adjacent[s][i].dist;
	}
	len[s]=0;
	inS[s]=true;
	int count=1;
	min_dist=INT_MAX;
	sum_dist=0;
	while(count<n+m)
	{
		int min=INT_MAX;
		int next;
		for(i=1;i<=1010;i++)
		{
			if(!inS[i] && len[i]<min)
			{
				min=len[i];
				next=i;
			}
		}
#ifdef DEBUG
printf("find next=%d, min=%d\n",next,min);
#endif
		if(min>ds && next<=1000)
		{
			//out of service
			min_dist=ds+1;
#ifdef DEBUG
printf("out of service, break\n");
#endif
			return ;
		}
		if(next<=1000)
		{
			sum_dist+=min;
			if(min<min_dist)
				min_dist=min;
		}
		inS[next]=true;
		count++;
		for(i=0;i<adjacent[next].size();i++)
		{
			if(len[next]+adjacent[next][i].dist<len[adjacent[next][i].to])
			{
				len[adjacent[next][i].to]=len[next]+adjacent[next][i].dist;
			}
		}
	}
}
int main()
{
	int k,i;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(i=0;i<k;i++)
	{
		char s[10];
		scanf("%s",s);
		int from,to;
		if(s[0]=='G')
			from=atoi(s+1)+1000;
		else
			from=atoi(s);
		scanf("%s",s);
		if(s[0]=='G')
			to=atoi(s+1)+1000;
		else
			to=atoi(s);
		int dist;
		scanf("%d",&dist);
		Road r1;
		r1.to=to;
		r1.dist=dist;
		adjacent[from].push_back(r1);
		Road r2;
		r2.to=from;
		r2.dist=dist;
		adjacent[to].push_back(r2);
	}
	int global_min_dist,global_sum_dist;
	global_min_dist=0;
	global_sum_dist=0;
	int global_index=-1;
	for(i=1;i<=m;i++)
	{
		di(1000+i);
#ifdef DEBUG
printf("after call di: min_dist=%d\n",min_dist);
#endif
		if(min_dist<=ds && min_dist>global_min_dist)
		{
			global_min_dist=min_dist;
			global_sum_dist=sum_dist;
			global_index=i;
#ifdef DEBUG
printf("change global_min_dist to %d\n",global_min_dist);
#endif
		}
		else if(min_dist<=ds && min_dist==global_min_dist && sum_dist<global_sum_dist)
		{
			global_sum_dist=sum_dist;
			global_index=i;
		}
	}
	if(global_index!=-1)
	{
		printf("G%d\n",global_index);
		printf("%.1lf %.1lf",1.0*global_min_dist,(1.0*global_sum_dist)/n);
#ifdef DEBUG
printf("\nfinal answer: global_sum_dist=%d\n",global_sum_dist);
#endif
	}
	else
		printf("No Solution");
	return 0;
}

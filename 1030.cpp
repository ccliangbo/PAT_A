#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

#define MAX_BIG 250001
int dis_map[500][500];
int cost_map[500][500];
int path[500];
bool inS[500];
int length[500];
int cost[500];
int n,s,d,m;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dis_map[i][j]=MAX_BIG;
	for(i=0;i<n;i++)
	{
		inS[i]=false;
		length[i]=MAX_BIG;
	}
	for(i=0;i<m;i++)
	{
		int from,to,dis,co;
		scanf("%d%d%d%d",&from,&to,&dis,&co);
		dis_map[from][to]=dis;
		dis_map[to][from]=dis;
		cost_map[from][to]=co;
		cost_map[to][from]=co;
	}

	//inS[s]=true;
	path[s]=s;
	length[s]=0;
	cost[s]=0;
	while(!inS[d])
	{
		int nextMin=MAX_BIG;
		int next;
		for(i=0;i<n;i++)
			if(!inS[i] && length[i]<nextMin)
			{
				next=i;
				nextMin=length[i];
			}

		inS[next]=true;
		for(i=0;i<n;i++)
			if(!inS[i])
			{
				if(length[next]+dis_map[next][i]<length[i])
				{
					length[i]=length[next]+dis_map[next][i];
					path[i]=next;
					cost[i]=cost[next]+cost_map[next][i];
				}
				else if(length[next]+dis_map[next][i]==length[i] && cost[i]>cost[next]+cost_map[next][i])
				{
					path[i]=next;
					cost[i]=cost[next]+cost_map[next][i];
				}
			}
	}

	vector<int> roads;
	i=d;
	while(path[i]!=i)
	{
		roads.push_back(i);
		i=path[i];
	}
	printf("%d",s);
	for(i=roads.size()-1;i>=0;i--)
		printf(" %d",roads[i]);
	printf(" %d %d",length[d],cost[d]);
	return 0;
}

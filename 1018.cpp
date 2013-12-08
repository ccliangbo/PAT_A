#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

#define MY_INT_MAX 1000000000

using namespace std;

#define DEBUG
int n,cmax,sp,m;
int map[501][501];
int bike[501];
bool inS[501];
vector<vector<int>> all_paths[501];
int length[501];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	//input
	scanf("%d%d%d%d",&cmax,&n,&sp,&m);
	int i,j,from,to,time;
	for(i=1;i<=n;i++)
		scanf("%d",&bike[i]);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			map[i][j]=MY_INT_MAX;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&from,&to,&time);
		map[from][to]=time;
		map[to][from]=time;
	}

	//shortest path
	for(i=1;i<=n;i++)
	{
		inS[i]=false;
		length[i]=map[0][i];
		if(length[i]<MY_INT_MAX)
		{
			vector<int> v;
			v.push_back(i);
			vector<vector<int>> vv;
			vv.push_back(v);
			all_paths[i]=vv;
		}
	}
	inS[0]=true;

	int min;
	int minV;
	while(!inS[sp])
	{
		minV=MY_INT_MAX;
		for(i=1;i<=n;i++)
		{
			if(!inS[i] && length[i]<minV)
			{
				min=i;
				minV=length[i];
			}
		}

#ifdef DEBUG
	int debug_i;
	for(debug_i=1;debug_i<=n;debug_i++)
	{
		printf("length[%d]=%d ",debug_i,length[debug_i]);
	}
	printf("\nin this iteration, min=%d, length[min]=%d\n",min,length[min]);
#endif
		inS[min]=true;
		for(i=1;i<=n;i++)
		{
			if(inS[i])
				continue;
#ifdef DEBUG
	printf("now i=%d, length[i]=%d\n",i,length[i]);
#endif
			if(length[i]>map[min][i]+length[min])
			{
#ifdef DEBUG
	printf("find a new short path to %d\n",i);
#endif
				length[i]=map[min][i]+length[min];
				all_paths[i].clear();
				for(vector<vector<int>>::iterator it=all_paths[min].begin();it!=all_paths[min].end();it++)
				{
					vector<int> nv= *it;
					nv.push_back(i);
					all_paths[i].push_back(nv);
				}
			}
			else if(length[i]==map[min][i]+length[min])
			{
#ifdef DEBUG
	printf("find an equal path to %d\n",i);
#endif
				for(vector<vector<int>>::iterator it=all_paths[min].begin();it!=all_paths[min].end();it++)
				{
					vector<int> nv= *it;
					nv.push_back(i);
					all_paths[i].push_back(nv);
				}
			}
		}
	}

	int minSend=99999999;
	int send;
	int record_send;
	vector<vector<int>> possible_paths;

	//find the paths with less send
	for(vector<vector<int>>::iterator it=all_paths[sp].begin();it!=all_paths[min].end();it++)
	{
		send=0;
		record_send=0;
		for(vector<int>::iterator jt=it->begin();jt!=it->end();jt++)
		{
			send+=cmax/2-bike[*jt];
			if(send>record_send)
				record_send=send;
		}
#ifdef DEBUG
	printf("record_send=%d, minSend=%d\n",record_send,minSend);
#endif
		if(record_send<minSend)
		{
			minSend=record_send;
			possible_paths.clear();
			possible_paths.push_back(*it);
		}
		else if(record_send == minSend)
		{
			possible_paths.push_back(*it);
		}
	}

	int store;
	int minStore=99999999;
	vector<vector<int>>::iterator bestPath;
	for(vector<vector<int>>::iterator it=possible_paths.begin();it!=possible_paths.end();it++)
	{
		store=minSend;
		for(vector<int>::iterator jt=it->begin();jt!=it->end();jt++)
		{
			store=store-(cmax/2-bike[*jt]);
		}
#ifdef DEBUG
	printf("this path, store=%d\n",store);
#endif
		if(store<minStore)
		{
			minStore=store;
			bestPath=it;
		}
	}
	printf("%d 0",minSend);
	for(vector<int>::iterator jt=bestPath->begin();jt!=bestPath->end();jt++)
		printf("->%d",*jt);
	printf(" %d",minStore);
	
	return 0;
}
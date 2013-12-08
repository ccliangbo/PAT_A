#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

#define DEBUG

int n;
vector<int> road[10001];
struct frame
{
	int len;
	int id;
};

int fmset[10001];
int findset(int n)
{
	if(fmset[n] == n)
		return n;
	else
	{
		fmset[n]=findset(fmset[n]);
		return fmset[n];
	}
}

void mergeset(int a,int b)
{
	a=findset(a);
	b=findset(b);
	if( a == b)
		return;
	fmset[a]=b;
}


int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int i,j;
	scanf("%d",&n);
	int from,to;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&from,&to);
		road[from].push_back(to);
		road[to].push_back(from);
	}

	int max_road=0;
	int gmax_road=0;
	vector<int> win;
	int visit_count;
	bool visited[10001];
	bool isConnect=true;
	queue<frame> q;
	for(i=1;i<=n;i++)
	{
		//try if i is the root
		visit_count=1;
		for(j=1;j<=n;j++)
			visited[j]=false;
		frame f;
		f.len=0;
		f.id=i;
		q.push(f);
		visited[i]=true;
		max_road=0;
		while(!q.empty())
		{
			for(vector<int>::iterator it=road[q.front().id].begin();it!=road[q.front().id].end();it++)
			{
				if(!visited[*it])
				{
					visited[*it]=true;
					frame f;
					f.id=*it;
					f.len=q.front().len+1;
					if(f.len>max_road)
					{
						max_road=f.len;
					}
					q.push(f);
					visit_count++;
				}
			}
			q.pop();
		}
		if(visit_count!=n)
		{
			//not connected
			isConnect=false;
			break;
		}
		if(max_road>gmax_road)
		{
			gmax_road=max_road;
			win.clear();
			win.push_back(i);
		}
		else if(max_road == gmax_road)
		{
			win.push_back(i);
		}
	}
	if(isConnect)
	{
		for(vector<int>::iterator it=win.begin();it!=win.end();it++)
			printf("%d\n",*it);
	}
	else
	{
		for(i=1;i<=n;i++)
			fmset[i]=i;
		for(i=1;i<=n;i++)
		{
			for(vector<int>::iterator it=road[i].begin();it!=road[i].end();it++)
				mergeset(i,*it);
		}
		int components=1;
		for(i=2;i<=n;i++)
			if(findset(1)!=findset(i))
			{
				components++;
				mergeset(1,i);
			}
		printf("Error: %d components",components);
	}
	return 0;
}
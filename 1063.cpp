#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> myList[51];
int main()
{
	int n,i,m,t,k,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		vector<int> ov;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&t);
			ov.push_back(t);
		}
		sort(ov.begin(),ov.end());
		myList[i].push_back(ov[0]);
		j=1;
		int pos=0;
		while(j<m)
		{
			if(myList[i][pos]!=ov[j])
			{
				pos++;
				myList[i].push_back(ov[j]);
			}
			j++;
		}
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int mx,my;
		mx=myList[x].size();
		my=myList[y].size();
		int nc=0;
		int nt=0;
		int p1=0;
		int p2=0;
		while(p1<mx && p2<my)
		{
			if(myList[x][p1]==myList[y][p2])
			{
				nc++;
				nt++;
				p1++;
				p2++;
			}
			else if(myList[x][p1]<myList[y][p2])
			{
				nt++;
				p1++;
			}
			else
			{
				nt++;
				p2++;
			}
		}
		while(p1<mx)
		{
			nt++;
			p1++;
		}
		while(p2<my)
		{
			nt++;
			p2++;
		}
		double ratio;
		ratio=100.0*nc/nt;
		printf("%.1f%%\n",ratio);
	}
	return 0;
}

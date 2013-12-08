#include<stdio.h>
#include<vector>
using namespace std;
#define DEBUG
class Pro{
public:
	int w;
	int p;
};
int main()
{
	int np,ng;
	scanf("%d%d",&np,&ng);
	Pro programmers[1001];
	int i;
	for(i=0;i<np;i++)
		scanf("%d",&(programmers[i].w));
	vector<int> pv;
	vector<int> winv;
	vector<int> losev;
	for(i=0;i<np;i++)
	{
		int t;
		scanf("%d",&t);
		pv.push_back(t);
	}
	while(pv.size()>1)
	{
#ifdef DEBUG
printf("now pv.size: %d\n",pv.size());
#endif
		winv.clear();
		losev.clear();
		for(i=0;i<pv.size();i+=ng)
		{
			int maxIndex=pv[i];
			for(int j=i+1;j<i+ng && j<pv.size();j++)
				if(programmers[pv[j]].w>programmers[maxIndex].w)
				{
#ifdef DEBUG
printf("change maxIndex from %d to %d\n",maxIndex,pv[j]);
#endif
					maxIndex=pv[j];
				}
#ifdef DEBUG
printf("find a winner: %d\n",maxIndex);
#endif
			winv.push_back(maxIndex);
			for(int j=i;j<i+ng && j<pv.size();j++)
				if(pv[j]!=maxIndex)
				{
#ifdef DEBUG
printf("find a loser: %d\n",pv[j]);
#endif
					losev.push_back(pv[j]);
				}
		}
		int rank=winv.size()+1;
		for(int j=0;j<losev.size();j++)
			programmers[losev[j]].p=rank;
		pv=winv;
	}
	programmers[pv[0]].p=1;
	printf("%d",programmers[0].p);
	for(i=1;i<np;i++)
		printf(" %d",programmers[i].p);
	return 0;
}

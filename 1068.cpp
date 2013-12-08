#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//#define DEBUG
bool less_v(vector<int> &a, vector<int> &b)
{
	int i;
	for(i=0;i<a.size();i++)
		if(a[i]<b[i])
			return true;
		else if(a[i]>b[i])
			return false;
	return false;
}
int main()
{
	int n,m,i,j;
	vector<int> v[101];
	vector<int> a;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t>0 && t<=100)
			a.push_back(t);
	}
	sort(a.begin(),a.end());
	n=a.size();
	for(i=0;i<n;i++)
	{
		int coin=a[i];
#ifdef DEBUG
printf("i=%d, coin=%d\n",i,coin);
#endif
		for(j=99;j>=1;j--)
			if(v[j].size()>0 && j+coin<=100 && v[j+coin].size()==0)
			{
				v[j+coin]=v[j];
				v[j+coin].push_back(coin);
#ifdef DEBUG
printf("j+coin=%d is achieved\n",j+coin);
#endif
			}
			else if(v[j].size()>0 && j+coin<=100 && v[j+coin].size()>0)
			{
				vector<int> tv=v[j];
				tv.push_back(coin);
				if(less_v(tv,v[j+coin]))
					v[j+coin]=tv;
			}
		if(v[coin].size()==0)
		{
			v[coin].push_back(coin);
#ifdef DEBUG
printf("coin=%d is achieved\n",coin);
#endif
		}
	}
	if(v[m].size()>0)
	{
		printf("%d",v[m][0]);
		for(i=1;i<v[m].size();i++)
			printf(" %d",v[m][i]);
	}
	else
		printf("No Solution");
	return 0;
}

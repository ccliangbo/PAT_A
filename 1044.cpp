#include<stdio.h>
#include<vector>
using namespace std;
class Seg{
	public:
		int from,to;
};
int main()
{
	int n,m,i,j;
	int a[100001];
	scanf("%d%d",&n,&m);
	int min=100000001;
	vector<Seg> minList;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	i=1;
	j=1;
	int sum=a[1];
	while(true)
	{
		if(sum>=m)
		{
			if(sum<min)
			{
				minList.clear();
				Seg e;
				e.from=i;
				e.to=j;
				min=sum;
				minList.push_back(e);
			}
			else if(sum == min)
			{
				Seg e;
				e.from=i;
				e.to=j;
				minList.push_back(e);
			}
			sum-=a[i];
			i++;
			if(i==n+1)
				break;
		}
		else
		{
			if(j==n)
				break;
			j++;
			sum+=a[j];
		}
	}
	for(i=0;i<minList.size();i++)
		printf("%d-%d\n",minList[i].from,minList[i].to);
	return 0;
}

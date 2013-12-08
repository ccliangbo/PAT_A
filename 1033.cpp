#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
#undef DEBUG

class Station{
public:
	double price,distance;
	bool operator < (const Station & right) const
	{
		if(distance<right.distance)
			return true;
		return false;
	}
};
double cmax,d,davg,step;
int n;
vector<Station> v;

int find_nearest_station(int m)
{
	int i;
	for(i=m+1;i<=n;i++)
	{
		if(v[i].distance>v[m].distance+cmax*davg)
			break;
		if(v[i].price<v[m].price)
			return i;
	}
	return -1;
}
int find_second_station(int m)
{
	int min=m+1;
	int i;
	for(i=m+1;i<=n;i++)
	{
		if(v[i].distance>v[m].distance+cmax*davg)
			break;
		if(v[i].price<v[min].price)
			min=i;
	}
	return min;
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
	step=cmax*davg;
	int i;
	v.reserve(n+1);
	for(i=0;i<n;i++)
	{
		Station s;
		scanf("%lf%lf",&s.price,&s.distance);
		v.push_back(s);
	}
	Station s;
	s.price=0;
	s.distance=d;
	v.push_back(s);
	sort(v.begin(),v.end());
	int now;
	double cap,cost;
	int min;
	double fill;
	double vol;
	int second;

	if(v[0].distance>0)
		printf("The maximum travel distance = 0.00\n");
	else
	{
		cap=0;
		now=0;
		cost=0;
		while(now<n)
		{
			if(v[now+1].distance-v[now].distance>step)
			{
				printf("The maximum travel distance = %.2lf",v[now].distance+step);
				return 0;
			}
			min=find_nearest_station(now);
			if(min == -1)
			{
				//this is the cheapest station within reach, fill to full
				vol=cmax-cap;
				cost+=v[now].price*vol;
				cap=cmax;
				
				//go to the second cheapest station
				second=find_second_station(now);
				cap-=(v[second].distance-v[now].distance)/davg;
				now=second;
			}
			else
			{
				if(cap*davg>v[min].distance-v[now].distance)
				{
					//no not need to fill, go ahead
					cap-=(v[min].distance-v[now].distance)/davg;
				}
				else
				{
					//fill to get there
					fill=(v[min].distance-v[now].distance)/davg-cap;
					cost+=fill*v[now].price;
					cap=0;
				}
				now=min;
			}
		}
		printf("%.2lf",cost);
	}
	return 0;
}

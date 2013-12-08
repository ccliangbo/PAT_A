#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Moon{
public:
	double amount;
	double price;
	double weight;
	bool operator<(const Moon & right)const
	{
		if(weight>right.weight)
			return true;
		return false;
	}
};
int main()
{
	vector<Moon> v;
	int i,n;
	double d,profit=0;
	scanf("%d%lf",&n,&d);
	for(i=0;i<n;i++)
	{
		double a;
		scanf("%lf",&a);
		Moon t;
		t.amount=a;
		v.push_back(t);
	}
	for(i=0;i<n;i++)
	{
		double p;
		scanf("%lf",&p);
		v[i].price=p;
		v[i].weight=v[i].price/v[i].amount;
	}
	sort(v.begin(),v.end());
	for(i=0;i<n && d>0;i++)
	{
		if(d>=v[i].amount)
		{
			d-=v[i].amount;
			profit+=v[i].price;
		}
		else
		{
			profit+=v[i].price*(d/v[i].amount);
			break;
		}
	}
	printf("%.2lf",profit);
	return 0;
}

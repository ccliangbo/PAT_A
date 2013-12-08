#include<stdio.h>
#include<vector>
#include<algorithm>

#define DEBUG
using namespace std;
class Customer{
public:
	int c,b,e,p;
	bool operator <(const Customer & right) const
	{
		if(c<right.c)
			return true;
		return false;
	}
};
int n,k,rn;
int windows[100];
vector<Customer> v;
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int i;
	scanf("%d%d",&n,&k);
	rn=0;
	for(i=0;i<k;i++)
		windows[i]=-1;
	for(i=0;i<n;i++)
	{
		int ch,cm,cs,p;
		scanf("%d:%d:%d%d",&ch,&cm,&cs,&p);
		int tmp=ch*3600+cm*60+cs;
		if(tmp<=17*3600)
		{
			Customer c;
			c.c=tmp;
			c.p=p*60;
			v.push_back(c);
			rn++;
		}
	}
	sort(v.begin(),v.end());
#ifdef DEBUG
	printf("rn = %d\n",rn);
	for(i=0;i<v.size();i++)
		printf("%d %d\n",v[i].c,v[i].p);
#endif

	long long int wait=0;
	int front_customer=0;
	int now_time=0;
	int position;
	while(front_customer<rn)
	{
		position=0;
		for(i=0;i<k;i++)
		{
			if(windows[i] == -1)
			{
				position=i;
				break;
			}
			if(v[windows[i]].e<v[windows[position]].e)
				position=i;
		}
		if(windows[position] == -1)
		{
#ifdef DEBUG
	printf("windows[position] == -1 and position=%d\n",position);
#endif
			if(v[front_customer].c>=8*3600)
			{
				v[front_customer].b=v[front_customer].c;
			}
			else
			{
				v[front_customer].b=8*3600;
				wait+=8*3600-v[front_customer].c;
#ifdef DEBUG
	printf("wait=%lld\n",wait);
#endif
			}
#ifdef DEBUG
	printf("v[%d].b=%d\n",front_customer,v[front_customer].b);
#endif
		}
		else if(v[windows[position]].e<v[front_customer].c)
		{
#ifdef DEBUG
	printf("v[windows[position]].e<v[front_customer].c and position=%d\n",position);
#endif
			v[front_customer].b=v[front_customer].c;
#ifdef DEBUG
	printf("v[%d].b=%d\n",front_customer,v[front_customer].b);
#endif
		}
		else
		{
#ifdef DEBUG
	printf("v[windows[position]].e>=v[front_customer].c and position=%d\n",position);
#endif
			v[front_customer].b=v[windows[position]].e;
			wait=wait+(v[windows[position]].e-v[front_customer].c);
#ifdef DEBUG
	printf("v[%d].b=%d, wait=%lld\n",front_customer,v[front_customer].b,wait);
#endif
		}
		v[front_customer].e=v[front_customer].b+v[front_customer].p;
#ifdef DEBUG
	printf("v[%d].e=%d\n",front_customer,v[front_customer].e);
#endif
		windows[position]=front_customer;
		front_customer++;
	}

	printf("%.1lf",wait/60.0/rn);
	return 0;
}
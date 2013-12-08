#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int d1,d2,d3,d4;
	d1=n/1000;
	d2=n/100%10;
	d3=n/10%10;
	d4=n%10;
	if(d1 == d2 && d2 == d3 && d3 == d4)
	{
		printf("%04d - %04d = 0000",n,n);
		return 0;
	}
	else
	{
		while(true)
		{
			d1=n/1000;
			d2=n/100%10;
			d3=n/10%10;
			d4=n%10;
			vector<int> v;
			v.push_back(d1);
			v.push_back(d2);
			v.push_back(d3);
			v.push_back(d4);
			sort(v.begin(),v.end());
			int big,small;
			big=v[3]*1000+v[2]*100+v[1]*10+v[0];
			small=v[0]*1000+v[1]*100+v[2]*10+v[3];
			int diff=big-small;
			printf("%04d - %04d = %04d\n",big,small,diff);
			if(diff == 6174)
				break;
			else
			{
				n=diff;
			}
		}
	}
	return 0;
}

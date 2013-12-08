#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool less_1(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int nn,np;
	int i;
	scanf("%d",&nn);
	vector<int> vpn,vnn,vpp,vnp;
	for(i=0;i<nn;i++)
	{
		int t;
		scanf("%d",&t);
		if(t>0)
			vpn.push_back(t);
		else
			vnn.push_back(-t);
	}
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		int t;
		scanf("%d",&t);
		if(t>0)
			vpp.push_back(t);
		else
			vnp.push_back(-t);
	}
	sort(vpn.begin(),vpn.end(),less_1);
	sort(vnn.begin(),vnn.end(),less_1);
	sort(vpp.begin(),vpp.end(),less_1);
	sort(vnp.begin(),vnp.end(),less_1);
	long long int result=0;
	int min;
	if(vpn.size()>vpp.size())
		min=vpp.size();
	else
		min=vpn.size();
	for(i=0;i<min;i++)
	{
		result+=vpn[i]*vpp[i];
	}
	if(vnn.size()>vnp.size())
		min=vnp.size();
	else
		min=vnn.size();
	for(i=0;i<min;i++)
	{
		result+=vnn[i]*vnp[i];
	}
	printf("%lld",result);
	return 0;
}
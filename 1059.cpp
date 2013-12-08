#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(long n)
{
	long m=(long)sqrt(n);
	for(long i=2;i<=m;i++)
		if(n%i == 0)
			return false;
	return true;
}
int main()
{
	vector<long> pf;
	vector<long> kf;
	long n;
	scanf("%ld",&n);
	if(n==1)
	{
		printf("1=1");
		return 0;
	}
	long nn=n;
	long i=2;
	int top=-1;
	for(i=2;i<=nn && nn!=1;i++)
	{
		if(!isPrime(i))
			continue;
		bool newF=true;
		while(i<=nn && nn%i == 0)
		{
			if(newF)
			{
				newF=false;
				pf.push_back(i);
				kf.push_back(1);
				top++;
			}
			else
			{
				kf[top]=kf[top]+1;
			}
			nn/=i;
		}
	}
	printf("%ld=",n);
	if(kf[0]==1)
		printf("%ld",pf[0]);
	else
		printf("%ld^%ld",pf[0],kf[0]);
	for(int j=1;j<pf.size();j++)
		if(kf[j]==1)
			printf("*%ld",pf[j]);
		else
			printf("*%ld^%ld",pf[j],kf[j]);
	return 0;
}

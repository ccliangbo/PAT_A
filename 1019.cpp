#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

#define DEBUG

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int n,b;
	scanf("%d%d",&n,&b);
	if(n==0)
	{
		printf("Yes\n0");
	}
	else
	{
		vector<int> a;
		while(n!=0)
		{
			a.push_back(n%b);
			n=n/b;
		}
		bool isP=true;
		for(int i=0;i<a.size();i++)
			if(a[i] != a[a.size()-i-1])
				isP=false;
		if(isP)
			printf("Yes\n");
		else
			printf("No\n");
		for(int i=a.size()-1;i>0;i--)
			printf("%d ",a[i]);
		printf("%d",a[0]);
	}
	
	return 0;
}
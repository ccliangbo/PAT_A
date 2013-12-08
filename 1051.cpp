#include<stdio.h>
#include<stack>
using namespace std;
//#define DEBUG
int main()
{
	int m,n,k,i,j,inTop;
	scanf("%d%d%d",&m,&n,&k);
	for(i=0;i<k;i++)
	{
#ifdef DEBUG
printf("i=%d\n",i);
#endif
		bool f=true;
		inTop=1;
		stack<int> s;
		for(j=0;j<n;j++)
		{
			int t;
			scanf("%d",&t);
#ifdef DEBUG
printf("read t=%d\n",t);
#endif
			while(s.size()==0 || s.top()<t)
			{
#ifdef DEBUG
printf("push %d\n",inTop);
#endif
				s.push(inTop++);
			}
#ifdef DEBUG
printf("after push, size=%d\n",s.size());
#endif
			if(s.size()>m)
			{
				f=false;
				break;
			}
			if(s.top()!=t)
			{
				f=false;
				break;
			}
			s.pop();
		}
		j++;
		while(j<n)
		{
			int t;
			scanf("%d",&t);
			j++;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

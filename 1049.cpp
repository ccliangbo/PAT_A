#include<stdio.h>
#include<math.h>

//the number of 1 from [0,n]
int f(int n)
{
	if(n==0)
		return 0;
	if(n<10)
		return 1;
	int m,d,h;
	m=n;
	d=0;
	while(m>=10)
	{
		d++;
		m=m/10;
	}
	h=m;
	int result=h*f((int)pow(10.0,d)-1);
	if(h != 1)
	{
		result+=(int)pow(10.0,d);
		result+=f(n-h*((int)pow(10,d)));
	}
	else
	{
		result+=n-h*((int)pow(10,d))+1;
		result+=f(n-h*((int)pow(10,d)));
	}
	return result;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}

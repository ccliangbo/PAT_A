#include<stdio.h>
#include<string.h>
class Number{
public:
	char a[120];
	char b[120];
	int count;
	int k;
	void process()
	{
		count=0;
		k=0;
		int i=0;
		for(i=0;i<120;i++)
			b[i]='0';
		i=0;
		while(a[i]=='0')
		{
			i++;
		}
		while(a[i]!='.' && a[i]!='\0')
		{
			b[count]=a[i];
			count++;
			k++;
			i++;
		}
		if(a[i]=='.')
			i++;
		else
			return;
		if(k != 0 )
		{
			while(a[i]!='\0')
			{
				b[count]=a[i];
				count++;
				i++;
			}
		}
		else
		{
			while(a[i]=='0' && a[i]!='\0')
			{
				i++;
				k--;
			}
			if(a[i]=='\0')
			{
				//0.0 case
				k=0;
				return;
			}
			while(a[i]!='\0')
			{
				b[count]=a[i];
				count++;
				i++;
			}
		}
	}
	bool equal(int n, Number & right)
	{
		if(k != right.k)
			return false;
		int i=0;
		for(i=0;i<n;i++)
			if(b[i]!=right.b[i])
				return false;
		return true;
	}
	void show(int n)
	{
		int i;
		printf("0.");
		for(i=0;i<n;i++)
			printf("%c",b[i]);
		printf("*10^%d",k);
	}
};
int main()
{
	int n;
	Number a,b;
	scanf("%d%s%s",&n,a.a,b.a);
	a.process();
	b.process();
	if(a.equal(n,b) == true)
	{
		printf("YES ");
		a.show(n);
	}
	else
	{
		printf("NO ");
		a.show(n);
		printf(" ");
		b.show(n);
	}
	return 0;
}

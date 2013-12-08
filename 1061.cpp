#include<stdio.h>
#include<ctype.h>
int main()
{
	char a[80],b[80],c[80],d[80];
	scanf("%s%s%s%s",a,b,c,d);
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i] == b[i] && a[i] >= 'A' && a[i]<='G')
		{
			int d=(a[i]-'A')%7+1;
			switch(d)
			{
				case 1:	printf("MON ");break;
				case 2:	printf("TUE ");break;
				case 3:	printf("WED ");break;
				case 4:	printf("THU ");break;
				case 5:	printf("FRI ");break;
				case 6:	printf("SAT ");break;
				case 7:	printf("SUN ");break;
				default:while(true);
			}
			i++;
			break;
		}
		i++;
	}
	while(a[i]!='\0')
	{
		if(a[i] == b[i] && ((a[i] >= 'A' && a[i]<='N') || (a[i] >= '0' && a[i]<='9')))
		{
			if(a[i]>='0' &&a[i]<='9')
				printf("%02d:",a[i]-'0');
			else
				printf("%02d:",a[i]-'A'+10);
			break;
		}
		i++;
	}
	i=0;
	while(c[i]!='\0')
	{
		if(c[i]==d[i] && isalpha(c[i]))
		{
			printf("%02d",i);
			//printf("%c%c",c[i],d[i]);
			return 0;
		}
		i++;
	}
	return 0;
}

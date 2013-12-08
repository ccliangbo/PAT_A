#include<stdio.h>
#include<stdlib.h>

//PAT1001
void f(long n)
{
    if(n>=1000)
    {
        f(n/1000);
        if(n%1000>=100)
            printf(",%ld",n%1000);
        else if(n%1000>=10)
            printf(",0%ld",n%1000);
        else
            printf(",00%ld",n%1000);
    }
    else
        printf("%ld",n);
}
int main()
{
    long a,b,c;
    scanf("%ld%ld",&a,&b);
    c=a+b;
    if(c<0)
    {
        printf("-");
        c=-c;
    }
    f(c);
    return 0;
}

/*
good sample

#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d", &a, &b);
	c=a+b;
	if(c<0)
	{  
		c=-c;  printf("-");
	}
	if(c>=1000000) 
		printf("%d,%03d,%03d\n",c/1000000,c/1000%1000,c%1000); 
	else if(c>=1000) 
		printf("%d,%03d\n",c/1000,c%1000);
	else 
		printf("%d\n",c); 
	return 0;
}
*/

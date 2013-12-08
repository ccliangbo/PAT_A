#include<stdio.h>
int main()
{
	char s1[10001];
	char s2[10001];
	gets(s1);
	gets(s2);
	int i;
	bool b[257];
	for(i=0;i<257;i++)
		b[i]=true;
	i=0;
	while(s2[i]!='\0')
	{
		b[s2[i]]=false;
		i++;
	}
	i=0;
	while(s1[i]!='\0')
	{
		if(b[s1[i]])
			putchar(s1[i]);
		i++;
	}
	return 0;
	
}

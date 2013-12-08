#include<stdio.h>
#include<string>
#include<map>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	char buffer[1048577];
	gets(buffer);
	map<string,int> dict;
	int begin=0;
	int i;
	bool inword=false;
	int maxFre=0;
	int len=strlen(buffer);
	for(i=0;i<len;i++)
	{
		if(!inword && isalnum(buffer[i]))
		{
			begin=i;
			if(buffer[i]>='A' && buffer[i]<='Z')
				buffer[i]=buffer[i]+'a'-'A';
			inword=true;
		}
		else if(!inword && !isalnum(buffer[i]))
			;
		else if(inword &&isalnum(buffer[i]))
		{
			if(buffer[i]>='A' && buffer[i]<='Z')
				buffer[i]=buffer[i]+'a'-'A';
		}
		else 
		{
			buffer[i]='\0';
			inword=false;
			string s(&buffer[begin]);
			map<string,int>::iterator it=dict.find(s);
			if(it!=dict.end())
			{
				it->second=it->second+1;
				if(it->second>maxFre)
				{
					maxFre=it->second;
				}
			}
			else
			{
				dict[s]=1;
				if(maxFre==0)
					maxFre=1;
			}
			begin=i+1;
		}
	}
	if(inword)
	{
		string s(&buffer[begin]);
		map<string,int>::iterator it=dict.find(s);
		if(it!=dict.end())
		{
			it->second=it->second+1;
			if(it->second>maxFre)
			{
				maxFre=it->second;
			}
		}
		else
		{
			dict[s]=1;
			if(maxFre==0)
				maxFre=1;
		}
	}
	map<string,int>::iterator it;
	for(it=dict.begin();it!=dict.end();it++)
	{
		if(it->second == maxFre)
		{
			break;
		}
	}
	cout<<it->first<<' '<<maxFre;
	return 0;
}

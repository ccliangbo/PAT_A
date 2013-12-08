#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool less_1(string x,string y)
{
	string s1,s2;
	s1=x+y;
	s2=y+x;
	return s1<s2;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n;
	vector<string> v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),less_1);
	string result;
	for(int i=0;i<n;i++)
	{
		result+=v[i];
	}
	int position=result.find_first_not_of('0');
	if(position!=0)
		result.erase(0,position);
	if(result.size()==0)
		result="0";
	cout<<result;
	return 0;
}
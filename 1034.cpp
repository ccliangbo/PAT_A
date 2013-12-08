#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Node
{
public:
	int MyMinute;
	int totalMinute;
	int father;
	int peoplesOfGang;
	string name;
};

class VNode
{
public:
	string name;
	int num;
	bool operator<(const VNode & right) const
	{
		return name<right.name;
	}
};
int n,k,name_count;
map<string,int> nameDict;
Node mfset[2001];

int set_find(int n)
{
	if(n==mfset[n].father)
		return n;
	else
	{
		int result=set_find(mfset[n].father);
		mfset[n].father=result;
		return result;
	}
}
void set_merge(int x,int y)
{
	x=set_find(x);
	y=set_find(y);
	if(mfset[x].MyMinute>mfset[y].MyMinute)
	{
		mfset[y].father=x;
		mfset[x].peoplesOfGang+=mfset[y].peoplesOfGang;
		mfset[x].totalMinute+=mfset[y].totalMinute;
	}
	else
	{
		mfset[x].father=y;
		mfset[y].peoplesOfGang+=mfset[x].peoplesOfGang;
		mfset[y].totalMinute+=mfset[x].totalMinute;
	}
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	cin>>n>>k;
	name_count=0;
	for(int i=0;i<n;i++)
	{
		string s1,s2;
		int n1,n2;
		int len;
		cin>>s1>>s2>>len;
		map<string,int>::iterator it1;
		it1=nameDict.find(s1);
		if(it1==nameDict.end())
		{
			nameDict[s1]=name_count;
			n1=name_count;
			mfset[n1].father=n1;
			mfset[n1].MyMinute=len;
			mfset[n1].totalMinute=len;
			mfset[n1].peoplesOfGang=1;
			mfset[n1].name=s1;
			name_count++;
		}
		else
		{
			n1=it1->second;
			mfset[n1].MyMinute+=len;
			int father=set_find(n1);
			mfset[father].totalMinute+=len;
			if(mfset[n1].MyMinute>mfset[father].MyMinute)
			{
				mfset[n1].peoplesOfGang=mfset[father].peoplesOfGang;
				mfset[n1].totalMinute=mfset[father].totalMinute;
				mfset[n1].father=n1;
				mfset[father].father=n1;
			}
		}
		map<string,int>::iterator it2;
		it2=nameDict.find(s2);
		if(it2==nameDict.end())
		{
			nameDict[s2]=name_count;
			n2=name_count;
			mfset[n2].father=n2;
			mfset[n2].MyMinute=len;
			mfset[n2].totalMinute=len;
			mfset[n2].peoplesOfGang=1;
			mfset[n2].name=s2;
			name_count++;
		}
		else
		{
			n2=it2->second;
			mfset[n2].MyMinute+=len;
			int father=set_find(n2);
			mfset[father].totalMinute+=len;
			if(mfset[n2].MyMinute>mfset[father].MyMinute)
			{
				mfset[n2].peoplesOfGang=mfset[father].peoplesOfGang;
				mfset[n2].totalMinute=mfset[father].totalMinute;
				mfset[n2].father=n2;
				mfset[father].father=n2;
			}
		}
		if(set_find(n1)!=set_find(n2))
		{
			set_merge(n1,n2);
		}
	}

	vector<VNode> v;
	for(int i=0;i<name_count;i++)
	{
		if(mfset[i].father==i && mfset[i].peoplesOfGang>2 && mfset[i].totalMinute > 2*k)
		{
			VNode r;
			r.name=mfset[i].name;
			r.num=mfset[i].peoplesOfGang;
			v.push_back(r);
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].name<<' '<<v[i].num<<endl;
	}
	return 0;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<iostream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

#define DEBUG

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,m;
	map<string,set<string> > titleMap;
	map<string,set<string> > authorMap;
	map<string,set<string> > publisherMap;
	map<string,set<string> > yearMap;
	map<string,set<string> > keyMap;

	cin>>n;
	string dummy;
	getline(cin,dummy);
	for(int i=0;i<n;i++)
	{
		string id,title;
		getline(cin,id);

		//title
		getline(cin,title);
		if(titleMap.count(title) == 0)
		{
			set<string> s;
			s.insert(id);
			titleMap[title]=s;
		}
		else
		{
			map<string,set<string> >::iterator it=titleMap.find(title);
			set<string> s=it->second;
			s.insert(id);
			titleMap[title]=s;
		}

		//author
		string author;
		getline(cin,author);
		if(authorMap.count(author) == 0)
		{
			set<string> s;
			s.insert(id);
			authorMap[author]=s;
		}
		else
		{
			map<string,set<string> >::iterator it=authorMap.find(author);
			set<string> s=it->second;
			s.insert(id);
			authorMap[author]=s;
		}

		//key words
		string keywords;
		getline(cin,keywords);
		istringstream ist(keywords);
		while(!ist.eof())
		{
			string key;
			ist>>key;
			if(keyMap.count(key) == 0)
			{
				set<string> s;
				s.insert(id);
				keyMap[key]=s;
			}
			else
			{
				map<string,set<string> >::iterator it=keyMap.find(key);
				set<string> s=it->second;
				s.insert(id);
				keyMap[key]=s;
			}
		}

		//publisher
		string publisher;
		getline(cin,publisher);
		if(publisherMap.count(publisher) == 0)
		{
			set<string> s;
			s.insert(id);
			publisherMap[publisher]=s;
		}
		else
		{
			map<string,set<string> >::iterator it=publisherMap.find(publisher);
			set<string> s=it->second;
			s.insert(id);
			publisherMap[publisher]=s;
		}

		//year
		string year;
		getline(cin,year);
		if(yearMap.count(year) == 0)
		{
			set<string> s;
			s.insert(id);
			yearMap[year]=s;
		}
		else
		{
			map<string,set<string> >::iterator it=yearMap.find(year);
			set<string> s=it->second;
			s.insert(id);
			yearMap[year]=s;
		}
	}

	cin>>m;
	getline(cin,dummy);
	for(int i=0;i<m;i++)
	{
		string query;
		getline(cin,query);
		cout<<query<<endl;
		set<string> results;
		string newquery=query.substr(3,query.length()-3);
		switch(query.at(0))
		{
		case '1':
			if(titleMap.count(newquery) == 1)
			{
				map<string,set<string> >::iterator it=titleMap.find(newquery);
				results=it->second;
			}
			break;
		case '2':
			if(authorMap.count(newquery) == 1)
			{
				map<string,set<string> >::iterator it=authorMap.find(newquery);
				results=it->second;
			}
			break;
		case '3':
			if(keyMap.count(newquery) == 1)
			{
				map<string,set<string> >::iterator it=keyMap.find(newquery);
				results=it->second;
			}
			break;
		case '4':
			if(publisherMap.count(newquery) == 1)
			{
				map<string,set<string> >::iterator it=publisherMap.find(newquery);
				results=it->second;
			}
			break;
		case '5':
			if(yearMap.count(newquery) == 1)
			{
				map<string,set<string> >::iterator it=yearMap.find(newquery);
				results=it->second;
			}
			break;
		}
		if(results.size()!=0)
		{
			vector<string> v;
			for(set<string>::iterator it=results.begin();it!=results.end();it++)
				v.push_back(*it);
			sort(v.begin(),v.end());
			for(int j=0;j<v.size();j++)
				cout<<v[j]<<endl;
		}
		else
			cout<<"Not Found"<<endl;
	}
	return 0;
}

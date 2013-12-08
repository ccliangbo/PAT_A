#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#undef DEBUG

class Player
{
public:
	int comeTime;
	int playTime;
	bool isVIP;
	int serveTime;
	int waitTime;
	bool isServed;
	bool operator<(const Player & r) const
	{
		return comeTime<r.comeTime;
	}
};

bool less_serveTime(const Player & x, const Player & y)
{
	return x.serveTime<y.serveTime;
}
class Table
{
public:
	int serveNumber;
	bool isVIP;
	int availableTime;
};

int n,k,m;
vector<Player> vp;
Table tables[101];
queue<int> normalQueue;
queue<int> vipQueue;

int vip_table_available(int curlTime)
{
	int i;
	for(i=1;i<=k;i++)
	{
		if(tables[i].isVIP &&tables[i].availableTime<=curlTime)
		{
			return i;
		}
	}
	return -1;
}

int all_table_available(int curlTime)
{
	int i;
	for(i=1;i<=k;i++)
	{
		if(tables[i].availableTime<=curlTime)
		{
			return i;
		}
	}
	return -1;
}

void assign_table(int curlTime, int tableNumber, int playerNumber)
{
	vp[playerNumber].isServed=true;
	vp[playerNumber].serveTime=curlTime;
	vp[playerNumber].waitTime=curlTime-vp[playerNumber].comeTime;
	tables[tableNumber].serveNumber++;
	tables[tableNumber].availableTime=curlTime+vp[playerNumber].playTime;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		Player p;
		int h,min,s,pt,tag;
		scanf("%d:%d:%d%d%d",&h,&min,&s,&pt,&tag);
		p.comeTime=(h-8)*3600+min*60+s;
		if(p.comeTime<0 || p.comeTime >=(21-8)*3600)
			continue;
		p.playTime=pt*60;
		if(p.playTime>2*60*60)
			p.playTime=2*60*60;
		if(tag == 1)
			p.isVIP=true;
		else
			p.isVIP=false;
		p.isServed=false;
		vp.push_back(p);
	}
	n=vp.size();
	scanf("%d%d",&k,&m);
	for(i=1;i<=k;i++)
	{
		tables[i].serveNumber=0;
		tables[i].availableTime=0;
		tables[i].isVIP=false;
	}
	for(i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		tables[tmp].isVIP=true;
	}
	sort(vp.begin(),vp.end());

	int shutTime=(21-8)*3600;
	int frontPlayer=0;
	for(int curTime=0;curTime<shutTime;curTime++)
	{
		//if comes a player
		if(frontPlayer<n && vp[frontPlayer].comeTime == curTime)
		{
			if(vp[frontPlayer].isVIP)
				vipQueue.push(frontPlayer);
			else
				normalQueue.push(frontPlayer);
			frontPlayer++;
		}

		while(vip_table_available(curTime)!=-1 && vipQueue.size()>0)
		{
			assign_table(curTime,vip_table_available(curTime),vipQueue.front());
			vipQueue.pop();
		}

		while(all_table_available(curTime)!=-1 && (vipQueue.size()>0 || normalQueue.size()>0))
		{
			if(vipQueue.size()>0 && normalQueue.size()>0)
			{
				if(vp[vipQueue.front()].comeTime<vp[normalQueue.front()].comeTime)
				{
					assign_table(curTime,all_table_available(curTime),vipQueue.front());
					vipQueue.pop();
				}
				else
				{
					assign_table(curTime,all_table_available(curTime),normalQueue.front());
					normalQueue.pop();
				}
			}
			else if(vipQueue.size()>0)
			{
				assign_table(curTime,all_table_available(curTime),vipQueue.front());
				vipQueue.pop();
			}
			else
			{
				assign_table(curTime,all_table_available(curTime),normalQueue.front());
				normalQueue.pop();
			}
		}
	}

	vector<Player> finishv;
	for(i=0;i<n;i++)
		if(vp[i].isServed)
			finishv.push_back(vp[i]);
	sort(finishv.begin(),finishv.end(),less_serveTime);
	//output
	for(i=0;i<finishv.size();i++)
	{
			printf("%02d:%02d:%02d ",finishv[i].comeTime/3600+8,finishv[i].comeTime/60%60,finishv[i].comeTime%60);
			printf("%02d:%02d:%02d ",finishv[i].serveTime/3600+8,finishv[i].serveTime/60%60,finishv[i].serveTime%60);
			int rs,rm;
			rm=finishv[i].waitTime/60;
			rs=finishv[i].waitTime%60;
			if(rs>=30)
				rm++;
			printf("%d\n",rm);
	}
	printf("%d",tables[1].serveNumber);
	for(i=2;i<=k;i++)
	{
		printf(" %d",tables[i].serveNumber);
	}
	return 0;
}

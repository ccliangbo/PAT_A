#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

#undef DEBUG
using namespace std;

class Record
{
public:
    char name[21];
    int m,d,h,minute;
    bool on;
	void nextHour()
	{
		h++;
		if(h==24)
		{
			h=0;
			d++;
		}
	}
};

int rate[24];
int n;
vector<Record> v;

bool less_record(const Record & r1,const Record & r2)
{
	if(strcmp(r1.name,r2.name) < 0)
		return true;
	if(strcmp(r1.name,r2.name) > 0)
		return false;
	if(r1.d<r2.d)
		return true;
	if(r1.d>r2.d)
		return false;
	if(r1.h<r2.h)
		return true;
	if(r1.h>r2.h)
		return false;
	if(r1.minute<r2.minute)
		return true;
	return false;
}

bool inSameHour(int i,int j)
{
	if(v[i].d== v[j].d &&v[i].h== v[j].h)
		return true;
	else
		return false;
}

int main()
{
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    
    int i;
    for(i=0;i<24;i++)
        scanf("%d",&rate[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Record r;
		char s[21];
        scanf("%s",r.name);
		scanf("%d:%d:%d:%d",&r.m,&r.d,&r.h,&r.minute);
		scanf("%s",s);
		if(strcmp(s,"on-line")==0)
			r.on=true;
		else
			r.on=false;
		v.push_back(r);
    }

	sort(v.begin(),v.end(),less_record);

	char nowName[21];
	nowName[0]='\0';
	int amount,totalAmount;
	int talkTime;
	totalAmount=-1;
	bool hasLeft=false;
	int leftIndex;
	for(i=0;i<n;i++)
	{
		if(strcmp(nowName,v[i].name) !=0)
		{
			if(totalAmount>0)
			{
				printf("Total amount: $%.2lf\n",totalAmount/100.0);
			}
			strcpy(nowName,v[i].name);
			totalAmount=0;
			//printf("%s %02d\n",nowName,v[i].m);
			hasLeft=false;
		}
		if(v[i].on)
		{
			hasLeft=true;
			leftIndex=i;
		}
		else if(!hasLeft)
		{
			//do nothing
		}
		else
		{
			//have a pair
			hasLeft=false;
			if(totalAmount<=0)
				printf("%s %02d\n",nowName,v[i].m);
			printf("%02d:%02d:%02d %02d:%02d:%02d ",v[leftIndex].d,v[leftIndex].h,v[leftIndex].minute,v[i].d,v[i].h,v[i].minute);
			if(inSameHour(leftIndex,i))
			{
				talkTime=v[i].minute-v[leftIndex].minute;
				amount=talkTime*rate[v[i].h];
			}
			else
			{
				talkTime=60-v[leftIndex].minute;
				amount=talkTime*rate[v[leftIndex].h];
				v[leftIndex].minute=0;
				v[leftIndex].nextHour();

				talkTime+=v[i].minute;
				amount+=v[i].minute*rate[v[i].h];
				v[i].minute=0;

				while(!inSameHour(leftIndex,i))
				{
					talkTime+=60;
					amount+=60*rate[v[leftIndex].h];
					v[leftIndex].nextHour();
				}
			}
			totalAmount+=amount;
			printf("%d $%.2lf\n",talkTime,amount/100.0);
		}
	}
	if(totalAmount>0)
	{
		printf("Total amount: $%.2lf\n",totalAmount/100.0);
	}
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>

#undef DEBUG
using namespace std;

int n,m,k,q;
class Customer
{
public:
    int beginTime,endTime,transTime;
};
Customer c[1001];

int main()
{
    int i,j;
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&(c[i].transTime));
        c[i].beginTime=-1;
        c[i].endTime=-1;
    }
    int nowTime=0;
    int shutDown=(17-8)*60;
    
    queue<int> windows[20];
    int count=1;//next customer to be served
    
    //first push n customers
    for(i=0;i<n && count<=k;i++)
    {
        windows[i].push(count);
        c[count].beginTime=0;
        c[count].endTime=c[count].transTime;
        count++;
    }
    //push m-1 customers in each queue
    for(i=0;i<m-1 && count<=k;i++)
        for(j=0;j<n && count<=k;j++)
        {
            c[count].beginTime=c[windows[j].back()].endTime;
            c[count].endTime=c[count].beginTime+c[count].transTime;
            windows[j].push(count);
            count++;
        }
    while(count<=k && nowTime<shutDown)
    {
        int minIndex=0;
        for(i=1;i<n;i++)
            if(c[windows[i].front()].endTime < c[windows[minIndex].front()].endTime)
                minIndex=i;
        nowTime=c[windows[minIndex].front()].endTime;
        windows[minIndex].pop();
        c[count].beginTime=c[windows[minIndex].back()].endTime;
        c[count].endTime=c[count].beginTime+c[count].transTime;
        windows[minIndex].push(count);
        count++;
    }
    
    //query
    for(i=0;i<q;i++)
    {
        int q;
        scanf("%d",&q);
        if(c[q].endTime == -1 || c[q].beginTime >= shutDown)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n",c[q].endTime/60+8,c[q].endTime%60);
    }
    return 0;
}

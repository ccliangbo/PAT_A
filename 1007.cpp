#include<stdio.h>
#include<vector>
#include<algorithm>

#undef DEBUG

using namespace std;

int main()
{
    int i,k;
    int first,last,max,maxBegin,maxEnd,nowBegin,nowMax;
    int a[10000];
    
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    
    max=-1;
    nowMax=0;
    maxBegin=0;
    maxEnd=0;
    nowBegin=0;
    for(i=0;i<k;i++)
    {
        nowMax+=a[i];
        #ifdef DEBUG
        printf("i=%d, nowMax=%d\n",i,nowMax);
        #endif
        if(nowMax<0)
        {
            nowBegin=i+1;
            nowMax=0;
            continue;
        }
        if(nowMax>max)
        {
            maxBegin=nowBegin;
            maxEnd=i;
            max=nowMax;
        }
    }
    
    if(max < 0)
    {
        printf("0 %d %d",a[0],a[k-1]);
    }
    else
    {
        printf("%d %d %d",max,a[maxBegin],a[maxEnd]);
    }
    return 0;
}

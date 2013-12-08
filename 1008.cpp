#include<stdio.h>

int main()
{
    int time=0;
    int now=0,n,i,m;
    
    //freopen("input.in","r",stdin);
    //freopen("output.in","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m>now)
        {
            time+=(m-now)*6+5;
        }
        else
        {
            time+=(now-m)*4+5;
        }
        now=m;
    }
    printf("%d",time);
    return 0;
}

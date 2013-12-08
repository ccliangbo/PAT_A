#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

#undef DEBUG
using namespace std;

bool isPrime(int n)
{
    if(n ==1 || n==0)
        return false;
    if(n== 2)
        return true;
    if(n%2 == 0)
        return false;
    int i;
    for(i=3;i<=(int)sqrt(n);i+=2)
        if(n%i == 0)
            return false;
    return true;
}

int dto10(char s[],int d)
{
    int i,len;
    int result=0;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        result*=d;
        result+=s[i]-'0';
    }
    return result;
}

bool isRev(int n, int d)
{
    char s[100];
    int i=0;
    while(n>0)
    {
        s[i]='0'+n%d;
        n=n/d;
        i++;
    }
    s[i]='\0';
    return isPrime(dto10(s,d));
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    
    int n,d,t1,t2,i,len;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&d);
        if(isPrime(n) && isRev(n,d))
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
        scanf("%d",&n);
    }
    return 0;
}

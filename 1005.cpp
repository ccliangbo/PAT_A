#include<stdio.h>
#include<stdlib.h>

void f(int n)
{
    int m;
    if(n<10)
    {
        if(n==0)
            printf("zero");
        else if(n==1)
            printf("one");
        else if(n==2)
            printf("two");
        else if(n==3)
            printf("three");
        else if(n==4)
            printf("four");
        else if(n==5)
            printf("five");
        else if(n==6)
            printf("six");
        else if(n==7)
            printf("seven");
        else if(n==8)
            printf("eight");
        else if(n==9)
            printf("nine");
    }
    else
    {
        f(n/10);
        n=n%10;
        if(n==0)
            printf(" zero");
        else if(n==1)
            printf(" one");
        else if(n==2)
            printf(" two");
        else if(n==3)
            printf(" three");
        else if(n==4)
            printf(" four");
        else if(n==5)
            printf(" five");
        else if(n==6)
            printf(" six");
        else if(n==7)
            printf(" seven");
        else if(n==8)
            printf(" eight");
        else if(n==9)
            printf(" nine");
        
    }
}
int main()
{
    char ch;
    char s[105];
    int n;
    int sum=0;
    
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    scanf("%s",s);
    int i=0;
    while(s[i]!='\0')
    {
        n=s[i]-'0';
        sum+=n;
        i++;
    }
    f(sum);
    return 0;
}

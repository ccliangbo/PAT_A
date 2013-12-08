#include<stdio.h>
using namespace std;

int main()
{
    float a,b,c,sum;
    int i;
    
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    sum=1;
    for(i=0;i<3;i++)
    {
        scanf("%f%f%f",&a,&b,&c);
        if(a>b && a>c)
        {
            printf("W ");
            sum*=a;
        }
        if(b>a && b>c)
        {
            printf("T ");
            sum*=b;
        }
        if(c>a && c>b)
        {
            printf("L ");
            sum*=c;
        }
    }
    sum*=0.65;
    sum=(sum-1)*2;
    printf("%.2f",sum);
    return 0;
}

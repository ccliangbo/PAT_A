#include<stdio.h>
#include<stdlib.h>

class Polynomials
{
    public:
    int exponents;
    float coefficients;
};

int main()
{
    int i,j,k1,k2,t,len;
    float f;
    bool contain;
    Polynomials a[10];
    Polynomials b[10];
    Polynomials c[20];
    Polynomials d[20];
    scanf("%d",&k1);
    for(i=0;i<k1;i++)
    {
        scanf("%d",&(a[i].exponents));
        scanf("%f",&(a[i].coefficients));
    }
    len=0;
    scanf("%d",&k2);
    for(i=0;i<k2;i++)
    {
        scanf("%d",&t);
        scanf("%f",&f);
        contain=false;
        for(j=0;j<k1;j++)
            if(a[j].exponents == t)
            {
                a[j].coefficients+=f;
                contain=true;
            }
        if(!contain)
        {
            b[len].exponents=t;
            b[len].coefficients=f;
            len++;
        }
    }
    
    //output b
    /*for(i=0;i<k2;i++)
    {
        printf(" %d %.1f",b[i].exponents,b[i].coefficients);
    }
    printf("\n\n");*/
    
    //combine sort
    k2=len;
    len=0;
    i=0;
    j=0;
    while(i<k1 && j<k2)
    {
        if(a[i].exponents > b[j].exponents)
        {
            c[len].exponents=a[i].exponents;
            c[len].coefficients=a[i].coefficients;
            i++;
        }
        else
        {
            c[len].exponents=b[j].exponents;
            c[len].coefficients=b[j].coefficients;
            j++;
        }
        len++;
    }
    if(i==k1)
    {
        while(j<k2)
        {
            c[len].exponents=b[j].exponents;
            c[len].coefficients=b[j].coefficients;
            j++;
            len++;
        }
    }
    else
    {
        while(i<k1)
        {
            c[len].exponents=a[i].exponents;
            c[len].coefficients=a[i].coefficients;
            i++;
            len++;
        }
    }
    
    k1=len;
    len=0;
    for(i=0;i<k1;i++)
    {
        if(c[i].coefficients !=0 )
        {
            d[len].exponents=c[i].exponents;
            d[len].coefficients=c[i].coefficients;
            len++;
        }
    }
    
    printf("%d",len);
    for(i=0;i<len;i++)
    {
        printf(" %d %.1f",d[i].exponents,d[i].coefficients);
    }
    
    return 0;
}

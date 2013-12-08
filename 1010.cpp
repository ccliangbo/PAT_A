#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>

#define DEBUG
using namespace std;

class BigInt
{
public:
    vector<long long int> a;
    int len;
    //0 is the least significant digit
    BigInt()
    {
        a.push_back(0);
    }
    
    BigInt& operator *=(long long int right)
    {
        int i;
        for(i=0;i<a.size();i++)
            a[i]*=right;
        return *this;
    }
    
    BigInt& operator +=(int right)
    {
        int i;
        a[0]+=right;
        i=0;
        while(i<a.size())
        {
            if(a[i]>=10)
            {
                long long int tmp=a[i]/10;
                if(i == a.size()-1)
                    a.push_back(tmp);
                else
                    a[i+1]+=tmp;
                a[i]=a[i]%10;
            }
            i++;
        }
        return *this;
    }
    
    bool operator < (const BigInt & right) const
    {
        int i;
        if(a.size()<right.a.size())
            return true;
        else if(a.size()>right.a.size())
            return false;
        for(i=a.size()-1;i>=0;i--)
        {
            if(a[i]<right.a[i])
                return true;
            else if(a[i]>right.a[i])
                return false;
        }
        return false;
    }
    
    bool operator > (const BigInt & right) const
    {
        int i;
        #ifdef DEBUG
        printf("inside >\n");
        for(i=0;i<a.size();i++)
            printf("%lld ",a[i]);
        printf("\n");
        for(i=0;i<right.a.size();i++)
            printf("%lld ",right.a[i]);
        printf("\n");
        #endif
        if(a.size()>right.a.size())
            return true;
        else if(a.size()<right.a.size())
            return false;
        for(i=a.size()-1;i>=0;i--)
        {
            if(a[i]>right.a[i])
                return true;
            else if(a[i]<right.a[i])
                return false;
        }
        return false;
    }
    
    void clear()
    {
        int i;
        a.clear();
        a.push_back(0);
    }
};
int main()
{
    char s1[15];
    char s2[15];
    char t[15];
    int tag;
    long long int radix;
    int i,n;

    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    
    //read input
    scanf("%s%s%d%lld",s1,s2,&tag,&radix);
    if(tag == 2)
    {
        strcpy(t,s1);
        strcpy(s1,s2);
        strcpy(s2,t);
    }
    
    /*if( strcmp(s1,"1") == 0 && strcmp(s2,"1") == 0)
    {
        printf("2");
        return 0;
    }*/
    #ifdef DEBUG
    printf("%s %s %d %lld\n",s1,s2,tag,radix);
    #endif
    //process the first number
    BigInt b1;
    i=0;
    while(s1[i]!='\0')
    {
        if(s1[i] >= '0' && s1[i]<='9')
            n=s1[i]-'0';
        else
            n=s1[i]-'a'+10;
        b1*=radix;
        b1+=n;
        i++;
    }
    
    //decide min radix for the second number
    long long int minR,maxR,middleR;
    char ch=0;
    i=0;
    while(s2[i]!='\0')
    {
        if(s2[i]>ch)
            ch=s2[i];
        i++;
    }
    if(ch >= '0' && ch<='9')
    {
        minR=ch-'0'+1;
    }
    else
        minR=ch-'a'+11;
        
    //decide max radix for the second number
    maxR=minR;
    BigInt b3;
    i=0;
    while(s2[i]!='\0')
    {
        if(s2[i] >= '0' && s2[i]<='9')
            n=s2[i]-'0';
        else
            n=s2[i]-'a'+10;
        b3*=maxR;
        b3+=n;
        i++;
    }
    while(b1>b3)
    {
        maxR*=2;
        #ifdef DEBUG
        printf("try maxR=%lld\n",maxR);
        #endif
        i=0;
        b3.clear();
        while(s2[i]!='\0')
        {
            if(s2[i] >= '0' && s2[i]<='9')
                n=s2[i]-'0';
            else
                n=s2[i]-'a'+10;
            b3*=maxR;
            b3+=n;
            i++;
        }
    }
    
    //binary search
    bool hasResult=false;
    while(minR<=maxR)
    {
        middleR=(minR+maxR)/2;
        #ifdef DEBUG
        printf("maxR=%lld, min$=%lld, middleR=%lld\n",maxR,minR,middleR);
        #endif
        BigInt b2;
        i=0;
        while(s2[i]!='\0')
        {
            if(s2[i] >= '0' && s2[i]<='9')
                n=s2[i]-'0';
            else
                n=s2[i]-'a'+10;
            b2*=middleR;
            b2+=n;
            i++;
        }
        
        if(b1<b2)
        {
            maxR=middleR-1;
            continue;
        }
        if(b1>b2)
        {
            minR=middleR+1;
            continue;
        }
        hasResult=true;
        break;
    }
    
    if(hasResult)
    {
        printf("%lld",middleR);
    }
    else
        printf("Impossible");
    return 0;
}

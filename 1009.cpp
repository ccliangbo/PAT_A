#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

class Term
{
public:
    int n;
    float a;
    bool operator ==(const Term & t) const
    {
        if(n == t.n)
            return true;
        return false;
    }
    bool operator < (const Term & t) const
    {
        if(n>t.n)
            return true;
        return false;
    }
};
int main()
{
    int k1,k2,k3,t,i,j;
    float f;
    vector<Term> v1,v2;
    //freopen("input.in","r",stdin);
    //freopen("output.in","w",stdout);
    scanf("%d",&k1);
    for(i=0;i<k1;i++)
    {
        scanf("%d%f",&t,&f);
        Term term;
        term.n=t;
        term.a=f;
        v1.push_back(term);
    }
    scanf("%d",&k2);
    for(i=0;i<k2;i++)
    {
        scanf("%d%f",&t,&f);
        Term term;
        term.n=t;
        term.a=f;
        for(j=0;j<k1;j++)
        {
            Term term2;
            term2.n=term.n+v1[j].n;
            term2.a=term.a*v1[j].a;
            vector<Term>::iterator it;
            it=find(v2.begin(),v2.end(),term2);
            if(it!=v2.end())
            {
                it->a+=term2.a;
                if(fabs(it->a-0)<0.001)
                    v2.erase(it);
            }
            else
            {
                v2.push_back(term2);
            }
        }
    }
    sort(v2.begin(),v2.end());
    
    k3=v2.size();
    printf("%d",k3);
    vector<Term>::iterator it;
    for(it=v2.begin();it!=v2.end();it++)
        printf(" %d %.1f",it->n,it->a);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
class Student
{
public:
    char name[10];
    int a,c,m,e;
};

int main()
{
    int n,m,i,j,score;
    char search[10];
    int rank,t_rank;
    char rank_ch;
    vector<Student> v;
    
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        Student s;
        scanf("%s%d%d%d",s.name,&s.c,&s.m,&s.e);
        s.a=s.c+s.m+s.e;
        v.push_back(s);
    }
    for(i=0;i<m;i++)
    {
        scanf("%s",search);
        vector<Student>::iterator it;
        for(it=v.begin();it!=v.end();it++)
            if(strcmp(it->name,search)==0)
                break;
        if(it==v.end())
        {
            printf("N/A\n");
        }
        else
        {
            rank=1;
            score=it->a;
            for(j=0;j<n;j++)
                if(v[j].a > score)
                    rank++;
            rank_ch='A';
            
            t_rank=1;
            score=it->c;
            for(j=0;j<n;j++)
                if(v[j].c > score)
                    t_rank++;
            if(t_rank<rank)
            {
                rank=t_rank;
                rank_ch='C';
            }
            
            t_rank=1;
            score=it->m;
            for(j=0;j<n;j++)
                if(v[j].m > score)
                    t_rank++;
            if(t_rank<rank)
            {
                rank=t_rank;
                rank_ch='M';
            }
            
            t_rank=1;
            score=it->e;
            for(j=0;j<n;j++)
                if(v[j].e > score)
                    t_rank++;
            if(t_rank<rank)
            {
                rank=t_rank;
                rank_ch='E';
            }
            
            printf("%d %c\n",rank,rank_ch);
        }
    }
    return 0;
}

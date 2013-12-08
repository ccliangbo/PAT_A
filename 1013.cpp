#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

#undef DEBUG
using namespace std;

class Road
{
public:
    int from,to;
};
int n,m,k;
int mfset[1000];
int my_rank[1000];
vector<Road> roads;

int find_set(int x)
{
    if(mfset[x] == x)
        return x;
    else
        return find_set(mfset[x]);
}

void union_set(int x,int y)
{
    #ifdef DEBUG
    int i;
    printf("inside union_set, x=%d, y=%d\nAnd the set:\n",x,y);
    for(i=1;i<=n;i++)
        printf("%d ",mfset[i]);
    printf("\n");
    #endif
    x=find_set(x);
    y=find_set(y);
    if(x == y)
        return;
    if(my_rank[x] > my_rank[y])
    {
        mfset[y]=x;
    }
    else if(my_rank[x] < my_rank[y])
    {
        mfset[x] = y;
    }
    else
    {
        mfset[y]=x;
        my_rank[x]++;
    }
}

int find_parts(int dead)
{
    int result=1;
    int i,seed;
    if(dead == 1)
    {
        seed = 2;
    }
    else
        seed =1;
    for(i=1;i<=n;i++)
        if(i!=seed && i!=dead && find_set(seed)!=find_set(i))
        {
            union_set(seed,i);
            result++;
        }
    return result;
}
int main()
{
    int i,j,from,to,dead;
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        Road r;
        scanf("%d%d",&from,&to);
        r.from=from;
        r.to=to;
        roads.push_back(r);
    }
    
    for(i=0;i<k;i++)
    {
        scanf("%d",&dead);
        for(j=1;j<=n;j++)
        {
            mfset[j]=j;
            my_rank[j]=0;
        }
        #ifdef DEBUG
        printf("before merge\n");
        #endif
        for(j=0;j<roads.size();j++)
        {
            if(roads[j].from !=dead && roads[j].to != dead)
                union_set(roads[j].from,roads[j].to);
        }
        #ifdef DEBUG
        printf("after merge\n");
        #endif
        printf("%d\n",find_parts(dead)-1);
    }
    return 0;
}

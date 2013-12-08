#include<stdio.h>
#include<vector>

using namespace std;

class Node{
public:
    bool hasChild;
    bool isChild[100];
    };
int main()
{
    int n,m;
    int i,j,k;
    int id,child;
    int count;

    Node tree[100];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        tree[i].hasChild=false;
        for(j=1;j<=n;j++)
            tree[i].isChild[j]=false;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&id,&k);
        tree[id].hasChild=true;
        for(j=0;j<k;j++)
        {
            scanf("%d",&child);
            tree[id].isChild[child]=true;
        }
    }
    
    vector<int> v1;
    vector<int> v2;
    int now=1;
    v1.push_back(1);
    bool firstOut=true;
    
    while(!v1.empty() || !v2.empty())
    {
        if(now == 1)
        {
            int count=0;
            vector<int>::iterator it;
            for(it=v1.begin();it!=v1.end();it++)
            {
                if(tree[*it].hasChild)
                {
                    for(i=1;i<=n;i++)
                        if(tree[*it].isChild[i])
                            v2.push_back(i);
                }
                else
                    count++;
            }
            if(firstOut)
            {
                printf("%d",count);
                firstOut=false;
            }
            else
                printf(" %d",count);
            now=-now;
            v1.clear();
        }
        else
        {
            //now == -1
            int count=0;
            vector<int>::iterator it;
            for(it=v2.begin();it!=v2.end();it++)
            {
                if(tree[*it].hasChild)
                {
                    for(i=1;i<=n;i++)
                        if(tree[*it].isChild[i])
                            v1.push_back(i);
                }
                else
                    count++;
            }
            if(firstOut)
            {
                printf("%d",count);
                firstOut=false;
            }
            else
                printf(" %d",count);
            now=-now;
            v2.clear();
        }
    }
    return 0;
}

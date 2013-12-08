#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
#undef DEBUG

using namespace std;

int n,m,c1,c2;
int map[500][500];

class City{
public:
    int man;
    int maxMan;
    int numberOfPath;
};

int main()
{
    int i,j;
    int from,to,weight;
    //read input
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    
    #ifdef DEBUG
    printf("after reading,n=%d,m=%d,c1=%d,c2=%d\n",n,m,c1,c2);
    #endif
    City *cities= new City[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&(cities[i].man));
        cities[i].maxMan=cities[i].man;
        cities[i].numberOfPath=0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            map[i][j]=-1;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&from,&to,&weight);
        map[to][from]=weight;
        map[from][to]=weight;
    }
        
    //shortest path
    cities[c1].maxMan = cities[c1].man;
    map[c1][c1]= -1;
    cities[c1].numberOfPath = 1;
    
    set<int> s1;
    s1.insert(c1);
    set<int> s2;
    for(i=0;i<n;i++)
    {
        if(i!=c1)
            s2.insert(i);
    }
    int newcomer=c1;
    while(s1.find(c2) == s1.end())
    {
        #ifdef DEBUG
        printf("--------------\nnewcomer=%d\n",newcomer);
        #endif
        for(i=0;i<n;i++)
        {
            if(map[newcomer][i] != -1)
                if(map[c1][i] == -1)
                {
                    map[c1][i]=map[c1][newcomer]+map[newcomer][i];
                    #ifdef DEBUG
                    printf("new path %d to %d = %d\n",c1,i,map[c1][i]);
                    #endif
                    cities[i].maxMan=cities[newcomer].maxMan+cities[i].man;
                    cities[i].numberOfPath=cities[newcomer].numberOfPath;
                }
                else if(map[c1][i] > map[c1][newcomer]+map[newcomer][i])
                {
                    map[c1][i]=map[c1][newcomer]+map[newcomer][i];
                    #ifdef DEBUG
                    printf("update path %d to %d = %d\n",c1,i,map[c1][i]);
                    #endif
                    cities[i].maxMan=cities[newcomer].maxMan+cities[i].man;
                    cities[i].numberOfPath=cities[newcomer].numberOfPath;
                }
                else if(map[c1][i] == map[c1][newcomer]+map[newcomer][i])
                {
                    #ifdef DEBUG
                    printf("equal path %d to %d = %d\n",c1,i,map[c1][i]);
                    #endif
                    if(cities[i].maxMan<cities[newcomer].maxMan+cities[i].man)
                    {
                        #ifdef DEBUG
                        printf("touch maxMan\n");
                        #endif
                        cities[i].maxMan=cities[newcomer].maxMan+cities[i].man;
                    }
                    cities[i].numberOfPath+=cities[newcomer].numberOfPath;
                    #ifdef DEBUG
                    printf("city %d, maxMan=%d, numberOfPath=%d\n",i,cities[i].maxMan,cities[i].numberOfPath);
                    #endif
                }
        }
        
        bool hasNewcomer=false;
        set<int>::iterator sit;
        for(sit=s2.begin();sit!=s2.end();sit++)
        {
            if(map[c1][*sit]!=-1)
            {
                if(hasNewcomer)
                {
                    if(map[c1][*sit] < map[c1][newcomer])
                        newcomer=*sit;
                }
                else
                {
                    newcomer=*sit;
                    hasNewcomer=true;
                }
            }
        }
        
        s1.insert(newcomer);
        s2.erase(newcomer);
    }
    
    #ifdef DEBUG
    printf("shortest path %d to %d = %d\n",c1,c2,map[c1][c2]);
    #endif
    printf("%d %d",cities[c2].numberOfPath,cities[c2].maxMan);
    return 0;  
}

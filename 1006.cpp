#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class MyTime{
public:
    int hour,minute,second;
    bool operator <(const MyTime & t) const
    {
        if(hour<t.hour)
            return true;
        else if(hour == t.hour && minute < t.minute)
            return true;
        else if(hour == t.hour && minute == t.minute && second < t.second)
            return true;
        return false;
    }
};

class Record
{
public:
    char name[20];
    MyTime in,out;
    void print()
    {
        printf("%s %d:%d:%d %d:%d:%d\n",name,in.hour,in.minute,in.second,out.hour,out.minute,out.second);
    }
};

bool lessIn(const Record & r1, const Record & r2)
{
    if(r1.in < r2.in)
        return true;
    return false;
}

bool lessOut(const Record & r1, const Record & r2)
{
    if(r1.out < r2.out)
        return true;
    return false;
}
int main()
{
    int n,i,h,m,s;
    char str[20];
    
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    
    vector<Record> v;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Record r;
        scanf("%s",r.name);
        scanf("%d:%d:%d",&h,&m,&s);
        r.in.hour=h;
        r.in.minute=m;
        r.in.second=s;
        scanf("%d:%d:%d",&h,&m,&s);
        r.out.hour=h;
        r.out.minute=m;
        r.out.second=s;
        v.push_back(r);
    }
    
    sort(v.begin(),v.end(),lessIn);
    printf("%s ",v[0].name);
    sort(v.begin(),v.end(),lessOut);
    vector<Record>::iterator it=v.end();
    it--;
    printf("%s",it->name);
    //v[0].print();
    return 0;
}

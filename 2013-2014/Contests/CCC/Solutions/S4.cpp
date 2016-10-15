#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct seg
{
    int x,y1,y2,val;
    seg()
    {

    }
    seg(int a,int b,int c,int d)
    {
        x=a,y1=b,y2=c,val=d;
    }
}point[3001];
int n,c,t,indy,len,ind,val;
int segy[3001],x1,y1,x2,y2;
long long ans,line[3001];

int findy(int x)
{
    int l=1,h=len;
    while(l<h)
    {
        int mid=(l+h)>>1;
        if(segy[mid]>=x)
            h=mid;
        else
            l=mid+1;
    }
    return l;
}
bool cmp(seg p1,seg p2)
{
    return p1.x<p2.x;
}
int main()
{
    //freopen("s4.txt","r",stdin);
    scanf("%d%d",&n,&t);
    indy=ind=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
        point[ind++]=seg(x1,y1,y2,val);
        point[ind++]=seg(x2,y1,y2,-val);
        segy[indy++]=y1;
        segy[indy++]=y2;
    }
    sort(point+1,point+ind,cmp);
    sort(segy+1,segy+indy);
    len=unique(segy+1,segy+indy)-(segy+1);
    for(int i=1;i<ind;i++)
    {
        for(int j=1;j<len;j++)
            if(line[j]>=t)
                ans+=(long long)(segy[j+1]-segy[j])*(point[i].x-point[i-1].x);
        for(int j=findy(point[i].y1);j<findy(point[i].y2);j++)
            line[j]+=point[i].val;
    }
    printf("%lld\n",ans);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,ind,dp[2001],l,r,pos;
pair<int,int>cord[2001],temp[25001];
pair<int,pair<int,int> >dis[4000002];
int dist(pair<int,int>a,pair<int,int>b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main()
{
    //freopen("s5.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&cord[i].first,&cord[i].second);
        for(int j=0;j<i;j++)
        {
            if(j!=0)
                dis[ind++]=make_pair(-dist(cord[i],cord[j]),make_pair(i,j));
            dis[ind++]=make_pair(-dist(cord[j],cord[i]),make_pair(j,i));
        }
    }
    sort(dis,dis+ind);
    fill(dp+1,dp+n+1,-1e6);
    for(int l=0,r;l<ind;l=r+1)
    {
        r=l;
        while(r<ind-1&&dis[l].first==dis[r+1].first)
            r++;
        pos=0;
        for(int j=l;j<=r;j++)
        {
            temp[pos].first=dp[dis[j].second.first]+1;
            temp[pos++].second=dis[j].second.second;
        }
        for(int j=0;j<pos;j++)
            if(temp[j].first>dp[temp[j].second])
                dp[temp[j].second]=temp[j].first;
    }
    printf("%d\n",*max_element(dp+1,dp+n+1));
    return 0;
}

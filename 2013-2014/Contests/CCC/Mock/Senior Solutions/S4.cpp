#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int n,m,a,b,u,dfn[40001],low[40001],id[40001],set[40001],r[40001],ind;
vector<int>graph[40001];
stack<int>st;
bool flag[40001],done;

int find(int x)
{
    if(x!=set[x])
        set[x]=find(set[x]);
    return set[x];
}
void merge(int a,int b)
{
    int fa=find(a);
    int fb=find(b);
    if(fa==fb)
        return;
    if(r[fa]>r[fb])
        set[fb]=fa;
    else
    {
        set[fa]=fb;
        if(r[fa]==r[fb])
            r[fb]++;
    }
}
void tarjan(int u,int w)
{
    dfn[u]=low[u]=++ind;
    st.push(u);
    flag[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(v==w)
            continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(flag[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        for(int v=-1;v!=u;)
        {
            v=st.top();
            st.pop();
            flag[v]=false;
            merge(u,v);
        }
    }
}
void dfs(int u)
{
    flag[u]=true;
    dfn[find(u)]++;
    if(u==n)
    {
        memset(flag,true,sizeof(flag));
        return;
    }
    for(int v=0;v<graph[u].size();v++)
        if(!flag[graph[u][v]])
            dfs(graph[u][v]);
    if(!flag[0])
        dfn[find(u)]--;
}
int main()
{
    //freopen("DATA.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        set[i]=i;
        r[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,-1);
    memset(dfn,0,sizeof(dfn));
    dfs(1);
    for(int i=1;i<=n;i++)
        if(dfn[i]>1)
        {
            done=true;
            break;
        }
    if(done)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

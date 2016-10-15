#include <cstdio>
#include <string.h>

using namespace std;

int n,m,a[101][101],b[2][101],lin[101],ans;
bool flag[101],graph[101][101];

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
bool dfs(int u)
{
    for(int v=1;v<=m;v++)
        if(graph[u][v]&&!flag[v])
        {
            flag[v]=true;
            if(!lin[v]||dfs(lin[v]))
            {
                lin[v]=u;
                return true;
            }
        }
    return false;
}
int main()
{
    //freopen("s5.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&b[0][i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[1][i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(gcd(b[0][i],b[1][j])>1)
                graph[i+1][j+1]=true;
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(dfs(i))
            ans++;
    }
    printf("%d\n",ans*2);
    return 0;
}

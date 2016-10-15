#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r,c,n,x;

bool cmp(vector<int> a,vector<int> b)
{
    return a[x]<b[x];
}
int main()
{
    //freopen("s3.txt","r",stdin);
    scanf("%d%d",&r,&c);
    vector<vector<int> >a(r,vector<int>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        x--;
        stable_sort(a.begin(),a.end(),cmp);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,a,ind=0,skip=0;
string name;
pair<int,string>data[101];

bool cmp(pair<int,string>a1,pair<int,string>a2)
{
    if(a1.first>a2.first)
        return true;
    if(a1.first==a2.first&&a1.second<a2.second)
        return true;
    return false;
}
int main()
{
    freopen("DATA.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name;
        cin>>a;
        data[i]=make_pair(a,name);
    }
    sort(data,data+n,cmp);
    while(ind<n)
    {
        cout<<ind+1<<" "<<data[ind+skip].second<<endl;
        skip++;
        while(ind+skip<n&&data[ind+skip].first==data[ind].first)
        {
            cout<<ind+1<<" "<<data[ind+skip].second<<endl;
            skip++;
        }
        ind+=skip;
        skip=0;
    }
    return 0;
}

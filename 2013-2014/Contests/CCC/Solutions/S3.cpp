#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

int t,n,a,cur;
stack<int>st,br;
bool once;

int main()
{
    //freopen("s3.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        while(!st.empty())
            st.pop();
        while(!br.empty())
            br.pop();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            st.push(a);
        }
        cur=1;
        while(true)
        {
            once=false;
            while(!st.empty()&&st.top()==cur)
            {
                st.pop();
                cur++;
                once=true;
            }
            while(!br.empty()&&br.top()==cur)
            {
                br.pop();
                cur++;
                once=true;
            }
            while(!st.empty()&&st.top()!=cur)
            {
                a=st.top();
                st.pop();
                br.push(a);
                once=true;
            }
            if(!once)
                break;
        }
        if(cur==n+1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

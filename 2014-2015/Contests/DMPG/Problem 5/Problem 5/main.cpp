#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// black - 0
// white - 1
struct seg
{
	int x,y1,y2;
	bool operator <(const seg a)const
	{
		return x<a.x;
	}
};
struct node
{
	int left,right,mid,val;
	bool flip;
}tree[40001];
void build(int low,int high,int node)
{
	tree[node].left=low;
	tree[node].right=high;
	tree[node].mid=(low+high)>>1;
	tree[node].val=0;
	if(low!=high)
	{
		build(low,tree[node].mid,node<<1);
		build(tree[node].mid+1,high,node<<1|1);
	}
}
void pushdown(int node)
{
	if(tree[node].flip)
	{
		tree[node<<1].flip^=1;
		tree[node<<1].val=tree[node<<1].right-tree[node<<1].left+1-tree[node<<1].val;
		tree[node<<1|1].flip^=1;
		tree[node<<1|1].val=tree[node<<1|1].right-tree[node<<1|1].left+1-tree[node<<1|1].val;
		tree[node].flip^=1;
	}
}
void update(int l,int r,int node)
{
	if(tree[node].left==l&&tree[node].right==r)
	{
		tree[node].val=(r-l+1)-tree[node].val;
		tree[node].flip^=1;
		return;
	}
	pushdown(node);
	if(r<=tree[node].mid)
		update(l,r,node<<1);
	else if(l>=tree[node].mid+1)
		update(l,r,node<<1|1);
	else
	{
		update(l,tree[node].mid,node<<1);
		update(tree[node].mid+1,r,node<<1|1);
	}
	tree[node].val=tree[node<<1].val+tree[node<<1|1].val;
}
vector<seg>line;
int pos,ans;

int main() {
	//freopen("in2.txt", "r", stdin);
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; i++) {
		int x, y, w, h;
		scanf("%d %d %d %d", &x, &y, &w, &h);
		x++,y++;
		line.push_back(seg{x,y,y+h-1});
		line.push_back(seg{x+w,y,y+h-1});
	}
	sort(line.begin(),line.end());
	build(1,N,1);
	pos=line[0].x;
	for(int i=0;i<line.size();i++)
	{
		ans+=tree[1].val*(line[i].x-pos);
		update(line[i].y1,line[i].y2,1);
		pos=line[i].x;
	}
	printf("%d\n",ans);
    return 0;
}

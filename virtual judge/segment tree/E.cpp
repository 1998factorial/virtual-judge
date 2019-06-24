#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
//#include <unordered_set>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int maxn=1e5+10;
//lazy propagation
struct node{
	int l,r,id;
}tree[maxn<<3];
int n,q,ret;

void push_down(int i){
	if(tree[i].id!=-1){
		tree[i<<1].id=tree[i].id;
		tree[i<<1|1].id=tree[i].id;
		tree[i].id=-1;
	}
}

void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].id=-1;
	if(l!=r){
		int m=(l+r)>>1;
		build(i<<1,l,m);
		build(i<<1|1,m+1,r);
	}
}

void update(int i,int l,int r,int v){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].id=v;
	}
	else{
		push_down(i);
		int m=(tree[i].l+tree[i].r)>>1;
		if(m>=r)update(i<<1,l,r,v);
		else if(m<l)update(i<<1|1,l,r,v);
		else{
			update(i<<1,l,m,v);
			update(i<<1|1,m+1,r,v);
		}
	}
}

int query(int i,int l,int r){
	if(tree[i].id!=-1&&tree[i].l>=l&&tree[i].r<=r)
		return tree[i].id*(tree[i].r-tree[i].l+1);
	int ans=0;
	int m=(tree[i].l+tree[i].r)>>1;
	if(m>=r)return query(i<<1,l,r);
	else if(m<l)return query(i<<1|1,l,r);
	return query(i<<1,l,m)+query(i<<1|1,m+1,r);
}

void show(int i){
	printf("[%d %d]->%d\n",tree[i].l,tree[i].r,tree[i].id);
	if(tree[i].l!=tree[i].r){
		show(i<<1);
		show(i<<1|1);
	}
}

int main(){
	int _,cc=1;scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%d",&q);
		build(1,1,n);
		tree[1].id=1;
		REP(i,0,q){
			int l,r,v;
			scanf("%d %d %d",&l,&r,&v);
			update(1,l,r,v);
		}
		ret=query(1,1,n);
		printf("Case %d: The total value of the hook is %d.\n",cc++,ret);
	}
	return 0;
}
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
//lazy propagation
const int maxn=1e5+10;
int n,q,a[maxn];

struct node{
	int l,r,m;
	ll sum,lazy;
}tree[maxn<<2]; //size x 4!

void init(int id,int l,int r){
	tree[id].l=l;
	tree[id].r=r;
	tree[id].m=(l+r)>>1;
	tree[id].lazy=0;
	if(l==r)
		tree[id].sum=a[l];
	else{
		int m=(l+r)>>1;
		init(id<<1,l,m);
		init(id<<1|1,m+1,r);
		tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
	}
}

ll query(int id,int l,int r){
	if(tree[id].l==l&&tree[id].r==r)//good segment
		return tree[id].sum+tree[id].lazy*(r-l+1);
	if(tree[id].lazy){//propagate down
		tree[id<<1].lazy+=tree[id].lazy;
		tree[id<<1|1].lazy+=tree[id].lazy;
		tree[id].sum+=tree[id].lazy*(tree[id].r-tree[id].l+1);
		tree[id].lazy=0ll;
	}
	if(tree[id].m>=r)
		return query(id<<1,l,r);
	else if(tree[id].m<l)
		return query(id<<1|1,l,r);
	return query(id<<1,l,tree[id].m)+query(id<<1|1,tree[id].m+1,r);
}

void update(int id,int l,int r,int val){
//all elements in [l,r] are increased by val
//always make sure that the current tree node includes [l,r]
	if(tree[id].l==l&&tree[id].r==r)
		tree[id].lazy+=val;//propagate down when query
	else{
		tree[id].sum+=1ll*(r-l+1)*val;
		if(tree[id].m>=r)
			update(id<<1,l,r,val);//focus on the left part
		else if(tree[id].m<l)
			update(id<<1|1,l,r,val);//focus on the right part
		else{//内包含
			update(id<<1,l,tree[id].m,val);
			update(id<<1|1,tree[id].m+1,r,val);
		}
	}
}


int main(){
	while(~scanf("%d %d",&n,&q)){
		REP(i,1,n+1)scanf("%d",&a[i]);
		init(1,1,n);
		REP(i,0,q){
			string tt;
			cin>>tt;
			if(tt=="Q"){
				int l,r;
				scanf("%d %d",&l,&r);
				cout<<query(1,l,r)<<'\n';
			}
			else if(tt=="C"){
				int l,r,v;
				scanf("%d %d %d",&l,&r,&v);
				update(1,l,r,v);
			}
		}
	}
	return 0;
}
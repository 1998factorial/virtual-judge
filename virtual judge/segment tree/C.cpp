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
//区间更新，若仍然使用单点更新必然超时
//lazy propagation
//mark为懒惰更新值
const int maxn=1e5+10;
struct node{
	int l,r,m;
	ll sum,mark;
}tree[maxn<<2];
int a[maxn],n,q;

void init(int id,int l,int r){
	tree[id].l=l;tree[id].r=r;tree[id].m=(l+r)>>1;
	tree[id].mark=0;
	if(l==r){
		tree[id].sum=1ll*a[l];
	}
	else{
		int m=(l+r)>>1;
		init(id<<1,l,m);init(id<<1|1,m+1,r);
		tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
	}
}

ll query(int id,int l,int r){
	//printf("%d,%d,%d\n",id,l,r);
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum+tree[id].mark*(r-l+1);
	if(tree[id].mark){
		//need to propagate down
		tree[id<<1].mark+=tree[id].mark;
		tree[id<<1|1].mark+=tree[id].mark;
		tree[id].sum+=(tree[id].r-tree[id].l+1)*tree[id].mark;
		tree[id].mark=0;
	}
	if(tree[id].m>=r)return query(id<<1,l,r);
	else if(tree[id].m<l)return query(id<<1|1,l,r);
	else return query(id<<1,l,tree[id].m)+query(id<<1|1,tree[id].m+1,r);
}

void update(int id,int l,int r,int val){
	if(tree[id].l==l&&tree[id].r==r) //this is the range that we want
		tree[id].mark+=1ll*val;
	else{
		tree[id].sum+=1ll*val*(r-l+1); 
		if(tree[id].m>=r)
			update(id<<1,l,r,val);
		else if(tree[id].m<l)
			update(id<<1|1,l,r,val);
		else{
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
			string task;
			cin>>task;
			if(task=="Q"){
				int l,r;
				scanf("%d %d",&l,&r);
				cout<<query(1,l,r)<<endl;
			}
			if(task=="C"){
				int l,r,v;
				scanf("%d %d %d",&l,&r,&v);
				update(1,l,r,v);
			}
		}
	}
	return 0;
}
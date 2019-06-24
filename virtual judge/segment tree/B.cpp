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
#include <unordered_set>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int maxn=2e5+5;
const int INF=1<<30;
int n,m,a[maxn],tree[maxn<<1];

void init(int l,int r,int k){
	if(l==r)tree[k]=a[l];
	else{
		init(l,(l+r)/2,k<<1);init((l+r)/2+1,r,k<<1|1);
		tree[k]=max(tree[k<<1],tree[k<<1|1]);
	}
}

int find(int a,int b,int k,int l,int r){
	if(r<a||l>b)return -INF;
	if(a<=l&&b>=r)return tree[k];
	return max(find(a,b,k<<1,l,(l+r)/2),find(a,b,k<<1|1,(l+r)/2+1,r));
}

void update(int pos,int val,int l,int r,int x){
	if(l==r)tree[x]=val;
	else{
		int m=(l+r)/2;
		if(pos<=m)update(pos,val,l,m,x<<1);
		else update(pos,val,m+1,r,x<<1|1);
		tree[x]=max(tree[x<<1],tree[x<<1|1]);
	}
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		REP(i,0,n)scanf("%d",&a[i]);
		FILL(tree,0);
		init(0,n-1,1);
		REP(j,0,m){
			string task;int l,r;
			cin>>task>>l>>r;
			if(task=="Q"){//query
				if(l>r)swap(l,r);
				printf("%d\n",find(l-1,r-1,1,0,n-1));
			}
			if(task=="U"){//update
				update(l-1,r,0,n-1,1);
			}
		}
	}
	return 0;
}
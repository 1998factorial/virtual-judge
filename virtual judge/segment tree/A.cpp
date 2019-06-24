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
const int maxn=5e5+5;
int a[maxn],n,tree[maxn<<1];

void init(int i,int j,int x){
	//二分法建树
	if(i==j)tree[x]=a[i];
	else{
		int m=(i+j)/2;
		init(i,m,x<<1);
		init(m+1,j,x<<1|1);
		tree[x]=tree[x<<1]+tree[x<<1|1];
	}
}

int find(int a,int b,int k,int x,int y){
	//查找“好区间”
	if(y<a||x>b)return 0;
	if(a<=x&&b>=y)return tree[k];
	return find(a,b,k<<1,x,(x+y)/2)+find(a,b,k<<1|1,(x+y)/2+1,y);
}

void add(int p,int val,int l,int r,int x){
	//注意单点更新即可
	if(l==r)tree[x]+=val;
	else{
		int m=(l+r)/2;
		if(p<=m)add(p,val,l,m,x<<1);
		else add(p,val,m+1,r,x<<1|1);
		tree[x]=tree[x<<1]+tree[x<<1|1];
	}
}

void sub(int p,int val,int l,int r,int x){
	if(l==r)tree[x]-=val;
	else{
		int m=(l+r)/2;
		if(p<=m)sub(p,val,l,m,x<<1);
		else sub(p,val,m+1,r,x<<1|1);
		tree[x]=tree[x<<1]+tree[x<<1|1];
	}
}

int main(){
	int _,l,r;cin>>_;
	for(int ccc=1;ccc<=_;ccc++){
		printf("Case %d:\n",ccc);
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		FILL(tree,0);
		init(0,n-1,1);
		string cmd="";
		while(cmd!="End"){
			cin>>cmd;
			if(cmd=="End")break;
			scanf("%d %d",&l,&r);
			if(cmd=="Query"){
				if(l>r)swap(l,r);
				--l,--r;
				cout<<find(l,r,1,0,n-1)<<endl;
			}
			if(cmd=="Add"){
				add(l-1,r,0,n-1,1);
			}
			if(cmd=="Sub"){
				sub(l-1,r,0,n-1,1);
			}
		}
	}
	return 0;
}
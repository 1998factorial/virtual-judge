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

//输入的l，r可以很大，故需要将数据离散化
//1<=n<=10000 so li,ri will have at most 20000 distinct values
const int maxn=1e5+10;
struct segmentTree{
  int l,r,id;
}tree[maxn<<3];
struct poster{
  int l,r;
}p[maxn];
int n,a[maxn<<1],seg[maxn<<2],ret;
bool seen[maxn<<2];

void push_down(int i){
  tree[i<<1].id=tree[i].id;
  tree[i<<1|1].id=tree[i].id;
  tree[i].id=-1;
}

void query(int i,int l,int r){
  if(tree[i].id!=-1){//as this node will 
    if(!seen[tree[i].id]){
      seen[tree[i].id]=true;
      ret++;
    }
    tree[i].id=-1;
    return;
  }
  if(l==r)return;
  int m=(tree[i].l+tree[i].r)>>1;
  if(m>=r)query(i<<1,l,r);
  else if(m<l)query(i<<1|1,l,r);
  else{
    query(i<<1,l,m);
    query(i<<1|1,m+1,r);
  }
}

void update(int i,int l,int r,int id){
  //lazy update
  if(tree[i].l==l&&tree[i].r==r){
    tree[i].id=id;//if good segment then we are done
  }
  else{
    //this [l,r] is partially/fully covered by this segment
    if(tree[i].id!=-1)
      push_down(i);//lazy down
    int m=(tree[i].l+tree[i].r)>>1;
    if(m>=r)//focus on the left child
      update(i<<1,l,r,id);
    else if(m<l)//focus on the right child
      update(i<<1|1,l,r,id);
    else{//shrink towords the mid point
      update(i<<1,l,m,id);
      update(i<<1|1,m+1,r,id);
    }
  }
}

void show(int i){
  printf("[%d,%d]->%d\n",tree[i].l,tree[i].r,tree[i].id);
  if(tree[i].l!=tree[i].r)show(i<<1),show(i<<1|1);
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

int search(int l,int r,int val){//compute lower bound
  int m;
  while(l<=r){
    m=(l+r)>>1;
    if(val==seg[m])return m;
    else if(val<seg[m])r=m-1;
    else l=m+1;
  }
  return l;
}

int main(){
  int _;scanf("%d",&_);
  while(_--){
    scanf("%d",&n);
    int m=0;
    //离散化处理
    FILL(seen,0);
    REP(i,0,n){
      scanf("%d %d",&p[i].l,&p[i].r);
      a[m++]=p[i].l;
      a[m++]=p[i].r;
    }
    //排序
    sort(a,a+m);
    int mm=0;
    seg[mm++]=a[0];
    REP(i,1,m)//去重复
      if(a[i]!=a[i-1])seg[mm++]=a[i];
    for(int i=mm-1;i>0;--i){//加入poster 与 poster之间的间隔
      if(seg[i]-seg[i-1]>1)seg[mm++]=seg[i-1]+1;
    }
    sort(seg,seg+mm);
    build(1,1,mm);
    REP(i,0,n){
      int x=search(0,mm-1,p[i].l)+1;//lower_bound(seg,seg+mm,p[i].l)-seg+1;
      int y=search(0,mm-1,p[i].r)+1;//lower_bound(seg,seg+mm,p[i].r)-seg+1;
      update(1,x,y,i);//using lazy propagation to update segments
    }
    ret=0;
    query(1,1,mm);
    cout<<ret<<endl;
  }
  return 0;
}
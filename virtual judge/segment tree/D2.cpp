#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
const int maxn=11111;
 
struct node1
{
    int l,r,id;
}segTree[maxn*16+5];
struct node2
{
    int l,r;
}poster[maxn+5];
bool vis[10010];
int seg[4*maxn+5];
int ans;
void push_down(int i)
{
    if(segTree[i].id!=-1){
        segTree[i<<1].id=segTree[i].id;
        segTree[(i<<1)|1].id=segTree[i].id;
        segTree[i].id=-1;
    }
}

void build(int i,int l,int r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].id=-1;
    if(l==r)return;
    int mid=(l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}
 
void update(int i,int l,int r,int id)
{
    if(segTree[i].l==l&&segTree[i].r==r){
        segTree[i].id=id;
        return;
    }
    push_down(i);
    int mid=(segTree[i].l+segTree[i].r)/2;
    if(r<=mid)update(i<<1,l,r,id);
    else if(mid<l)update((i<<1)|1,l,r,id);
    else{
        update(i<<1,l,mid,id);
        update((i<<1)|1,mid+1,r,id);
    }
}
 
void query(int i,int l,int r)
{
    if(segTree[i].id!=-1){//不用判断区间，之间检查染色情况
        if(!vis[segTree[i].id]){
            vis[segTree[i].id]=true;
            ans++;
        }
        segTree[i].id=-1;
        return;
    }
    if(l==r)return;
    push_down(i);
    int mid=(segTree[i].l+segTree[i].r)/2;
    if(r<=mid)query(i<<1,l,r);
    else if(l>mid)return query((i<<1)|1,l,r);
    else {
        query(i<<1,l,mid);
        query((i<<1)|1,mid+1,r);
    }
}
 
int BSearch(int low,int high,int num)
{
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(num==seg[mid])return mid;
        else if(seg[mid]>num)high=mid-1;
        else low=mid+1;
    }
    return low;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    int c,n,cnt,m;
    scanf("%d",&c);
    while(c--){
        memset(vis,0,sizeof(vis));
        cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&poster[i].l,&poster[i].r);
            seg[cnt++]=poster[i].l;seg[cnt++]=poster[i].r;
        }
        sort(seg,seg+cnt);
        m=1;
        for(int i=1;i<cnt;i++)
            if(seg[i]!=seg[i-1])seg[m++]=seg[i];
        for(int i=m-1;i>=1;i--)
            if(seg[i]-seg[i-1]>1)seg[m++]=seg[i-1]+1;
        sort(seg,seg+m);
        build(1,1,m);
        for(int i=0;i<n;i++){
            int l=BSearch(0,m-1,poster[i].l);//利用二分查找离散处理后的位置
            int r=BSearch(0,m-1,poster[i].r);
            update(1,l+1,r+1,i);
        }
        ans=0;
        query(1,1,m);
        printf("%d\n",ans);
    }
    return 0;
}
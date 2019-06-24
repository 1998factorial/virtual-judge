#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <set>
#include <list>
#include <iostream>
#define ll long long
#define ull unsigned long long
#define cls(x) memset(x,0,sizeof(x))
#define clslow(x) memset(x,-1,sizeof(x))
#define INF  0x3f3f3f3f
//typedef long long ll;
using namespace std;
const int maxn=1e5+100;
const int mod=1e9+7;

int lazy[maxn<<2];

void Push_down(int rt)
{
    if(lazy[rt]){
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1]=lazy[rt];
        lazy[rt]=0;
    }
}

void Update(int L,int R,int l,int r,int rt,int c)
{
    if(L<=l && r<=R)
    {
        lazy[rt]=c;
        return;
    }
    Push_down(rt);
    int mid=(l+r)>>1;
    if(L<=mid)Update(L,R,l,mid,rt<<1,c);
    if(R>mid)Update(L,R,mid+1,r,rt<<1|1,c);
}

int Query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R && lazy[rt]>0){
        return lazy[rt]*(r-l+1);//查询到有懒惰标记，直接返回计算的值就好了
    }
    int ANS=0;
    int mid=(l+r)>>1;
    if(L<=mid)ANS+=Query(L,R,l,mid,rt<<1);
    if(R>mid)ANS+=Query(L,R,mid+1,r,rt<<1|1);
    return ANS;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d",&n);
        Update(1,n,1,n,1,1);//因为刚开始全是1，所以这里就是初始化
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            Update(u,v,1,n,1,c);
        }
        cout<<"Case "<<cas++<<": The total value of the hook is "<<Query(1,n,1,n,1)<<"."<<endl;
    }

    return 0;
}

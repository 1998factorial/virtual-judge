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
//#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int N,xi,yi,MAX,INF=1<<30;
struct platform{
	int l,r,h;
	friend bool operator<(platform a,platform b)
	{return a.h<b.h;}
}a[1005];
int dp[1005][2];

int main(){
	int _;cin>>_;
	while(_--){
		cin>>N>>xi>>yi>>MAX;
		for(int i=1;i<=N;++i)cin>>a[i].l>>a[i].r>>a[i].h;
		a[N+1].l=a[N+1].r=xi;a[N+1].h=yi;
		a[0].l=-INF;a[0].r=INF;a[0].h=0;
		sort(a+1,a+N+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N+1;++i){
			bool ll=false,rr=false;
			for(int j=i-1;j>=0&&a[i].h-a[j].h<=MAX;--j)
				if(a[i].l>=a[j].l&&a[i].l<=a[j].r){//left
					ll=true;
					if(!j)dp[i][0]=a[i].h;
					else dp[i][0]=a[i].h-a[j].h+min(dp[j][0]+a[i].l-a[j].l,dp[j][1]+a[j].r-a[i].l);
					break;
				}
			if(!ll)dp[i][0]=INF;
			for(int j=i-1;j>=0&&a[i].h-a[j].h<=MAX;--j)
				if(a[i].r>=a[j].l&&a[i].r<=a[j].r){//right
					rr=true;
					if(!j)dp[i][1]=a[i].h;
					else dp[i][1]=a[i].h-a[j].h+min(dp[j][0]+a[i].r-a[j].l,dp[j][1]+a[j].r-a[i].r);
					break;
				}
			if(!rr)dp[i][1]=INF;
		}
		printf("%d\n",min(dp[N+1][0],dp[N+1][1]));
	}
	return 0;
}





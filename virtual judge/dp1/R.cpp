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

int N,M,R,dp[1005];

struct it{
	int ti,tf,e;
	friend bool operator<(it a,it b){
		return a.ti<b.ti;
	}
}a[1005];

int main(){
	while(~scanf("%d %d %d",&N,&M,&R)){
		for(int i=0;i<M;i++)
			scanf("%d %d %d",&a[i].ti,&a[i].tf,&a[i].e);
		sort(a,a+M);
		memset(dp,0,sizeof(dp));
		int ret=0;
		for(int i=0;i<M;i++){
			dp[i]=a[i].e;
			int ans=0;
			for(int j=i-1;j>=0;j--){
				if(a[i].ti-a[j].tf>=R)ans=max(ans,dp[j]);
			}
			dp[i]+=ans;
			ret=max(ret,dp[i]);
		}
		printf("%d\n",ret);
	}
	return 0;
}
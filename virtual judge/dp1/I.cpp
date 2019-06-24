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
#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
//FIND longest increasing sequence(LIS)
const int maxn=3e5+10;
int a[maxn],N,INF=1<<30,dp[maxn];

int main(){
	while(~scanf("%d",&N)){
		int ret=0,pre=-INF;
		REP(i,0,N){
			scanf("%d",&a[i]);
			dp[i]=1;
		}
		REP(i,0,N){
			REP(j,0,i){
				if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+1);
			}
			ret=max(ret,dp[i]);
		}
		cout<<ret<<'\n';
	}
	return 0;
}
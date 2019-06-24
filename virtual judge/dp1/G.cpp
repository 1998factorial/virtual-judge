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
const int maxn=1e5+5;
int N,dp[maxn][11],INF=1<<30,cnt[maxn][11];
//dp[i][j]=maximal number of pancake I can get at time i and pos j
int main(){
	while(~scanf("%d",&N)&&N){
		int tf=0,ret=0;
		memset(cnt,0,sizeof(cnt));
		REP(i,0,N){
			int x,y;
			scanf("%d %d",&x,&y);
			cnt[y][x]++;
			tf=max(tf,y);
		}
		REP(i,0,11)dp[tf][i]=cnt[tf][i];
		RREP(i,tf-1,0){
			REP(j,0,11){
				dp[i][j]=dp[i+1][j];
				if(j>0)dp[i][j]=max(dp[i+1][j-1],dp[i][j]);
				if(j<10)dp[i][j]=max(dp[i+1][j+1],dp[i][j]);
				dp[i][j]+=cnt[i][j];
			}
		}	
		printf("%d\n",dp[0][5]);//在5号格开始，逆向搜索
	}
	return 0;
}
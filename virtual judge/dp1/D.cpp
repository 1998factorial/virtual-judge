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
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
//state compression dp
const int maxn=16;
struct course{
	string name;
	int D,C;
}a[maxn];
int N,dp[1<<maxn][maxn][3],ret;//[0]=>cost,[1]=>last day,[2]=>pre course
bool seen[1<<maxn][maxn];

void solve(int mask, int pos){
	if(seen[mask][pos])return;
	seen[mask][pos]=true;
	int state=mask^(1<<pos);
	dp[mask][pos][0]=1<<30;
	REP(i,0,N){
		if(state&(1<<i)){
			solve(state,i);//will get dp[state][i][0-2]
			int cc=(dp[state][i][1]+a[pos].C<a[pos].D)?0:dp[state][i][1]+a[pos].C-a[pos].D;
			cc+=dp[state][i][0];
			if(cc<dp[mask][pos][0]){
				dp[mask][pos][0]=cc;
				dp[mask][pos][1]=dp[state][i][1]+a[pos].C;
				dp[mask][pos][2]=i;
			}
		}	
	}
}

int main(){
	int _;cin>>_;
	while(_--){
		cin>>N;ret=1<<30;int best=-1;
		REP(i,0,N)cin>>a[i].name>>a[i].D>>a[i].C;
		sort(a,a+N,[&](struct course x, struct course y){
			return x.name>y.name;
		});
		memset(dp,0,sizeof(dp));
		memset(seen,false,sizeof(seen));
		REP(i,0,N)
			dp[1<<i][i][0]=(a[i].D>a[i].C)?0:a[i].C-a[i].D,
			dp[1<<i][i][1]=a[i].C,
			dp[1<<i][i][2]=i,
			seen[1<<i][i]=true;
		REP(i,0,N)
			solve((1<<N)-1,i);//(state,i)
		REP(i,0,N){
			if(ret>dp[(1<<N)-1][i][0])ret=dp[(1<<N)-1][i][0],best=i;
		}
		cout<<ret<<endl;
		int ss=(1<<N)-1;vector<string> ans;
		while(dp[ss][best][2]!=best){
			ans.push_back(a[best].name);
			int tmp=best;
			best=dp[ss][best][2],ss^=(1<<tmp);
		}
		ans.push_back(a[best].name);
		reverse(ans.begin(),ans.end());
		for(string xx: ans)cout<<xx<<'\n';
	}
	return 0;
}

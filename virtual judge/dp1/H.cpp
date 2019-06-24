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

int S[2005],D[2005],dp[2005],N;
int main(){
	int _;cin>>_;
	while(_--){
		cin>>N;
		REP(i,1,N+1)cin>>S[i];
		REP(i,2,N+1)cin>>D[i];
		dp[0]=0;dp[1]=S[1];
		REP(i,2,N+1){
			dp[i]=min(S[i]+dp[i-1],D[i]+dp[i-2]);
		}
		int hr=dp[N]/3600,mi=(dp[N]%3600)/60,sec=(dp[N]%60);
		printf("%02d:%02d:%02d %s\n",(8+hr)%24,mi,sec,(8+hr)%24>12?"pm":"am");
	}
	return 0;
}
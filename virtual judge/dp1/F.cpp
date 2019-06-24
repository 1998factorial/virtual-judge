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
const int maxn=505;
int E,F,N,C[maxn][2],dp[10005],INF=1<<28;
//knap sack dp
int main(){
	int _;cin>>_;
	while(_--){
		cin>>E>>F;
		cin>>N;
		REP(i,0,N)cin>>C[i][0]>>C[i][1];
		int w=F-E;//coin weights
		dp[0]=0;
		REP(i,1,w+1){
			int mn=INF;
			REP(j,0,N){
				if(i>=C[j][1]&&mn>C[j][0]+dp[i-C[j][1]])mn=dp[i-C[j][1]]+C[j][0];
			}
			dp[i]=mn;
		}
		int ret=INF;
		ret=min(ret,dp[w]);
		if(ret!=INF)printf("The minimum amount of money in the piggy-bank is %d.\n",ret);
		else printf("This is impossible.\n");
	}
	return 0;
}
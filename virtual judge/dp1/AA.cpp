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
const int maxn=130;
int dp[maxn][maxn],N;
//dp[i][j]= # ways to split number i into several numbers where the maximal is j 
/*
way 1
int main(){
	while(~scanf("%d",&N)){
		memset(dp,0,sizeof(dp));
		int ret=0;
		REP(i,1,N+1)dp[i][i]=1;
		REP(i,1,N+1){
			REP(j,1,i){
				dp[i][j]=0;
				for(int k=1;k<=j&&k<=i-j;k++)
					dp[i][j]+=dp[i-j][k];
			}
		}
		REP(i,1,N+1)ret+=dp[N][i];
		cout<<ret<<'\n';
	}	
	return 0;
}*/

int main(){
	//dp[i][j]=# ways to write i=x1+x2+...+xn where xk is at most j
	//order x1<=x2<=...<=xn,xn is j or less than j => dp[i-j][j]+dp[i][j-1]
	memset(dp,0,sizeof(dp));
	REP(i,0,121)dp[i][0]=0,dp[i][1]=1,dp[0][i]=1,dp[1][i]=1;
	REP(i,2,121)
		REP(j,2,121){
			if(j>i)dp[i][j]=dp[i][i];
			else dp[i][j]=dp[i][j-1]+dp[i-j][j];
		}
	while(~scanf("%d",&N)){
		printf("%d\n",dp[N][N]);
	}
	return 0;
}

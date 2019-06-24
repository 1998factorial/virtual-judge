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

int n,k,a[105][105],dp[105][105];
//dp[i][j]=maximal score if starting from (i,j)

int solve(int i,int j){
	if(i<0||i>=n||j<0||j>=n)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=a[i][j];
	int ret=0;
	for(int ii=1;ii<=k;ii++){
		if(ii+i<n&&a[i][j]<a[i+ii][j])ret=max(ret,solve(ii+i,j));
		if(i-ii>=0&&a[i][j]<a[i-ii][j])ret=max(ret,solve(i-ii,j));
	}
	for(int jj=1;jj<=k;jj++){
		if(j+jj<n&&a[i][j]<a[i][j+jj])ret=max(ret,solve(i,j+jj));
		if(j-jj>=0&&a[i][j]<a[i][j-jj])ret=max(ret,solve(i,j-jj));
	}
	dp[i][j]+=ret;
	return dp[i][j];
}

int main(){
	while(~scanf("%d %d",&n,&k)&&!(n==-1&&k==-1)){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		memset(dp,-1,sizeof(dp));
		dp[0][0]=solve(0,0);
		printf("%d\n",dp[0][0]);
	}
	return 0;
}
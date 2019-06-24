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
const int maxn=1e4+5;
string A,B;
int dp[maxn][maxn];
//dp[i][j]=lengh of longest common seq of A[..i],B[..j]
int n,m;
int solve(int i,int j){
	if(i<0||j<0)return 0;
	if(dp[i][j]>-1)return dp[i][j];
	if(A[i]==B[j])dp[i][j]=1+solve(i-1,j-1);
	else dp[i][j]=max(solve(i-1,j),solve(i,j-1));
	return dp[i][j];
}

int main(){
	while(cin>>A>>B){
		n=A.size();m=B.size();
		REP(i,0,n)
			REP(j,0,m)
				dp[i][j]=-1;
		dp[n-1][m-1]=solve(n-1,m-1);
		printf("%d\n",dp[n-1][m-1]);
	}
	return 0;
}	
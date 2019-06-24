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

int a[2005],n,dp[2005][2005];

int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)dp[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int i=0;i+len-1<n;i++){
			int j=i+len-1;
			dp[i][j]=max(dp[i+1][j]+a[i]*(n-len+1),dp[i][j-1]+a[j]*(n-len+1));
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}
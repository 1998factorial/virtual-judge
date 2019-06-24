#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <complex>
using namespace std;
//区间 dp
const int N = 1000001;
int m,n;
int a[N];
int dp[N],Max[N];
int INF = (1 << 30);
//dp[i][j] = "maximal sum for dividing first i numbers into j groups"
//dp[i][j] = max{dp[i-1][j]+a[i],max{dp[k][j-1]}+a[i] for k < i}
//dp[i][0] = 0
//Max[i] = max{dp[k][j-1] for k < i}
//dp[i] => improved version of dp[i][j]
int main(){
	while(cin >> m >> n){
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++)cin >> a[i];
		memset(dp,0,sizeof(dp));
		memset(Max,0,sizeof(Max));
		int ret;
		for(int j = 1; j <= m; j++){ //j groups
			ret = -INF;
			for(int i = j; i <= n; i++){ //at least j numbers
				dp[i] = max(dp[i-1],Max[i-1]) + a[i];
				Max[i-1] = ret;
				ret = max(ret,dp[i]);
			}
		}
		cout << ret << endl;
	}
	return 0;
}





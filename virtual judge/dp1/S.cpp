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

int a[2005],b[2005],n;
ll dp[2][2005];
//dp[i][j]=min{dp[i-1][k]+abs(a[i]-a[j])|k<=j}
//find minimal cost to make the sequence a non-decreasing sequence
//we are not introducing new values other than a[0...n-1]
int main(){
	while(~scanf("%d",&n)){
		REP(i,0,n){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b,b+n);
		REP(i,0,n)dp[0][i]=abs(a[0]-b[i]);
		REP(i,1,n){
			ll mm=dp[(i-1)&1][0];
			REP(j,0,n){
				mm=min(mm,dp[(i-1)&1][j]);
				dp[i&1][j]=mm+abs(a[i]-b[j]);
			}
		}
		ll ret=1ll<<60;
		REP(i,0,n)ret=min(ret,dp[(n-1)&1][i]);
		printf("%lld\n",ret);
	}
	return 0;
}
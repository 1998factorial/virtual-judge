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

int n,a[1005],dp[1005];

int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	int ret=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+1);
		}
		ret=max(ret,dp[i]);
	}
	printf("%d\n",ret);
	return 0;
}
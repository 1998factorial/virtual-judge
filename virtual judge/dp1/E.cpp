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
const int maxn=1005;
int N,a[maxn],dp[maxn];
//longest increasing sequence dp
int main(){
	while(~scanf("%d",&N)&&N){
		int ret=0;
		REP(i,0,N){
			scanf("%d",&a[i]);
			dp[i]=a[i];
			int mx=0;
			REP(j,0,i){
				if(a[i]>a[j])mx=max(mx,dp[j]);
			}
			dp[i]+=mx;
			ret=max(ret,dp[i]);
		}printf("%d\n",ret);
	}
	return 0;
}
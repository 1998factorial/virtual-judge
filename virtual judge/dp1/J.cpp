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
//sort by weight then find LIS
struct mice{
	int w,v;
}a[1005];
int dp[1005],pre[1005];
int main(){
	int N=1,ret=-1,ss=-1;
	vector<int> mp;
	while(~scanf("%d %d",&a[N].w,&a[N].v))mp.push_back(N++);
	sort(mp.begin(),mp.end(),[&](int x,int y){
		return a[x].w<a[y].w;
	});
	REP(i,1,N)dp[i]=1,pre[i]=-1;
	REP(i,0,N-1){
		int x=mp[i],best=-1;
		REP(j,0,i){
			int y=mp[j];
			if(a[x].w>a[y].w&&a[x].v<a[y].v&&dp[i]<dp[j]+1)dp[i]=dp[j]+1,pre[i]=j;
		}
		if(dp[i]>ret)ret=dp[i],ss=i;
	}
	printf("%d\n",ret);
	vector<int> ans;
	while(ss!=-1)ans.push_back(mp[ss]),ss=pre[ss];
	reverse(ans.begin(),ans.end());
	for(int xx:ans)printf("%d\n",xx);
	return 0;	
}
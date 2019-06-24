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
#define REP(i,a,b) for(int i=a;i<b;++i)
#define PB push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod=2520;
ll dp[20][2520][50];
int len,d[20],mp[3000];
int GCD(int a,int b){return a==0?b:GCD(b%a,a);}
int LCM(int a,int b){return a/GCD(a,b)*b;}

ll DFS(int pos,int sum,int lcm,int flag){
	if(pos<0)return sum%lcm==0;
	if(!flag&&dp[pos][sum][mp[lcm]]!=-1)return dp[pos][sum][mp[lcm]];
	int limit=flag?d[pos]:9;
	ll ret=0ll;
	REP(i,0,limit+1){
		ll nlcm=lcm;
		if(i)nlcm=LCM(lcm,i);
		ret+=DFS(pos-1,(sum*10+i)%mod,nlcm,flag&&i==limit);
	}
	if(!flag)dp[pos][sum][mp[lcm]]=ret;
	return ret;
}

ll solve(ll n){
	len=0;
	while(n){
		d[len++]=n%10;
		n/=10;
	}
	return DFS(len-1,0,1,1);
}

int main(){
	int _;cin>>_;
	int cnt=0;
	REP(i,1,2521)
		if(mod%i==0)mp[i]=cnt++;
	memset(dp,-1ll,sizeof(dp));
	while(_--){
		ll r,l;
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}
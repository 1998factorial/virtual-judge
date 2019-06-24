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
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

ll dp[20][1<<10][10]; //20*1024*11 -> 10^5
//dp[i][state][j]=# of length i with state and longest seq being lenght j
int d[20],len,k;
int cnt[1<<10],nt[1<<10][10];

ll DFS(int pos,int state,int zero,int flag){
  if(pos<0)return cnt[state]==k;
  if(!flag&&dp[pos][state][k]>-1)return dp[pos][state][k];
  int up=flag?d[pos]:9;
  ll ret=0ll;
  for(int i=0;i<=up;++i){
    ret+=DFS(pos-1,zero&&(!i)?state:nt[state][i],zero&&(!i),flag&&(i==up));
  }
  if(!flag)dp[pos][state][k]=ret;
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

int mp(int state,int i){//每次添数的时候要尽量找小的
  for(int j=i;j<10;++j){
    if(state&(1<<j))
      return (state^(1<<j))|(1<<i);
  }
  return state|(1<<i);
}

int main(){
	int _;cin>>_;
	memset(dp,-1ll,sizeof(dp));
  for(int s=0;s<(1<<10);++s){
    cnt[s]=0;
    for(int i=0;i<10;++i){
      if(s&(1<<i))cnt[s]++;
      nt[s][i]=mp(s,i);
    }
  }
	for(int tn=1;tn<=_;++tn){
		ll l,r;
		cin>>l>>r>>k;
		printf("Case #%d: %lld\n",tn,solve(r)-solve(l-1));
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
int d[20],len;
ll dp[20][2];
//dp[i]=# of seq which do not have 49

ll dfs(int pos,int four,int flag){
  if(pos<0)return 1;
  if(!flag&&dp[pos][four]>-1)return dp[pos][four];
  int up=flag?d[pos]:9;
  ll ret=0ll;
  for(int i=0;i<=up;++i){
    if(i==9&&four)continue;
    ret+=dfs(pos-1,i==4,flag&&(i==up));
  }
  if(!flag)dp[pos][four]=ret;
  return ret;
}

ll solve(ll n){
  len=0;
  while(n){
    d[len++]=n%10;
    n/=10;
  }
  return dfs(len-1,0,1);
}

int main(){
  int _;cin>>_;
  memset(dp,-1,sizeof(dp));
  while(_--){
    cin>>N;
    cout<<N-solve(N)+1<<endl;
  }
}
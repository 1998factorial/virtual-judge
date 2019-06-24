#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[36][36][36],l,r;
int d[36],len;
//dp[i][j] # of good numbers up to ith digit st it has j '0's

ll dfs(int pos,int n0,int n1,int zero,int flag){
  if(pos<1)return n0>=n1;
  if(!flag&&!zero&&dp[pos][n0][n1]>-1)return dp[pos][n0][n1];
  int up=flag?d[pos]:1;
  ll ret=0;
  for(int i=0;i<=up;++i){
    ret+=dfs(pos-1,zero&&i==0?0:n0+(i==0),zero&&i==0?0:n1+(i==1),zero&&i==0,flag&&i==up);
  }
  if(!flag&&!zero)dp[pos][n0][n1]=ret;
  return ret;
}

ll solve(ll n){
  len=1;
  for(;n;n>>=1)d[len++]=n&1;
  return dfs(len-1,0,0,1,1);
}

int main(){
  memset(dp,-1,sizeof(dp));
  while(cin>>l>>r)cout<<solve(r)-solve(l-1)<<endl;
}